#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements);


template <typename T>
void RemoveDuplicates(vector<T>& elements) {
	for (auto it = begin(elements); it < end(elements); ++it) {
		for (auto it2 = begin(elements); it2 < end(elements); ++it2) {
			if (*it == *it2 and it != it2) {
				elements.erase(it2);
			}
		}
	}
}

int main() {
  vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1, 7, 6, 2, 0};
  RemoveDuplicates(v1);
  for (int x : v1) {
    cout << x << " ";
  }
  cout << endl;

  vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
  RemoveDuplicates(v2);
  for (const string& s : v2) {
    cout << s << " ";
  }
  cout << endl;
  return 0;
}

// 6 4 7 0 1 2
// C++ C
