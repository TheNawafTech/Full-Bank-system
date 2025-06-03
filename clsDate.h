#pragma once
#pragma warning (disable:4996)

#include<iostream>
#include<vector>
#include<string>
#include"ClsString.h";
using namespace std;

class ClsDates
{
private:

	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

	vector<string>SpltingStrings(string Str, string Delemiter = "#//#")
	{
		short Pos = 0;
		string Sword;
		vector<string>VReord;

		while ((Pos = Str.find(Delemiter)) != std::string::npos)
		{
			Sword = Str.substr(0, Pos);
			if (Sword != "")
			{
				VReord.push_back(Sword);
			}
			Str.erase(0, Pos + Delemiter.length());
		}

		if (Str != "")
		{
			VReord.push_back(Str);
		}
		return VReord;
	}

public:

	static ClsDates GetSystemDate()
	{
		ClsDates Date;
		time_t t = time(0);
		tm* now = localtime(&t);

		Date._Year = now->tm_year + 1900;
		Date._Month = now->tm_mon + 1;
		Date._Day = now->tm_wday;

		return Date;
	}

	static string GetSystemDateTimeString()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		short Year, Month, Day, Hour, Min, Sec;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_wday;
		Hour = now->tm_hour;
		Min = now->tm_min;
		Sec = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - " + to_string(Hour) + ":" + to_string(Min) + ":" + to_string(Sec));
	}

	ClsDates()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_wday;
	}

	string GetHour()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		return to_string(now->tm_hour);

	}

	string GetMin()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		return to_string(now->tm_min);
	}

	string GetSec()
	{

		time_t t = time(0);
		tm* now = localtime(&t);

		return to_string(now->tm_sec);
	}

	ClsDates(string Date)
	{
		vector<string>VDates = SpltingStrings(Date, "/");

		_Day = stoi(VDates[0]);
		_Month = stoi(VDates[1]);
		_Year = stoi(VDates[2]);
	}

	ClsDates(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	ClsDates(short TotalDays, short Year)
	{
		ClsDates Datee = GetDateFromDayOrderInYear(TotalDays, Year);
	}

	static string DateToString(ClsDates Date)
	{
		return  to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	void Print()
	{
		cout << _Day << "/" << _Month << "/" << _Year << endl;
	}

	static bool isLeapYear(short Year)
	{
		//If year accept divied 400 
		//OR year accept divide 4 and NOT accept divied 100
		//Then it's a leap year..

		return  ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
	}
	bool isLeapYear()
	{
		return isLeapYear(_Year);
	}

	static short NumberOfDaysInAYear(short Year)
	{
		return  isLeapYear(Year) ? 365 : 364;
	}

	short NumberOfDaysInAYear()
	{
		return NumberOfDaysInAYear(_Year);
	}

	static short NumberOfHoursInAYear(short Year)
	{
		return  NumberOfDaysInAYear(Year) * 24;
	}

	short NumberOfHoursInAYear()
	{
		return NumberOfHoursInAYear(_Year);
	}

	static int NumberOfMinutesInAYear(short Year)
	{
		return  NumberOfHoursInAYear(Year) * 60;
	}

	int NumberOfMinutesInAYear()
	{
		return NumberOfMinutesInAYear(_Year);
	}

	static int NumberOfSecondsInAYear(short Year)
	{
		return  NumberOfMinutesInAYear(Year) * 60;
	}

	int NumberOfSecondsInAYear()
	{
		return NumberOfSecondsInAYear(_Year);
	}

	static short NumberOfHoursInAMonth(short Month, short Year)
	{
		return  NumberOfDaysInAMonth(Month, Year) * 24;
	}

	short NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(_Month, _Year);
	}

	static int NumberOfMinutesInAMonth(short Month, short Year)
	{
		return  NumberOfHoursInAMonth(Month, Year) * 60;
	}

	int NumberOfMinutesInAMonth()
	{
		return NumberOfMinutesInAMonth(_Month, _Year);
	}

	static int NumberOfSecondsInAMonth(short Month, short Year)
	{
		return  NumberOfMinutesInAMonth(Month, Year) * 60;
	}

	int NumberOfSecondsInAMonth()
	{
		return NumberOfSecondsInAMonth(_Month, _Year);
	}

	static string DayShortName(short Day, short Month, short Year)
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[DayOfWeekOrder(Day, Month, Year)];
	}

	string DayShortName()
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[DayOfWeekOrder(_Day, _Month, _Year)];
	}

	static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}

		TotalDays += Day;

		return TotalDays;
	}

	short DaysFromTheBeginingOfTheYear()
	{
		short TotalDays = 0;

		for (int i = 1; i <= _Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, _Year);
		}

		TotalDays += _Day;

		return TotalDays;
	}

	static  short DayOfWeekOrder(short Year, short Month, short Day)
	{
		int A, Y, M;

		A = (14 - Month) / 12;
		Y = Year - A;
		M = Month + (12 * A) - 2;

		return (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
	}

	static short NumberOfDaysInMonth(short Year, short Month)
	{
		short ArrMonths[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		if (Month < 1 || Month > 12)
			return 0;

		return (Month == 2) ? isLeapYear(Year) ? 29 : 28 : ArrMonths[Month];
	}

	static short TotalDaysFromTheBegingOfTheYear(short Year, short Month, short Day)
	{
		short TotalDays = 0;

		for (short i = 1; i < Month; i++)
		{
			TotalDays += NumberOfDaysInMonth(Year, i);
		}

		TotalDays += Day;

		return TotalDays;
	}

	short GetYear()
	{
		return _Year;
	}

	short GetMonth()
	{
		return _Month;
	}

	short GetDay()
	{
		return _Day;
	}

	static ClsDates GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{

		ClsDates Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		short Month = 1;
		short year = Year;
		short Day = 0;

		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Year, Month);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Month++;
			}
			else
			{
				Day = RemainingDays;
				break;
			}

		}

		return Date;
	}

	ClsDates GetDateFromDayOrderInYear(short DateOrderInYear)
	{
		return GetDateFromDayOrderInYear(DateOrderInYear, _Year);
	}

	static ClsDates GetDateOfYearAfterAddingDays(ClsDates Date, short Days)
	{
		short MonthsDays = 0;

		short RemainingDays = Days + TotalDaysFromTheBegingOfTheYear(Date._Year, Date._Month, Date._Day);

		Date._Month = 1;

		while (true)
		{
			MonthsDays = NumberOfDaysInMonth(Date._Year, Date._Month);

			if (RemainingDays > MonthsDays)
			{
				RemainingDays -= MonthsDays;
				Date._Month++;

				if (Date._Month > 12)
				{
					Date._Year++;
					Date._Month = 1;
				}
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	ClsDates GetDateOfYearAfterAddingDays(short Days)
	{
		return GetDateOfYearAfterAddingDays(*this, Days);
	}

	static bool IsDate1BeforeDate2(ClsDates Date1, ClsDates Date2)
	{
		return (Date1._Year < Date2._Year) ? true : (Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : Date1._Month == Date2._Month ? (Date1._Day < Date2._Day) : false) : false;
	}

	bool IsDate1BeforeDate2(ClsDates Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(ClsDates Date1, ClsDates Date2)
	{
		return (Date1._Year == Date2._Year) ? Date1._Month == Date2._Month ? (Date1._Day == Date2._Day) : false : false;
	}

	bool IsDate1EqualDate2(ClsDates Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	enum ReturndDate { Before = -1, Equal = 0, After = 1 };

	static ReturndDate CompareDates(ClsDates Date1, ClsDates Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return ReturndDate::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return ReturndDate::Equal;


		return ReturndDate::After;
	}

	ReturndDate CompareDates(ClsDates Date2)
	{
		return CompareDates(*this, Date2);
	}

	static string MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan", "Feb", "Mar",
						   "Apr", "May", "Jun",
						   "Jul", "Aug", "Sep",
						   "Oct", "Nov", "Dec"
		};

		return (Months[MonthNumber - 1]);
	}

	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	static void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays;

		// Index of the day from 0 to 6
		int current = DayOfWeekOrder(Year, Month, 1);

		NumberOfDays = NumberOfDaysInMonth(Year, Month);

		// Print the current month name
		printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());

		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);


			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");

	}

	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Month, _Year);
	}

	void PrintYearCalendar(int Year)
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", Year);
		printf("  _________________________________\n");


		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}

		return;
	}

	void PrintYearCalendar()
	{
		PrintYearCalendar(_Year);
	}

	static bool IsValidDate(ClsDates Date)
	{

		if (Date._Day < 1 || Date._Day>31)
			return false;

		if (Date._Month < 1 || Date._Month >12)
			return false;

		if (Date._Month == 2)
		{
			if (isLeapYear(Date._Year))
			{
				if (Date._Day > 29)
					return false;
			}
			else
			{
				if (Date._Month > 28)
					return false;
			}
		}
		short DaysInMonth = NumberOfDaysInMonth(Date._Year, Date._Month);

		if (Date._Day > DaysInMonth)
			return false;

		return true;

	}

	bool IsValid()
	{
		return IsValidDate(*this);
	}

	bool IsTheLastDayInTheMonth(ClsDates Date)
	{
		return Date._Day == NumberOfDaysInMonth(Date._Year, Date._Month);
	}

	bool IsTheLastDayInTheMonth()
	{
		return IsTheLastDayInTheMonth(*this);
	}

	bool IsTheLastMonthInTheYear(short Month)
	{
		return (Month == 12);
	}

	bool IsTheLastMonthInTheYear()
	{
		return IsTheLastMonthInTheYear(_Month);
	}

	ClsDates IncreaseOneDayToTheYear(ClsDates Date)
	{
		if (IsTheLastDayInTheMonth(Date))
		{
			if (IsTheLastMonthInTheYear(Date._Month))
			{
				Date._Month = 1;
				Date._Day = 1;
				Date._Year;
			}
			else
			{
				Date._Month++;
				Date._Day = 1;
			}
		}
		else
		{
			Date._Day++;
		}

		return Date;
	}

	ClsDates IncreaseOneDayToTheYear()
	{
		return IncreaseOneDayToTheYear(*this);
	}

	static void SwapDates(ClsDates& Date1, ClsDates& Date2)
	{

		ClsDates TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;

	}

	void SwapDates(ClsDates Date2)
	{
		SwapDates(*this, Date2);
	}

	static short NumberOfDaysInAMonth(short Month, short Year)
	{

		if (Month < 1 || Month>12)
			return  0;

		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];

	}

	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Month, _Year);
	}

	static bool IsLastDayInMonth(ClsDates Date)
	{

		return (Date._Day == NumberOfDaysInAMonth(Date._Month, Date._Year));

	}

	bool IsLastDayInMonth()
	{

		return IsLastDayInMonth(*this);

	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static ClsDates AddOneDay(ClsDates Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Month = 1;
				Date._Day = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}

		return Date;
	}

	ClsDates AddOneDay()
	{
		return AddOneDay(*this);
	}

	void AddDays(short Days)
	{


		short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
		short MonthDays = 0;

		_Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(_Month, _Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				_Month++;

				if (_Month > 12)
				{
					_Month = 1;
					_Year++;

				}
			}
			else
			{
				_Day = RemainingDays;
				break;
			}

		}


	}

	static int GetDifferenceInDays(ClsDates Date1, ClsDates Date2, bool IncludeEndDay = false)
	{
		//this will take care of negative diff
		int Days = 0;
		short SawpFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			//Swap Dates 
			SwapDates(Date1, Date2);
			SawpFlagValue = -1;

		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = AddOneDay(Date1);
		}

		return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
	}

	int GetDifferenceInDays(ClsDates Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	static short CalculateMyAgeInDays(ClsDates DateOfBirth)
	{
		return GetDifferenceInDays(DateOfBirth, ClsDates::GetSystemDate(), true);
	}

	short CalculateMyAgeInDays()
	{
		return CalculateMyAgeInDays(*this);
	}

	static ClsDates IncreaseDateByOneWeek(ClsDates& Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = AddOneDay(Date);
		}

		return Date;
	}

	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}

	static ClsDates IncreaseDateByXWeeks(short Weeks, ClsDates& Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void IncreaseDateByXWeeks(short Weeks)
	{
		IncreaseDateByXWeeks(Weeks, *this);
	}

	static ClsDates IncreaseDateByOneMonth(ClsDates& Date)
	{

		if (Date._Month == 12)
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
		{
			Date._Month++;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
		// be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	void IncreaseDateByOneMonth()
	{
		IncreaseDateByOneMonth(*this);
	}

	static ClsDates IncreaseDateByXDays(short Days, ClsDates& Date)
	{

		for (short i = 1; i <= Days; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByXDays(short Days)
	{
		IncreaseDateByXDays(Days, *this);
	}

	static ClsDates IncreaseDateByXMonths(short Months, ClsDates& Date)
	{

		for (short i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void IncreaseDateByXMonths(short Month)
	{
		IncreaseDateByXMonths(Month, *this);
	}

	static ClsDates IncreaseDateByOneYear(ClsDates& Date)
	{
		Date._Year++;
		return Date;
	}

	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	static 	ClsDates IncreaseDateByXYears(short Years, ClsDates& Date)
	{
		Date._Year += Years;
		return Date;

	}

	void IncreaseDateByXYears(short Years)
	{
		IncreaseDateByXYears(Years);
	}

	ClsDates IncreaseDateByOneDecade(ClsDates& Date)
	{
		//Period of 10 years
		Date._Year += 10;
		return Date;
	}

	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}

	ClsDates IncreaseDateByXDecades(short Decade, ClsDates& Date)
	{
		Date._Year += Decade * 10;
		return Date;
	}

	void IncreaseDateByXDecades(short Decade)
	{
		IncreaseDateByXDecades(Decade, *this);
	}

	ClsDates IncreaseDateByOneCentury(ClsDates& Date)
	{
		//Period of 100 years
		Date._Year += 100;
		return Date;
	}

	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}

	ClsDates IncreaseDateByOneMillennium(ClsDates& Date)
	{
		//Period of 1000 years
		Date._Year += 1000;
		return Date;
	}

	ClsDates IncreaseDateByOneMillennium()
	{
		IncreaseDateByOneMillennium(*this);
	}

	static ClsDates DecreaseDateByOneDay(ClsDates Date)
	{
		if (Date._Day == 1)
		{
			if (Date._Month == 1)
			{
				Date._Month = 12;
				Date._Day = 31;
				Date._Year--;
			}
			else
			{

				Date._Month--;
				Date._Day = NumberOfDaysInAMonth(Date._Month, Date._Year);
			}
		}
		else
		{
			Date._Day--;
		}

		return Date;
	}

	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}

	static ClsDates DecreaseDateByOneWeek(ClsDates& Date)
	{

		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}

	static ClsDates DecreaseDateByXWeeks(short Weeks, ClsDates& Date)
	{

		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void DecreaseDateByXWeeks(short Weeks)
	{
		DecreaseDateByXWeeks(Weeks, *this);
	}

	static ClsDates DecreaseDateByOneMonth(ClsDates& Date)
	{

		if (Date._Month == 1)
		{
			Date._Month = 12;
			Date._Year--;
		}
		else
			Date._Month--;


		//last check day in date should not exceed max days in the current month
	   // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
	   // be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}


		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static ClsDates DecreaseDateByXDays(short Days, ClsDates& Date)
	{

		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByXDays(short Days)
	{
		DecreaseDateByXDays(Days, *this);
	}

	static ClsDates DecreaseDateByXMonths(short Months, ClsDates& Date)
	{

		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonths(short Months)
	{
		DecreaseDateByXMonths(Months, *this);
	}

	static ClsDates DecreaseDateByOneYear(ClsDates& Date)
	{

		Date._Year--;
		return Date;
	}

	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	static ClsDates DecreaseDateByXYears(short Years, ClsDates& Date)
	{

		Date._Year -= Years;
		return Date;
	}

	void DecreaseDateByXYears(short Years)
	{
		DecreaseDateByXYears(Years, *this);
	}

	static ClsDates DecreaseDateByOneDecade(ClsDates& Date)
	{
		//Period of 10 years
		Date._Year -= 10;
		return Date;
	}

	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}

	static ClsDates DecreaseDateByXDecades(short Decades, ClsDates& Date)
	{

		Date._Year -= Decades * 10;
		return Date;
	}

	void DecreaseDateByXDecades(short Decades)
	{
		DecreaseDateByXDecades(Decades, *this);
	}

	static ClsDates DecreaseDateByOneCentury(ClsDates& Date)
	{
		//Period of 100 years
		Date._Year -= 100;
		return Date;
	}

	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}

	static ClsDates DecreaseDateByOneMillennium(ClsDates& Date)
	{
		//Period of 1000 years
		Date._Year -= 1000;
		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}

	static short IsEndOfWeek(ClsDates Date)
	{
		return  DayOfWeekOrder(Date._Day, Date._Month, Date._Year) == 6;
	}

	short IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(ClsDates Date)
	{
		//Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
		return  (DayIndex == 5 || DayIndex == 6);
	}

	bool IsWeekEnd()
	{
		return  IsWeekEnd(*this);
	}

	static bool IsBusinessDay(ClsDates Date)
	{
		//Weekends are Sun,Mon,Tue,Wed and Thur

		return !IsWeekEnd(Date);

	}

	bool IsBusinessDay()
	{
		return  IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(ClsDates Date)
	{
		return 6 - DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
	}

	short DaysUntilTheEndOfWeek()
	{
		return  DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(ClsDates Date1)
	{

		ClsDates EndOfMontDate;
		EndOfMontDate._Day = NumberOfDaysInAMonth(Date1._Month, Date1._Year);
		EndOfMontDate._Month = Date1._Month;
		EndOfMontDate._Year = Date1._Year;

		return GetDifferenceInDays(Date1, EndOfMontDate, true);

	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}


	static short DaysUntilTheEndOfYear(ClsDates Date1)
	{

		ClsDates EndOfYearDate;
		EndOfYearDate._Day = 31;
		EndOfYearDate._Month = 12;
		EndOfYearDate._Year = Date1._Year;

		return GetDifferenceInDays(Date1, EndOfYearDate, true);

	}

	short DaysUntilTheEndOfYear()
	{
		return  DaysUntilTheEndOfYear(*this);
	}

	//i added this method to calculate business days between 2 days
	static short CalculateBusinessDays(ClsDates DateFrom, ClsDates DateTo)
	{
		short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}

		return Days;

	}

	short CalculateVacationDays(ClsDates DateFrom, ClsDates DateTo)
	{
		return CalculateBusinessDays(DateFrom, DateTo);
	}

	static ClsDates CalculateVacationReturnDate(ClsDates DateFrom, short VacationDays)
	{
		short WeekEndCounter = 0;

		for (short i = 1; i <= VacationDays; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = AddOneDay(DateFrom);
		}
		//to add weekends 
		for (short i = 1; i <= WeekEndCounter; i++)
			DateFrom = AddOneDay(DateFrom);

		return DateFrom;
	}

	static bool IsDate1AfterDate2(ClsDates Date1, ClsDates Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));

	}

	bool IsDate1AfterDate2(ClsDates Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}


};