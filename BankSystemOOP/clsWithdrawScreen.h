#pragma once
#include "clsTransactionMenueScreen.h"
#include "clsInputValidation.h"
#include "clsBankClients.h"
#include <iostream>

using namespace std;
class clsWithdrawScreen : public clsScreen
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
    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t\tWithDraw Screen");


        string AccountNumber;
        AccountNumber = clsInputValidate::ReadStrings("Enter The AccountNumber  : ");
        while (!clsBankClients::isUserExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = clsInputValidate::ReadStrings("Enter The AccountNumber  : ");
        }
        clsBankClients Client = clsBankClients::Find(AccountNumber);

        _PrintClient(Client);
        double Amount = 0;
        printf("\nPlease enter WithDraw amount ? ");
        Amount = clsInputValidate::ReadDblNumberBetween(0,Client.AccountBalance,"The Amount You Enter More Than You Have In Your Account ,,,\n\nPlease enter WithDraw amount ? ");
        char Answer;
        cout << "Are You Sure You Want tO WithDraw ?? ,,,";
        cin >> Answer;
        if (towlower(Answer) == 'y')
        {
            Client.WithDraw(Amount);
            printf("WithDraw Was Done Successful,,,,\n\n");
            printf("New Balance is : %f", Client.AccountBalance);
        }
        else
        {
            cout << "Operation Cancelled,,,,";
            return;
        }


    }
};

