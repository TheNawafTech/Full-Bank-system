#pragma once
#include<iostream>
#include"clsUser.h";
#include"GlobalScreenOfOOP11.h";
#include"ClsDates.h";

using namespace std;


class clsScreen
{

protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
       
        cout << "\n\t\t\t\t\tUser : ";
        cout << CurrentUser.GetUserName();

        cout << "\n\t\t\t\t\tDate : ";
        ClsDates::GetSystemDate();
        cout << ClsDates::DateToString(ClsDates()) << "\n\n";
    }


    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
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

    static void HeaderOfScreenRegister()
    {
        cout << setw(8) << left << "" << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(15) << "UserName";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

