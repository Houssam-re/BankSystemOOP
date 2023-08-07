#pragma once

#include <iostream>
#include "clsGlobale.h"
#include "clsBankUsers.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
public:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (!SubTitle.empty())
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        ShowUserNameAndDate();
    }
    static void ShowUserNameAndDate()
    {
        clsDate Date;
        cout << clsUtil::Tabs(3) << "User : " << CurrentUser.UserName << endl;
        cout << clsUtil::Tabs(3) << "Date : " << Date.WritMonthName() <<" "<< Date.WritDayName(Date.CalculeDayNum()) <<" ";
        Date.Print();
        cout << endl << endl;

    }
    static bool CheckAccessRights(clsBankUsers::enPermissions Permission)
    {

        if (!CurrentUser.CheckPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }

};

