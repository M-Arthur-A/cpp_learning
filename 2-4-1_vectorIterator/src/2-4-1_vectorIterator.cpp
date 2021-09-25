#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVectorPart(const vector<int>& numbers);

/* �������� ������� PrintVectorPart, ����������� ������ ����� ����� numbers,
 * ����������� ����� ������� �������������� ����� � �� � ��������� � ����������� �����
 * ��� �����, ������������� ����� ����������, � �������� �������.
 * ���� ������ �� �������� ������������� �����, �������� ��� ����� � �������� �������. */

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
  PrintVectorPart({-6, 1, 8, -5, 4});  // ������ �� ���������
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}

/* 8 1 6
 *
 * 4 5 8 1 6 */
