#include <stdio.h>
#include <math.h>
#include "value.hpp"

/**
 * Prompts a text and then returns a number entered by the user
 * The min value is 0, and the max is a parameter
 * 
 * @param text  string that will be showed in the prompt
 * @param max   max value the user can enter
 * @return if no issue whatsoever, the int from the user is returned
 */
int askValue(std::string text,int max)
{
    int x;
    do{
        if(std::cin.fail())
        {
            std::cin.clear();                        //If failed : clear the fail flag
            std::cin.ignore(10000,'\n');             //Ignore 10000 caracters until \n
            std::cout << "Not a number !" << std::endl;
        }
        std::cout << text << ": ";
        std::cin >> x;
    }while(x < 0 || std::cin.fail() || x > max);
    return x;
}

/**
 * Prompts a text and then returns a number entered by the user
 * the min value is 0, and the max value is the maximum value for an int (depending on your processor)
 * 
 * @param text  string that will be showed in the prompt
 * @return if no issue whatsover, the int from the user is returned
 */
int askValue(std::string text)
{
    return askValue(text,pow(2,(sizeof(int)*CHAR_BIT)-1)-1);
}

/**
 * Calls the function askValue, it asks for 3 different values
 * @param abc asks for multiple int pointers
 * @return returns these pointers with the value from askValue
 */
void askValues(int* a,int* b,int* c)
{
    *a = askValue("Hours");
    *b = askValue("Minutes",59);
    *c = askValue("Seconds",59);
}

/**
 * Shows the numbers entered by the user then ask if they are correct
 * If no, it will recall the function askValues, and itself
 * 
 * @param abc asks for multiple int pointers
 */
void choice(int* a,int* b,int* c)
{
    char prompt;
    std::cout << "You chose "<< *a << "h" << *b << "m" << *c << "s" << std::endl << "Are you sure? [y for yes, n for no]" << std::endl;
    std::cin >> prompt;
    if(prompt != 'y')
    {
        switch(prompt)
        {
            case 'n':
                askValues(a,b,c);
                choice(a,b,c);
                break;
            default :
                std::cout << "[Error] : '" << prompt << "' is not an option" << std::endl;  
                choice(a,b,c);
                break;
        }
    }
}