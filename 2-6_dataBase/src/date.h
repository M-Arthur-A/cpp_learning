#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

class Date {
public:
	Date(int year, int month, int day);
	int GetYear()const;
	int GetMonth()const;
	int GetDay()const;
private:
	const int Year;
	const int Month;
	const int Day;
};

string to_str(const Date& date);

ostream& operator << (ostream& os, const Date& d);
bool operator < (const Date & l, const Date& r);
bool operator > (const Date & l, const Date& r);
bool operator == (const Date & l, const Date& r);
bool operator <= (const Date & l, const Date& r);
bool operator >= (const Date & l, const Date& r);
Date ParseDate(istream& is);
