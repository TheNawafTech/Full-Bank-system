#include<iostream>
#include"clsBankClient.h";
#include"ClsInputValidate.h";
#include<iomanip>
#include"clsMainScreenOf_OOP11.h";
#include"clsUser.h";
#include"clsLoginUsersScreen.h";
#include"ClsDates.h";
#include"clsScreen.h"
#include<fstream>
#include"ClsUtil.h";

using namespace std;


int main()
{

	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}

	cout << endl;
	return 0;
}