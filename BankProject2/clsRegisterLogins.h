#pragma once
#include<iostream>
#include "clsDate.h" 
#include "Global.h"
#include "clsString.h"
#include "clsUser.h"
#include "clsScreen.h"
#include <fstream>

using namespace std; 

class clsRegisterLogins 
{

	//static clsRegisterLogins _ConvertLineToRegisterLogins(string Line, string Seperator = "#//#")
	//{
	//	vector<string> vRegisterLogins; 
	//	vRegisterLogins = clsString::Split(Line, Seperator);

	//	
	//}

	static string _ConverRegisterLoginsToLine(clsUser User , string Sperator = "#//#")
	{
		string RegisterRecord = "";
		RegisterRecord += clsDate::DateToString(clsDate()) + " - " + clsDate::GetSystemTime() +  Sperator;
		RegisterRecord += CurrentUser.UserName + Sperator;
		RegisterRecord += CurrentUser.Password + Sperator;
		RegisterRecord += to_string(CurrentUser.Permissions); 
		
		return RegisterRecord; 
	}

public:
	static void _SaveUsersRegisterLoginsToFile(clsUser vUserRegister)
	{
		fstream MyFile; 
		MyFile.open("LoginRegister.txt", ios::out | ios::app); 

		string DateLine; 

		if (MyFile.is_open())
		{
			
			
			DateLine = _ConverRegisterLoginsToLine(vUserRegister);
			MyFile << DateLine << endl; 
		}

		MyFile.close();
	}


};