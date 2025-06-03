#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include"ClsInputValidate.h"; 
#include<iomanip>
#include"ClsUtil.h";
#include"GlobalScreenOfOOP11.h";

using namespace std;

class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 3 };
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDelete = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = ClsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

    static vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C._MarkedForDelete == false)
                DataLine = _ConverClientObjectToLine(C);
                MyFile << DataLine << endl;

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    string _PreaperTransferRecord(clsBankClient& Client, double Amount, string Spreator = "#//#")
    {
        string Str = "";

        Str += ClsDates::GetSystemDateTimeString() + Spreator;
        Str += AccountNumber() + Spreator;
        Str += Client.AccountNumber() + Spreator;
        Str += to_string(Amount) + Spreator;
        Str += to_string(GetAccountBalance()) + Spreator;
        Str += to_string(Client.GetAccountBalance()) + Spreator;
        Str += CurrentUser.UserName;

        return Str;
    }

    void _LoadsTransfersInFile(double Amount, clsBankClient Client2)
    {
        fstream MyFile;

        string Line = _PreaperTransferRecord(Client2, Amount);

        MyFile.open("LoginTransfer.text", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << Line << endl;

            MyFile.close();
        }
    }

public:
 

    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string GetFullName()
    {
        return FirstName + " " + LastName;
    }

    // [1] Find client :
    static clsBankClient Find(string AccountNumber)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in | ios::app);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in | ios::app);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    // [2] Update client : 

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 3 };

    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadNumber<float>();
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }


    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {

                return enSaveResults::svFaildEmptyObject;

            }

        }

        case enMode::UpdateMode:
        {

            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }


    //[3] Add new client : 

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }


    //[4] Delete Client : 

    bool Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;

    }
   
    static void DeleteClient()
    {
        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        Client1.Print();

        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                Client1.Print();
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }


    // [5] Client List : The left..
    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }


    // [6] Total balances : 

    static float GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {

            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;

    }

    //__________________

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }
  
    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }

    }

    bool Transfer(double Amount, clsBankClient& Client)
    {
        if (!Withdraw(Amount))
        {
            return false;
        }

        Client.Deposit(Amount);

        _LoadsTransfersInFile(Amount, Client);

        return true;
    }

    void ClientCard(clsBankClient Client)
    {
        cout << "\nClient Card:\n";
        cout << "______________________\n";
        cout << "Full Name   : " << Client.GetFullName() << endl;
        cout << "Acc. Number : " << Client._AccountNumber << endl;
        cout << "Balance     : " << Client.AccountBalance << endl;
        cout << "______________________\n";

    }

    struct StTransferInfo
    {
        string DateAndTime, sAccount, dAccount, Amount, sBalance, dBalance, User;
    };


    static StTransferInfo ConvertTransferLogLineToRecord(string Line)
    {
        StTransferInfo TransferInfo;

        vector<string>VRecord = ClsString::Split(Line, "#//#");

        TransferInfo.DateAndTime = VRecord[0];
        TransferInfo.sAccount = VRecord[1];
        TransferInfo.dAccount = VRecord[2];
        TransferInfo.Amount = VRecord[3];
        TransferInfo.sBalance = VRecord[4];
        TransferInfo.dBalance = VRecord[5];
        TransferInfo.User = VRecord[6];

        return TransferInfo;
    }


    static vector<StTransferInfo>_PrepareRecords()
    {
        fstream MyFile;
        string Line = "";
        StTransferInfo TransferRecord;
        vector<StTransferInfo>VTransferRecord;

        MyFile.open("LoginTransfer.text", ios::in);

        if (MyFile.is_open())
        {
            while (getline(MyFile, Line))
            {
                TransferRecord = ConvertTransferLogLineToRecord(Line);

                VTransferRecord.push_back(TransferRecord);
            }

            MyFile.close();

        }

        return VTransferRecord;
    }

    static vector<StTransferInfo>LoadRecordsFromFile()
    {
        vector<StTransferInfo>VRecord;

        VRecord = _PrepareRecords();

        return VRecord;

    }


   
};
