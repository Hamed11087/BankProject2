#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h" 
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "Please Enter Account Number to Transfer From: "; 
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;

	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount; 
		cout << "\nEnter Transfer Amount? "; 

		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadFloatNumber();
		}

		return Amount; 
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t Transfer Screen "); 
		
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber()); 

		_PrintClientCard(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClientCard(DestinationClient);

		float Amount = ReadAmount(SourceClient);


		cout << "Are you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer; 

		if (Answer == 'y' || Answer == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Faild \n"; 
			}
		}


		_PrintClientCard(SourceClient);
		_PrintClientCard(DestinationClient);
		
		
	}

};