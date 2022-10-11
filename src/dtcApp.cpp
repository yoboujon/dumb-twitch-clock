#include "../include/dtcApp.h"
#include <chrono>
#include <thread>
#include <ctime>

#define WINDOW_WIDTH  620
#define WINDOW_HEIGHT 340

dtcApp::dtcApp(): m_clock("dtc.txt") {
  m_clockStart = 0;
  m_now = time(NULL);
  m_file="dtc.txt";
  wait_=0;

  app_ = App::Create();
  window_ = Window::Create(app_->main_monitor(), WINDOW_WIDTH, WINDOW_HEIGHT,
    false, kWindowFlags_Titled);
  overlay_ = Overlay::Create(window_, 1, 1, 0, 0);
  overlay_->Resize(window_->width(), window_->height());
  overlay_->view()->LoadURL("file:///index.html");
  /// Activate OnUpdate()
  app_->set_listener(this);
  /// Activate OnClose()
  window_->set_listener(this);
  /// Activate OnFinishLoading() et OnDOMReady()
  overlay_->view()->set_load_listener(this);
  /// Activate OnChangeCursor() et OnChangeTitle()
  overlay_->view()->set_view_listener(this);
}

dtcApp::~dtcApp() {
}

/**
 * Starts the Run loop
*/
void dtcApp::Run() {
  app_->Run();
}

/**
 * Called constently (sortof while(1))
*/
void dtcApp::OnUpdate() {
  std::time_t nowPlusOne;
  if(m_clockStart && !m_clock.hasClockEnded())
  {
    time(&nowPlusOne);
    if(nowPlusOne > m_now)
    {
      write2File(m_file,m_clock.printClock());
      m_clock.modifySeconds(-1);
      m_now = time(NULL);
      if(wait_ >= 2)
      {
        m_caller->EvaluateScript("onClickSecond(-1)");
        m_caller->EvaluateScript("checkTimeValues()");
      }
      wait_++;
    }
  }
}

/**
 * Called function when the app is closing
*/
void dtcApp::OnClose(ultralight::Window* window) {
  app_->Quit();
}

/**
 * Called function when the app finished loading the page
*/
void dtcApp::OnFinishLoading(ultralight::View* caller, uint64_t frame_id, bool is_main_frame, const String& url)
{

}

/**
 * Called function when all the JS,CSS,HTML elements from the document are completly loaded
*/
void dtcApp::OnDOMReady(ultralight::View* caller, uint64_t frame_id, bool is_main_frame, const String& url) {
  RefPtr<JSContext> context = caller->LockJSContext();
  SetJSContext(context->ctx());
  JSObject global = JSGlobalObject();
  global["onButtonClick"] = BindJSCallbackWithRetval(&dtcApp::onButtonClick);
  global["getName"] = BindJSCallback(&dtcApp::getName);
  global["getTimeValue"] = BindJSCallback(&dtcApp::getTimeValue);
  std::cout << "ondomready : " << caller << std::endl;
  m_caller = caller;
}

/**
 * While the cursor is moving, changing state, this fonction is called
*/
void dtcApp::OnChangeCursor(ultralight::View* caller, Cursor cursor) {
  window_->SetCursor(cursor);
}

/**
 * While changing Title, this fonction is called
*/
void dtcApp::OnChangeTitle(ultralight::View* caller, const String& title) {
  window_->SetTitle(title.utf8().data());
}

/**
 * While changing URL, this fonction is called
*/
void dtcApp::OnChangeURL(ultralight::View* caller,const String& title)
{}

/**
 * Change the URL of the app
*/
void dtcApp::ChangeURL(String url)
{
  overlay_->view()->LoadURL("url");
}

/**
 * Linked JS Function, when called, this C++ function can resend with different arguments
 * this JS function.
 * @param thisObject a JSObject, refers to the function itself
 * @param args JSArgs, the arguments of the function called
 * @return the value inside the function
*/
JSValue dtcApp::onButtonClick(const JSObject& thisObject, const JSArgs& args) {
  std::cout << "Bouton clique !" << std::endl;
  return JSValue("");
}

/**
 * Linked JS Function, when called, this C++ function can read the arguments.
 * Really useful if we want to read JS Variables.
 * @param thisObject a JSObject, refers to the function itself
 * @param args JSArgs, the arguments of the function called
*/
void dtcApp::getName(const JSObject& thisObject, const JSArgs& args) {
  for(int i=0; i<args.size() ; i++)
  {
    if(args[i].IsString())
    {
      std::cout << "String :" << getStringArg(args,i) << std::endl;
    }
    if(args[i].IsNumber())
    {
      double toto = args[i].ToNumber();
      std::cout << "Nombre :" << toto << std::endl;
    }
  }
}

/**
 * Linked JS getTimerValue(h,m,s) Function. Grab the hour, minutes and seconds of the clock.
 * It will then create a clock object.
 * 
 * @param thisObject a JSObject, refers to the function itself
 * @param args JSArgs, the arguments of the function called
*/
void dtcApp::getTimeValue(const JSObject& thisObject, const JSArgs& args)
{
  double h = args[0].ToNumber();
  double m = args[1].ToNumber();
  double s = args[2].ToNumber();
  m_clock.setClockTime(int(h),int(m),int(s));
  m_clockStart=1;
}

///FONCTIONS - THEY ARE NOT LINKED WITH THE OBJECT dtcApp

/**
 * This function converts the strings of a JSString inside an argument into an std::string.
 * @param arg The argument of the JSFunction
 * @param term int, as arg is an array, select the value you want to get
 * @return the string of the argument from the JS Function
*/
std::string getStringArg(const ultralight::JSArgs& arg,int term)
{
  JSString str = arg[term].ToString();
  char arg_str[128];
  JSStringGetUTF8CString(str, arg_str, 128);
  return arg_str;
}

void write2File(std::string file,std::string text)
{
    std::ofstream fout(file);
    fout << text;
    fout.close();
}