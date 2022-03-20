#include "../../../users/1/cpp/3-1-2_macrossortby/src/test_runner.h"
#include "../../../users/1/cpp/3-2-2_profiling/src/profile.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;


template <class T>
class ObjectPool {
public:
  T* Allocate() {
	  if (deallocated.empty()) {
		  T* obj = new T;
		  allocated.insert(obj);
		  return obj;
	  } else {
		  auto ptr = allocated.insert(deallocated.front());
		  deallocated.pop();
		  return *ptr.first;
	  }
  }
  T* TryAllocate(){
	  if (deallocated.empty()) {
		  return nullptr;
	  } else {
		  return Allocate();
	  }
  }

  void Deallocate(T* object){
	  if (allocated.find(object) == allocated.end()) {
		  throw invalid_argument("Invalid argument");
	  }

	  deallocated.push(object);
	  allocated.erase(object);
  }

  ~ObjectPool() {
	  while (!deallocated.empty()) {
		  delete deallocated.front();
		  deallocated.pop();
	  }
	  for (auto& p : allocated) {
	  	delete p;
	  }
  }

private:
  set<T*> allocated;
  queue<T*> deallocated;
};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}
