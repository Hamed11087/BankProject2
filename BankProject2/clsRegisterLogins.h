#pragma once
#include<iostream>
#include "clsDate.h" 
#include "Global.h"
#include "clsString.h"
#include "clsUser.h"
#include "clsScreen.h"
#include <fstream>

using namespace std; 

class clsRegisterLogins : clsScreen
{
private:

	static void _PrintRegiterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
		cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;

	}




public:

	static void ShowRegiterList()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pRegisterLogin))
		{
			return;
		}

		vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetRegisterLogInList();

		string Title = "\t  Login Register List Screen";
		string SubTitle = "\t    (" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLoginRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo Logins Available In the System!";
		else

			for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
			{
				_PrintRegiterRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
	}


};