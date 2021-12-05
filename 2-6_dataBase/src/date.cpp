#include "date.h"

Date::Date(int year, int month, int day)
	: Year(year),
	Month(month),
	Day(day) {
};
int Date::GetYear()const {
	return Year;
}
int Date::GetMonth()const {
	return Month;
}
int Date::GetDay()const {
	return Day;
}

string to_str(const Date& date) {
	ostringstream result;
	result << setfill('0') << fixed;
	result << setw(4) << date.GetYear() << '-' << setw(2) << date.GetMonth() << '-' << setw(2)
		<< date.GetDay();
	return result.str();
}

ostream& operator << (ostream& os, const Date& d) {
	os << setfill('0') << setw(4) << d.GetYear() << "-" << setfill('0') << setw(2) << d.GetMonth() << "-" << setfill('0') << setw(2) << d.GetDay();
	return os;
};

bool operator < (const Date & l, const Date& r) {
	if (l.GetYear() != r.GetYear())
		return l.GetYear() < r.GetYear();
	else if (l.GetMonth() != r.GetMonth()) 
		return l.GetMonth() < r.GetMonth();
	else
		return l.GetDay() < r.GetDay();
}
bool operator > (const Date & l, const Date& r) {
	if (l.GetYear() != r.GetYear())
		return l.GetYear() > r.GetYear();
	else if (l.GetMonth() != r.GetMonth())
		return l.GetMonth() > r.GetMonth();
	else
		return l.GetDay() > r.GetDay();
}

bool operator == (const Date&l, const Date&r) {
	return(l.GetYear() == r.GetYear() && l.GetMonth() == r.GetMonth() && l.GetDay() == r.GetDay());
}
bool operator <= (const Date & l, const Date& r) {
	if (l < r || l == r)
		return true;
	else
		return false;
}
bool operator >= (const Date & l, const Date& r) {
	if (l > r || l == r)
		return true;
	else
		return false;
}

Date ParseDate(istream& is) {
	int y, m, d;
	is >> y;
	is.ignore(1);
	is >> m;
	is.ignore(1);
	is >> d;
	return(Date(y, m, d));
}