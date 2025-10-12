#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>


class clsFindClientScreen :protected clsScreen
{

private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

public:

	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}

		_DrawScreenHeader("\t Find Client Screen");

		string AccountNumber; 

		cout << "\Please Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
			if (AccountNumber == "-90" || AccountNumber =="skip")
				break;
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient was not Found :-(\n";
		}
		_PrintClient(Client);

	}

};

