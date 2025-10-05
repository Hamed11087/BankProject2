#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include"clsMainScreen.h"
#include "Global.h"


class clsLoginScreen :protected clsScreen
{
private:

	static void _Login()
	{
		bool LoginFaild = false; 

		string UserName, Password;
		do
		{
			if (LoginFaild)
			{
				cout << "\n\t\t\t\t\t\tInvlaid Username/Password!\n\n";
			}

			cout << "\t\t\t\t\t\t  Enter Username? ";
			cin >> UserName; 

			cout << "\t\t\t\t\t\t  Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		clsMainScreen::ShowMainMenue();
	}

public:

	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		_Login();
	}

};