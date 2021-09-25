#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> SplitIntoWords(const string& s);

/*
 * �������� ������� SplitIntoWords, ����������� ������ �� ����� �� ��������.
 * - ������ ��������� ������ � ������� ��������� find;
 * - ��������� ��������� ����� � ������� ������������ ������ �� ���� ����������.
 */

vector<string> SplitIntoWords(const string& s) {
	vector<string> newords;
	auto it_begin = s.begin();

	for (auto it = s.begin(); it < s.end(); ++it) {
		if  (*it == ' ')  {
			newords.push_back({it_begin, it});
			it_begin = ++it;
		}
	}
	newords.push_back({it_begin , s.end()});
	return newords;
}

int main() {
	string s = "C Cpp Java Python";
	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;
	return 0;
}

/* 4 �/Cpp/Java/Python */
