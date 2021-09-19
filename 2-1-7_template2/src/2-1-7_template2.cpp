#include <iostream>
#include <string>
#include <map>
#include <utility>
using namespace std;

template<typename T>
T& get_ref_string(map<int, T>& m, int i) {
	bool key_exist{false};
	for (auto& pair : m) {
		if (pair.first == i) {key_exist = true;}
	}
	if (key_exist) { return m[i]; } else {throw runtime_error("There is no key under this index!");}
}

int main() {
	map<int, string> m = {{0, "value"}};
	string& item = get_ref_string(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue
	return 0;
}
