#include "../../../users/1/cpp/3-1-2_macrossortby/src/test_runner.h"
#include "../../../users/1/cpp/3-2-2_profiling/src/profile.h"
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class SimpleVector {
public:
  SimpleVector() = default;
  explicit SimpleVector(size_t size);
  ~SimpleVector();

  T& operator[](size_t index);

  T* begin();
  T* end();

  size_t Size() const;
  size_t Capacity() const;

  // принимаем объект по значению
  void PushBack(T value);

private:
  T* data = nullptr;
  size_t size = 0;
  size_t capacity = 0;

  void ExpandIfNeeded();
};

template <typename T>
SimpleVector<T>::SimpleVector(size_t size)
  : data(new T[size])
  , size(size)
  , capacity(size)
{
}

template <typename T>
SimpleVector<T>::~SimpleVector() {
  delete[] data;
}

template <typename T>
T& SimpleVector<T>::operator[](size_t index) {
  return data[index];
}

template <typename T>
size_t SimpleVector<T>::Size() const {
  return size;
}

template <typename T>
size_t SimpleVector<T>::Capacity() const {
  return capacity;
}

template <typename T>
void SimpleVector<T>::PushBack(T value) {
  ExpandIfNeeded();
  data[size++] = move(value);
}

template <typename T>
void SimpleVector<T>::ExpandIfNeeded() {
  if (size >= capacity) {
    auto new_cap = capacity == 0 ? 1 : 2 * capacity;
    auto new_data = new T[new_cap];
    // используем перемещение
    move(begin(), end(), new_data);
    delete[] data;
    data = new_data;
    capacity = new_cap;
  }
}

template <typename T>
T* SimpleVector<T>::begin() {
  return data;
}

template <typename T>
T* SimpleVector<T>::end() {
  return data + size;
}

void TestConstruction() {
  SimpleVector<int> empty;
  ASSERT_EQUAL(empty.Size(), 0u);
  ASSERT_EQUAL(empty.Capacity(), 0u);
  ASSERT(empty.begin() == empty.end());

  SimpleVector<string> five_strings(5);
  ASSERT_EQUAL(five_strings.Size(), 5u);
  ASSERT(five_strings.Size() <= five_strings.Capacity());
  for (auto& item : five_strings) {
    ASSERT(item.empty());
  }
  five_strings[2] = "Hello";
  ASSERT_EQUAL(five_strings[2], "Hello");
}

void TestPushBack() {
  SimpleVector<int> v;
  for (int i = 10; i >= 1; --i) {
    v.PushBack(i);
    ASSERT(v.Size() <= v.Capacity());
  }
  sort(begin(v), end(v));

  const vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT(equal(begin(v), end(v), begin(expected)));
}

class StringNonCopyable : public string {
public:
  using string::string;
  StringNonCopyable(string&& other) : string(move(other)) {}
  StringNonCopyable(const StringNonCopyable&) = delete;
  StringNonCopyable(StringNonCopyable&&) = default;
  StringNonCopyable& operator=(const StringNonCopyable&) = delete;
  StringNonCopyable& operator=(StringNonCopyable&&) = default;
};

void TestNoCopy() {
  SimpleVector<StringNonCopyable> strings;
  static const int SIZE = 10;
  for (int i = 0; i < SIZE; ++i) {
    strings.PushBack(StringNonCopyable(to_string(i)));
  }
  for (int i = 0; i < SIZE; ++i) {
    ASSERT_EQUAL(strings[i], to_string(i));
  }
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestConstruction);
  RUN_TEST(tr, TestPushBack);
  RUN_TEST(tr, TestNoCopy);
  return 0;
}
