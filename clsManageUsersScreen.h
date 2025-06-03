#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsBankClient.h";
#include"ClsInputValidate.h";
#include"clsUsersListScreen.h";
#include"clsFindClientScreen.h";
#include"clsDeleteClientScreen.h";
#include"clsUpdateClientScreen.h";
#include"clsAddNewUserScreen.h";
#include"clsMainScreenOf_OOP11.h";
#include"clsUsersListScreen.h";
#include"clsDeleteUserScreen.h";
#include"clsUpdateUserScreen.h";
#include"clsDeleteUserScreen.h";
#include"clsFindUserScreen.h";

class clsManageUsersScreen :protected clsScreen
{

private:
	enum enManageUsers { eListUsers = 1, eAddNewUsers = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenue = 6 };

	struct StUser
	{
		string Username;
		string Password;
		bool MarkForDelete = false;
		int Permission = 0;

		//Betwise;
	};


	enum enMainMenuePermissions
	{
		eAll = -1, eClientsList = 1, eAddNewClient = 2, eDeleteClient = 4,
		eUpdateClient = 8, eFindClient = 16, eTransactions = 32, eMangeUsers = 64
	};


	static void ShowAccessDenied()
	{
		cout << "- - - - - - - - - - - - - - - - - - - - -\n";
		cout << "Access Denied,\n";
		cout << "You Don't Have Permission To Do This,\n";
		cout << "Please Conact Your Admin\n";
		cout << "- - - - - - - - - - - - - - - - - - - - -\n";
	}

	static StUser CurrentUser;

	static void GoBackToManageUsers()
	{
		cout << "\nPress any key to go back to Manage Users...\n";
		system("pause>0");

		ShowManageUsersScreen();
	}

	static void _ShowUsersListScreen()
	{
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUsersScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static short _ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

public:

	static void PerfromMangeUsers()
	{
		short ManageUsersOption = _ReadManageUsersMenueOption();

		switch (ManageUsersOption)
		{
		case enManageUsers::eListUsers:
			system("cls");
			_ShowUsersListScreen();
			GoBackToManageUsers();
			break;

		case enManageUsers::eAddNewUsers:
			system("cls");
			_ShowAddNewUsersScreen();
			GoBackToManageUsers();
			break;

		case enManageUsers::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			GoBackToManageUsers();
			break;

		case enManageUsers::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			GoBackToManageUsers();
			break;

		case enManageUsers::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			GoBackToManageUsers();
			break;

		case enManageUsers::eMainMenue:
			break;
		}

	}

	static void ShowManageUsersScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;// this will exit the function and it will not continue
		}
		system("cls");
		_DrawScreenHeader("\tManage Users Menue Menue");

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

		PerfromMangeUsers();
	}


};

