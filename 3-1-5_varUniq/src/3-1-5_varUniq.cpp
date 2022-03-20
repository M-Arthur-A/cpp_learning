#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define UNIQ_ID__(LINE) __uniqueVar##LINE
#define UNIQ_ID_(LINE) UNIQ_ID__(LINE)
#define UNIQ_ID UNIQ_ID_(__LINE__)

#define VAR_TO_STR(variable) #variable

int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
  //cout << VAR_TO_STR(UNIQ_ID) << endl;
}
