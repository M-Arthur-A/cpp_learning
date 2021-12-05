#include "database.h"
#include "date.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <set>

void Database::Add(const Date &date, const string &event) {
	if (database_check[date].count(event) == 0) {
		database[date].push_back(event);
		database_check[date].insert(event);
	}
}

string Database::Last(const Date& date) const {
	string result;
	auto last_date = database.upper_bound(date);

	if (last_date != end(database)) {
		if (date < last_date->first) {
			if (last_date == begin(database)) return "No entries";
			else last_date = prev(last_date);
		}
	}
	else {
		if (last_date == begin(database)) return "No entries";
		last_date = prev(last_date);
	}

	result = to_str(last_date->first) + " " + *(prev(last_date->second.end()));
	return result;
}

void Database::Print(ostream& os) const {
	string date;
	os << setfill('0') << fixed;

	for (const auto &i : database) {

		for (const auto &j : i.second) {

			os << setw(4) << i.first.GetYear() << '-' << setw(2) << i.first.GetMonth() << '-' << setw(2)
				<< i.first.GetDay() << " " << j << endl;
		}

	}
}
