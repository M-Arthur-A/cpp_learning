#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include "profile.h"

using namespace std;

class Learner {
 private:
	set<string> dict;

 public:
	int Learn(const vector<string>& words) {
		LOG_DURATION("Learn")
		int newWords = 0;
		for (const auto& word : words) {
			if (dict.insert(word).second) {
				++newWords;
			}
		}
		return newWords;
	}

	vector<string> KnownWords() {
		LOG_DURATION("KnownWords")
		return {dict.begin(), dict.end()};
	}
};


int main() {
	Learner learner;
	string line;
	while (getline(cin, line)) {
		vector<string> words;
		stringstream ss(line);
		string word;
		while (ss >> word) {
			words.push_back(word);
		}
		cout << learner.Learn(words) << "\n";
	}
	cout << "\n=== known words ===\n";
	for (auto word : learner.KnownWords()) {
		cout << word << "\n";
	}
}
