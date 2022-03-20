#include "../../../Users/1/cpp/3-1-2_macrosSortBy/src/test_runner.h"
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class Table {
public:
	Table(const size_t& row_count, const size_t& col_count) {
		Resize(row_count, col_count);
	}

	void Resize(const size_t& row_count, const size_t& col_count) {
		data.resize(row_count);
		for (auto& row : data) {
			row.resize(col_count);
		}
	}

	vector<T>& operator[](const size_t &index) {
		return data[index];
	}

	const vector<T>& operator[](const size_t &index) const {
		return data[index];
	}

	pair<size_t, size_t> Size() const {
		if (data.empty() && data[0].empty()) {
			return {0, 0};
		}
		return {data.size(), data[0].size()};
	}
private:
	vector<vector<T>> data;
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
