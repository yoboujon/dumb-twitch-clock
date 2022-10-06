#include "main.hpp"

int main()
{
    int h,m,s;
    char choice;
    askValues(&h,&m,&s);
    while(choice != 'y')
    {
        std::cout << "You choose "<< h << "h" << m << "m" << s << "s" << std::endl << "Are you sure? [y for yes, n for no]" << std::endl;
        std::cin >> choice;
        switch(choice)
        {
            case 'n':
                askValues(&h,&m,&s);
                break;
            default :
                break;
        }
    }
    return 0;
}