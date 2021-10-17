#include <iostream>
#include <set>
#include <algorithm>
//#include <iterator>
using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border);
// set<int>::const_iterator �
// ��� ���������� ��� ������������ ��������� ����� �����


set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border) {
	/* ��� ��������� ����� ����� numbers � ������� ����� border ����������
	 * �������� �� ������� ���������, ��������� � border.
	 * ���� ��������� ��������� ���������, ������ �������� �� ���������� �� ���.
	 */

	auto low = numbers.lower_bound(border);
	if (low == numbers.begin()) { return low; }
	if (low == numbers.end()) { return prev(low); }

	const bool is_left = (border - *prev(low) <= *low - border);
	  return is_left ? prev(low) : low;
}

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;

  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
