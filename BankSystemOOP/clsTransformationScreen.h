#pragma once
#include "clsTransactionMenueScreen.h"
#include "clsInputValidation.h"
#include "clsBankClients.h"
#include <iostream>

class clsTransformationScreen : protected clsScreen
{
    static void _PrintClient(clsBankClients Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }
    static string _ReadAccountNumber(string message)
    {
       string AccountNumber = clsInputValidate::ReadStrings(message);
        while (!clsBankClients::isUserExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = clsInputValidate::ReadStrings("Enter The AccountNumber  : ");
        }
        return AccountNumber;
    }
    static float ReadAmount(clsBankClients SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }
   
public:
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t\tTransfer Screen");


        string TransFromAccountNumber = _ReadAccountNumber("Please Enter The AccountNumber to Transfer From : ");
        clsBankClients TransFromClient = clsBankClients::Find(TransFromAccountNumber);
        _PrintClient(TransFromClient);

        string TransToAccountNumber = _ReadAccountNumber("Please Enter The AccountNumber to Transfer To : ");
        clsBankClients TransToClient = clsBankClients::Find(TransToAccountNumber);
        _PrintClient(TransToClient);
       
   

        double Amount = 0;
        Amount = ReadAmount(TransFromClient);
        char Answer;
        cout << "Are You Sure You Want tO Transfer ?? ,,,";
        cin >> Answer;
        if (towlower(Answer) == 'y')
        {
            if (TransFromClient.Transfer(Amount, TransToClient,CurrentUser.UserName))
            {
                 printf("Transfer Was Done Successful,,,,\n\n");
                _PrintClient(TransFromClient);
                _PrintClient(TransToClient);
            }
            else
                printf("Transfer Was Faild,,,,\n\n");
        }
        else
        {
            cout << "Operation Cancelled,,,,";
            return;
        }


    }
};

