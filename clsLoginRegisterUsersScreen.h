#pragma once

#include<iostream>
#include"clsScreen.h";
#include<fstream>
#include<vector>
#include"ClsString.h"
#include<iomanip>
#include "clsUser.h"
#include<string>

class clsLoginRegisterScreen : protected clsScreen
{
private:

    struct StrRegister
    {
        string eDate, eUser, Password; int Permissions = 0;
    };


    static StrRegister ConvertRegisterLineToRecrd(string Line)
    {
        vector<string>VRecord;
        StrRegister StRegister;

        VRecord = ClsString::Split(Line, "#//#");

        StRegister.eDate = VRecord[0];
        StRegister.eUser = VRecord[1];
        StRegister.Password = VRecord[2];
        StRegister.Permissions = stoi(VRecord[3]);

        return StRegister;
    }


    static vector<StrRegister> LoadDataRegisterFromFile()
    {
        string LineRecord = "";

        fstream MyFile;
        vector<StrRegister>VStrRecord;


        MyFile.open("LoginRegister.text", ios::in | ios::app);

        if (MyFile.is_open())
        {
            StrRegister StrLegister;

            while (getline(MyFile, LineRecord))
            {
                StrLegister = ConvertRegisterLineToRecrd(LineRecord);
                VStrRecord.push_back(StrLegister);
            }
        }
        return VStrRecord;
    }


    static void PrintRegisters(StrRegister& Regsiter)
    {
        cout << "| " << left << setw(20) << Regsiter.eDate;
        cout << "| " << left << setw(15) << Regsiter.eUser;
        cout << "| " << left << setw(12) << Regsiter.Password;
        cout << "| " << left << setw(10) << Regsiter.Permissions;
        cout << endl;
    }


public:
	static void ShowLoginRegister()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;// this will exit the function and it will not continue
        }

        static vector<StrRegister>VRecord = LoadDataRegisterFromFile();


        string Title = "\tLogin Regoster Screen";
        string SubTitle = "\t(" + to_string(VRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        fstream MyFile;
        MyFile.open("LoginRegister.text", ios::in | ios::app);

        HeaderOfScreenRegister();

        for ( StrRegister &Register : VRecord)
        {
            PrintRegisters(Register);
        }

	}



	



};