#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidation.h"
#include "clsDepositScreeen.h"
#include "clsWithdrawScreen.h"
#include "clsTotaleBalanceScreen.h"
#include "clsTransformationScreen.h"
#include "clsTransferListScreen.h"
#include "clsMainMenu.h"
using namespace std;

class clsTransactionMenueScreen : protected clsScreen
{

private:
    enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eTransformation = 4,eTransferList,eShowMainMenue = 6 };

    static short ReadTransactionsMenueOption()
    {
        int Choice; cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number Between 1 and 6 : ");
        return Choice;
    }

   static void GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionMainMenue();

    }

   static void ShowDepositScreen()
   {
       clsDepositScreeen::ShowDepositScreen();
   }  
   
   static void ShowWithDrawScreen()
   {
       clsWithdrawScreen::ShowWithdrawScreen();
   }   

   static void ShowTotalBalancesScreen()
   {
       clsTotaleBalanceScreen::ShowBalancesScreen();
   }  
   static void ShowTransformationScreen()
   {
       clsTransformationScreen::ShowTransferScreen();
   }
      
   static void ShowTransferListScreen()
   {
       clsTransferListScreen::ShowTransferRegisterScreen();
   }


   static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
    {
        switch (TransactionMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            ShowDepositScreen();
            GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            ShowWithDrawScreen();
            GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            ShowTotalBalancesScreen();
            GoBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eTransformation:
        {
            system("cls");
            ShowTransformationScreen();
            GoBackToTransactionsMenue();
            break;
        }  
        case enTransactionsMenueOptions::eTransferList:
        {
            system("cls");
            ShowTransferListScreen();
            GoBackToTransactionsMenue();
            break;
        }    
        case enTransactionsMenueOptions::eShowMainMenue:
        {
            

        }

        }

    }

public:
    static void ShowTransactionMainMenue()
    {
        if (!CheckAccessRights(clsBankUsers::enPermissions::pTranactions))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfare.\n"; 
        cout << setw(37) << left << "" << "\t[5] Transfer History List.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }
};

