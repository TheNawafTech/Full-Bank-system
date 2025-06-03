#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreenOf_OOP11.h";
#include "GlobalScreenOfOOP11.h";

using namespace std;

class clsLoginScreen :protected clsScreen
{
private:

    static bool _Login()
    {
        bool LoginFaild = false;
        short FailedLoginTimes = 0;

        string Username, Password;
        do
        {
            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n";
                FailedLoginTimes++;
                cout << "You have " << 3 - FailedLoginTimes << " Trials to login.\n\n";
            }
            if (FailedLoginTimes == 3)
            {
                cout << "You are locked after 3 faild trails.\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.LogInRegister();

        clsMainScreen::ShowMainMenue();
        return true;
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};