#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include"clsFindUserScreen.h"
#include "clsInputValidation.h"
#include "clsDepositScreeen.h"
#include "clsWithdrawScreen.h"
#include "clsTotaleBalanceScreen.h"
#include "clsShowListUsersScreen.h"
#include"clsDeleteUserScreen.h"
#include "clsAddNewUsers.h"
#include "clsUpdateUser.h"
#include "clsMainMenu.h"
using namespace std;
class clsMainManageUsersScreen :protected clsScreen
{
    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short _ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }


  static void GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowManageUsersMenue();
          
    }
static void ShowListUsersScreen()
{
    clsShowListUsersScreen::ShowUsersList();
}

static void ShowAddNewUserScreen()
{
    clsAddNewUsers::AddNewUser();
}

static void ShowDeleteUserScreen()
{
    clsDeleteUserScreen::DeleteUser();
}   

static void ShowUpdateUserScreen()
{
    clsUpdateUser::UpdateUserInfo();
} 

static void ShowFindUserScreen()
{
    clsFindUserScreen::FindUser();
}

static void _PerfromManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
{
    switch (ManageUsersMenueOption)
    {
    case enManageUsersMenueOptions::eListUsers:
    {
        system("cls");
        ShowListUsersScreen();
        GoBackToManageUsersMenue();
        break;
    }

    case enManageUsersMenueOptions::eAddNewUser:
    {
        system("cls");
        ShowAddNewUserScreen();
        GoBackToManageUsersMenue();
        break;
    }

    case enManageUsersMenueOptions::eDeleteUser:
    {
        system("cls");
        ShowDeleteUserScreen();
        GoBackToManageUsersMenue();
        break;
    }

    case enManageUsersMenueOptions::eUpdateUser:
    {
        system("cls");
        ShowUpdateUserScreen();
        GoBackToManageUsersMenue();
        break;
    }

    case enManageUsersMenueOptions::eFindUser:
    {
        system("cls");

        ShowFindUserScreen();
        GoBackToManageUsersMenue();
        break;
    }

    case enManageUsersMenueOptions::eMainMenue:
    {
          
    }
    }

}


public:
    static void ShowManageUsersMenue()
    {
        if (!CheckAccessRights(clsBankUsers::enPermissions::pManageUsers))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _PerfromManageUsersMenueOption((enManageUsersMenueOptions)_ReadManageUsersMenueOption());
    }

};

