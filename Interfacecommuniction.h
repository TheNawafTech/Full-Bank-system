#pragma once
#include<string>
#include<iostream>

using namespace std;

class Interfacecommuniction
{
public:

	virtual void SendEmail(string Title, string Body) = 0;
	virtual void SendFax(string Title, string Body) = 0;
	virtual void SendSMS(string Title, string Body) = 0;


};

