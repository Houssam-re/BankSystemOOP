#include <iostream>
#include "clsBankClients.h"
#include "clsUtil.h"
#include"clsMainMenu.h"
#include "clsBankUsers.h"
#include "clsLoginScreen.h"
using namespace std;

int main()
{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
            break;
    }
}

