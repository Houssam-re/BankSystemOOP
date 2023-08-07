#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsClientsListScreen.h"
#include "clsTransactionMenueScreen.h"
#include "clsMainManageUsersScreen.h"
#include "clsAddNewClients.h"
#include "clsDeleteClients.h"
#include "clsUpdateClients.h"
#include "clsFindClients.h"
#include "clsLoginRegistreScreen.h"
#include "clsGlobale.h"
using namespace std;

class clsMainMenu : protected clsScreen
{

private:
    enum enMainMenueOptions
    {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eShowLoginRegistred = 8,eExit = 9
    };

   static short _ReadMainMenueOption()
   {
       int Choice; cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 9]? ";
       Choice = clsInputValidate::ReadShortNumberBetween(1, 9, "Enter Number Between 1 and 9 : ");
       return Choice;
   }

   static void _ShowAllClientsScreen()
   {
       clsClientsListScreen::ShowAllClientsScreen();
   }

   static void _GoBackToMainMenue()
   {
       cout << "\n\nPress any key to go back to Main Menue...";
       system("pause>0");
       ShowMainMenue();
   }

   static void _ShowAddNewClientsScreen()
   {
       clsAddNewClients::AddNewClients();
   }

   static void _ShowDeleteClientScreen()
   {
       clsDeleteClients::DeleteClient();

   }  

   static void _ShowUpdateClientScreen()
   {
       clsUpdateClients::UpdateClient();
   }   

   static void _ShowFindClientScreen()
   {
       clsFindClients::FindClient();
   }   

   static void _ShowTransactionsMenue()
   {
       clsTransactionMenueScreen::ShowTransactionMainMenue();
   }

   static void _ShowManageUsersMenue()
    {
       clsMainManageUsersScreen::ShowManageUsersMenue();
    }
      static void _ShowRegistredLogin()
    {
          clsLoginRegistreScreen::ShowRegisterScreen();
    }

    static void _Logout()
    {
        CurrentUser = clsBankUsers::Find("", "");
    }
 
   static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eShowLoginRegistred:
            system("cls");
            _ShowRegistredLogin();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;
        }

    }

public :
   static void ShowMainMenue()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Menu Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n"; 
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }
};

