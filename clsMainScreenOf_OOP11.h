#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"ClsInputValidate.h";
#include"clsClientListScreen.h";
#include"clsAddNewClientScreen.h";
#include"clsDeleteClientScreen.h";
#include"clsUpdateClientScreen.h";
#include"clsFindClientScreen.h";
#include"clsTransactionClientScreen.h";
#include"clsManageUsersScreen.h";
#include"GlobalScreenOfOOP11.h";
#include"clsLoginRegisterUsersScreen.h";
#include"clsCurrencyExchangeScreen.h";

using namespace std;


class clsMainScreen :protected clsScreen
{
private:

    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsClientMenue = 6,
        eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::AddNewClient(); 
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::DeleteClient();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClient();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersScreen();
    }

    static void _showLoginRegister()
    {
        clsLoginRegisterScreen::ShowLoginRegister();
    }

    static void _ShowCurrencyExchange()
    {
        clsCurrencyExchange::ShowCurrencyExchangeMainScreen();
    }

    static void _Logout()
    {
      CurrentUser = CurrentUser.Find("", "");
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

        case enMainMenueOptions::eShowTransactionsClientMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _showLoginRegister();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchange();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;
        }

    };

  public:   

    static void ShowMainMenue()
      {

          system("cls");
          _DrawScreenHeader("\t\tMain Screen");

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
          cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
          cout << setw(37) << left << "" << "\t[10] Logout.\n";
          cout << setw(37) << left << "" << "===========================================\n";

          _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    };

};
