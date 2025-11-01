#include <iostream>
#include "clsLoginScreen.h"
#include "clsRegisterLogins.h"

int main()
{

    //clsMainScreen::ShowMainMenue();
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
            break; 
    }
    

    system("pause>0");
    return  0;

}


