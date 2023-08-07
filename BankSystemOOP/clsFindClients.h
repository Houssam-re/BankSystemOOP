#include <iostream>
#include "clsBankClients.h"
#include "clsUtil.h"
using namespace std;

class clsFindClients : clsScreen
{

	static void _PrintClient(clsBankClients Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.PhoneNumber;
		cout << "\nAcc. Number : " << Client.AccountNumber;
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

public:

	static void FindClient()
	{
		if (!CheckAccessRights(clsBankUsers::enPermissions::pFindClient))
		{
			return;
		}
		_DrawScreenHeader("\t Find Client Screen");

		string AccountNumber;
		AccountNumber = clsInputValidate::ReadStrings("Enter The AccountNumber  : ");
		while (!clsBankClients::isUserExist(AccountNumber))
		{
			cout << "Invalid AccountNumber,, Try Another one ,, : ";
			AccountNumber = clsInputValidate::ReadStrings("Enter The AccountNumber  : ");
		}
		clsBankClients Client = clsBankClients::Find(AccountNumber);
		cout << "\n\nClient Found :) \n";
		_PrintClient(Client);

		

	}
};

