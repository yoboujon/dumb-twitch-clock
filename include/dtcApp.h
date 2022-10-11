#pragma once
#include <AppCore/AppCore.h>
#include <JavaScriptCore/JavaScript.h>
#include <iostream>
#include <string>
#include "../include/clock.hpp"

std::string getStringArg(const ultralight::JSArgs& arg, int term);
void write2File(std::string file,std::string text);

using namespace ultralight;

class dtcApp : public AppListener, public WindowListener, public LoadListener, public ViewListener
{
  public:
    dtcApp();
    virtual ~dtcApp();
    virtual void Run();
    virtual void ChangeURL(String url);
    virtual void OnUpdate() override;
    virtual void OnClose(ultralight::Window* window) override;
    virtual void OnFinishLoading(ultralight::View* caller, uint64_t frame_id, bool is_main_frame, const String& url) override;
    virtual void OnDOMReady(ultralight::View* caller, uint64_t frame_id, bool is_main_frame, const String& url) override;
    virtual void OnChangeCursor(ultralight::View* caller, Cursor cursor) override;
    virtual void OnChangeTitle(ultralight::View* caller, const String& title) override;
    virtual void OnChangeURL(ultralight::View* caller,const String& title) override;
    JSValue onButtonClick(const JSObject& thisObject, const JSArgs& args);
    void getName(const JSObject& thisObject, const JSArgs& args);
    void getTimeValue(const JSObject& thisObject, const JSArgs& args);

  protected:
    RefPtr<App> app_;
    RefPtr<Window> window_;
    RefPtr<Overlay> overlay_;

  private:
    Clock m_clock;
    bool m_clockStart;
    int wait_;
    std::time_t m_now;
    std::string m_file;
    ultralight::View* m_caller;
};
