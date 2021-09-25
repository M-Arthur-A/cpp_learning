#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVectorPart(const vector<int>& numbers);

/* Напишите функцию PrintVectorPart, принимающую вектор целых чисел numbers,
 * выполняющую поиск первого отрицательного числа в нём и выводящую в стандартный вывод
 * все числа, расположенные левее найденного, в обратном порядке.
 * Если вектор не содержит отрицательных чисел, выведите все числа в обратном порядке. */

template <typename IT>
void PrintRange(const IT from, const IT to, bool reverse=false) {
	cout << "[ ";
	if (!reverse) {
		for (auto it = from; it < to; ++it) {
			cout << *it << " ";
		}
	} else {
		for (auto it = to; it > from;) {
			--it;
			cout << *it << " ";
		}
	}
	cout << "]" << endl;
}

void PrintVectorPart(const vector<int>& numbers) {
	auto negative_it = find_if(begin(numbers), end(numbers), [] (int item) {return item < 0;});
	PrintRange(begin(numbers), negative_it, true);
}

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}

/* 8 1 6
 *
 * 4 5 8 1 6 */
