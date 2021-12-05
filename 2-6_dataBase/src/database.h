#pragma once

#include "date.h"
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

class Database {
public:
	void Add(const Date& date, const string& event);

	template <class T>
	int RemoveIf(T func);

	template <class T>
	vector<string> FindIf(T func) const;

	string Last(const Date& date) const;

	void Print(ostream& os) const;
private:
	map<Date, vector<string>> database;
	map<Date, set<string>> database_check;
};

template <class T>
vector<string> Database::FindIf(T func) const {
	vector<string> result;
	for (const auto &i : database) {
		for (const auto& j : i.second) {
			if (func(i.first, j)) {
				result.push_back(to_str(i.first) + " " + j);
			}
		}
	}
	return result;
}

template <class T>
int Database::RemoveIf(T func) {
	int count = 0;
	vector<Date> dates;

	for (auto i = begin(database); i != end(database); i++) {
		auto it = stable_partition(i->second.begin(), i->second.end(), [func, i](string s) {
			return !func(i->first, s);
		});
		count += i->second.end() - it;
		database_check[i->first].clear();
		database_check[i->first].insert(i->second.begin(), it);
		i->second.erase(it, i->second.end());
		if (begin(i->second) == end(i->second)) dates.push_back(i->first);
	}

	for (const auto& i : dates) {
		database.erase(i);
		database_check.erase(i);
	}
	return count;
}
