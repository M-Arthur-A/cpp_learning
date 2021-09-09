#include <iostream>
#include <vector>
using namespace std;


class Temperature {
	vector<int> t;
public:
	Temperature(unsigned size) {
		int item;
		for (unsigned i = 0; i < size; ++i) {
			cout << "enter " << i+1 << " day temperature:" << endl << ">: ";
			cin >> item;
			t.push_back(item);
			cout << endl;
		}
	}

	int getTemp(unsigned day) const {return t.at(day-1);};

	void unnormalDay() const {
		/*
		 * return day with temperature higher than average
		 */
		int temp_avg, temp_sum;
		size_t size = t.size();
		vector<unsigned> result;

		// get average
		for (int d : t) {temp_sum += d;}
		temp_avg = temp_sum / static_cast<int>(size);

		// get results with high temperature
		for (unsigned day = 1; day <= size; ++day) {
			if (getTemp(day) > temp_avg) {
				result.push_back(day);
			}
		}

		// show results
		if (result.size()) {
			cout << "There is/are days with temperature higher than " << temp_avg << ": [ ";
			for (int day : result) {cout << day << "(" << getTemp(day) << ") ";}
			cout << "]" << endl;
		} else {
			cout << "There is no days with temperature higher than "
					<< temp_avg << " (average temperature)" << endl;
		}
	}
};

int main() {
	unsigned size;
	cout << "Enter size of vector with temperature:" << endl << ">: ";
	cin >> size;
	cout << endl;
	Temperature t(size);
	t.unnormalDay();
	return 0;
}
