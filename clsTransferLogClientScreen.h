#pragma once

#include<iostream>
#include"clsScreen.h";
#include"clsBankClient.h";
#include<string>
#include"ClsString.h";
#include<vector>

class clsTransferLog :protected clsScreen
{

private:

    static void _PrintRecord(clsBankClient::StTransferInfo Record)
    {
        cout << "| " << left << setw(20) << Record.DateAndTime;
        cout << "| " << left << setw(8) << Record.sAccount;
        cout << "| " << left << setw(8) << Record.dAccount;
        cout << "| " << left << setw(14) << Record.Amount;
        cout << "| " << left << setw(14) << Record.sBalance;
        cout << "| " << left << setw(14) << Record.dBalance;
        cout << "| " << left << setw(14) << Record.User;
        cout << setw(8) << left << "" << "\n_______________________________________________________________________";
        cout << "_________________________________________\n" << endl;
    }

public:

    static void ShowTransferLog()
    {
        vector<clsBankClient::StTransferInfo>VRecord;

        VRecord = clsBankClient::LoadRecordsFromFile();

        string Title = "      Transfer Log List Screen";
        string SubTitile = "         (" + to_string(VRecord.size()) + ") " + "Record(s).";

        _DrawScreenHeader(Title, SubTitile);


        cout << setw(8) << left << "" << "\n_______________________________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "| " << left << setw(20) << "Date/Time ";
        cout << "| " << left << setw(8) << "S.Acct ";
        cout << "| " << left << setw(8) << "d.Acct ";
        cout << "| " << left << setw(14) << "Amount ";
        cout << "| " << left << setw(14) << "S.Balance ";
        cout << "| " << left << setw(14) << "d.Balance ";
        cout << "| " << left << setw(14) << "User ";
        cout << setw(8) << left << "" << "\n_______________________________________________________________________";
        cout << "_________________________________________\n" << endl;

        for (clsBankClient::StTransferInfo& Record : VRecord)
        {
            _PrintRecord(Record);
            cout << endl;
        }
    }

};

