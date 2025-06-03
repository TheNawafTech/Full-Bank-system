#pragma once
#include<iostream>
#include"clsScreen.h";
#include"ClsInputValidate.h";
#include"clsMainScreenOf_OOP11.h";
#include"clsDepositClientScreen.h";
#include"clsWithdrawClientScreen.h";
#include"clsTotalBalancesClientScreen.h";
#include"clsWireTransferClientScreen.h";
#include"clsTransferLogClientScreen.h";

class clsTransactionScreen :protected clsScreen
{
	
private:
		enum enMainMenuePermissions
		{
			eAll = -1, eClientsList = 1, eAddNewClient = 2, eDeleteClient = 4,
			eUpdateClient = 8, eFindClient = 16, eTransactions = 32, eMangeUsers = 64
		};
	
		enum enTransactionsMenue
		{
			eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eTransfer = 4, eTransferLog = 5, ShowEndScreen = 6
		};
	
		static short _ReadTransactionsMenueOption()
		{
			cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
			short Choice = clsInputValidate::ReadNumberBetween(1, 6, "Enter Number between 1 to 6? ");
			return Choice;
		}
	
	//Continue from here (The Fourth functions)...
	
		static void _ShowDepositScreen()
		{
			clsDepositScreen::ShowDepositScreen();
		}
	
		static void _ShowWithdrawScreen()
		{
			clsWithdrawScreen::ShowWithdraw();
		}

		static void _ShowTotalBalancesScreen()
		{
			clsTotalBalancesScreen::ShowTotalBalances();
		}

		static void _ShowTransferScreen()
		{
			clsWireTransfer::ShowTransferScreen();
		}

		static void _ShowTransferLogScreen()
		{
			clsTransferLog::ShowTransferLog();
		}

		static void _GoBackToTransactionsMenue()
		{
			cout << "\n\nPress any key to go back to Transactions Menue...";
			system("pause>0");
			ShowTransactionsMenue();

		}


		
public:
	
		static void PerformTransactionsMenueScreen(enTransactionsMenue TransactionsOption)
		{
			//ShowTransactionsMenueScreen();
	
			switch (TransactionsOption)
			{
	
			case enTransactionsMenue::eDeposit:
			{
				system("cls");
				_ShowDepositScreen();
				_GoBackToTransactionsMenue();
				break;
			}
			case enTransactionsMenue::eWithdraw:
			{
				system("cls");
				_ShowWithdrawScreen();
				_GoBackToTransactionsMenue();
				break;
			}
			case enTransactionsMenue::eTotalBalances:
			{	system("cls");
				_ShowTotalBalancesScreen();
				_GoBackToTransactionsMenue();
				break;
			}

			case enTransactionsMenue::eTransfer:
			{
				system("cls");
				_ShowTransferScreen();
				_GoBackToTransactionsMenue();
				break;
			}

			case enTransactionsMenue::eTransferLog:
			{
				system("cls");
				_ShowTransferLogScreen();
				_GoBackToTransactionsMenue();
				break;
			}


			case enTransactionsMenue::ShowEndScreen:
			{
				break;
			}
	
			}
	
		}
		
		static void ShowTransactionsMenue()
		{
			if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
			{
				return;// this will exit the function and it will not continue
			}

			system("cls");

			_DrawScreenHeader("\tTransactions Screen");
					
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t[1] Deposit.\n";
			cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
			cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
			cout << setw(37) << left << "" << "\t[4] Transfer.\n";
			cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
			cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
			cout << setw(37) << left << "" << "===========================================\n";
			PerformTransactionsMenueScreen((enTransactionsMenue)_ReadTransactionsMenueOption());
		}
	
		
		
	
};
