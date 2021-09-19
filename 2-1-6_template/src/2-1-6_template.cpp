#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;


// Предварительное объявление шаблонных функций
template<typename T> vector<T>& Sqr(vector<T>& x);
template<typename T> map<int, pair<T, T>>& Sqr(map<int, pair<T, T>>& x);


// Объявляем шаблонные функции
template <typename T>
vector<T>& Sqr(vector<T>& x) {
	for (auto& i : x) { i = i*i; }
	return x;
}
template<typename T>
map<int, pair<T, T>>& Sqr(map<int, pair<T, T>>& x) {
	for (auto& i : x) {
		i.second.first = i.second.first * i.second.first;
		i.second.second = i.second.second * i.second.second;
	}
	return x;
}


int main() {
	vector<int> v = {1, 2, 3};
	cout << "vector: [";
	for (int x : Sqr(v)) { cout << ' ' << x; }
	cout << " ]" << endl;


	map<int, pair<int, int>> map_of_pairs = {
											 {4, {2, 2}},
											 {7, {4, 3}}
											};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}	return 0;
}
