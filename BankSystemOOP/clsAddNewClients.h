#include <iostream>
#include "clsBankClients.h"
#include "clsUtil.h"
using namespace std;

class clsAddNewClients :protected clsScreen
{
	static void ReadClientInfo(clsBankClients& Client)
	{

		Client.PinCode = clsInputValidate::ReadStrings("Enter PinCode  : ");
		Client.FirstName = clsInputValidate::ReadStrings("Enter FirstName  : ");
		Client.LastName = clsInputValidate::ReadStrings("Enter LastName  : ");
		Client.PhoneNumber = clsInputValidate::ReadStrings("Enter PhoneNumber  : ");
		Client.Email = clsInputValidate::ReadStrings("Enter Email  : ");
		Client.AccountBalance = clsInputValidate::ReadDblNumber("Enter AccountBalance  : ");

	}

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

public :
	static void AddNewClients()
	{
		if (!CheckAccessRights(clsBankUsers::enPermissions::pAddNewClient))
		{
			return;
		}
		_DrawScreenHeader("\t Add New Client Screen");
	
		string AccountNumber;
		cout << "Enter The AccountNumber  : ";
		cin >> AccountNumber;
		while (clsBankClients::isUserExist(AccountNumber))
		{
			cout << "Exist Client AccountNumber ,,, Try Another one ,, : ";
			AccountNumber = clsInputValidate::ReadStrings("Enter The AccountNumber  : ");
		}
		clsBankClients Client = clsBankClients::GetAddNewClient(AccountNumber);

		ReadClientInfo(Client);

		clsBankClients::enSave SaveResult = Client.Save();
		switch (SaveResult)
		{
		case clsBankClients::enSaveDone:
			cout << "Account Added Successfully\n\n";
			break;
		case clsBankClients::enSaveFaild:
			cout << "there is problem\n";
			break;
		}
	}

};

