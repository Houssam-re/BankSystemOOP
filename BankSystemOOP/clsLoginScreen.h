#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include "clsBankUsers.h"
#include "clsGlobale.h"
#include "clsMainMenu.h"
using namespace std;
class clsLoginScreen : protected clsScreen
{
 
	static bool _Login()
	{
		string username, password;
		bool LoginFailed = false;
		short FaildLogin = 0;
		do
		{
			
			if (LoginFailed)
			{
				FaildLogin++;
				
				cout << "InValid Username/Password,,Try Again\n";
				cout << "You Have " << 3 - FaildLogin << " Trials To Login ,,\n\n";
			}
			if (FaildLogin == 3)
			{
				cout << "You Are Locked because Try More Than 3,,,\n\n";
				return false;
			}
			username = clsInputValidate::ReadStrings("Enter Username : ");
			password = clsInputValidate::ReadStrings("Enter Password : ");
			CurrentUser = clsBankUsers::Find(username, password);
			LoginFailed = CurrentUser.isEmptyMode();
		}while (LoginFailed);
		CurrentUser.RegistreLogin();
		clsMainMenu::ShowMainMenue();
	}
public:


	static bool ShowLoginScreen()
	{
		system("cls");

		_DrawScreenHeader("\t   Login Screen");
		return _Login();

	}
};

