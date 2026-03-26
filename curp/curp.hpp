#pragma once
#include <string>
#include <vector>

using namespace std;

class CURP {
private: 
  vector<string> curps;
  int partition(int low, int high);
  void quickSort(int low, int high);
  int binarySearch(int low, int high, string value);
  int findIndex(string curp);

public:
  CURP(vector<string>& c);
  CURP();

  string findCurp(string curp);
  bool addCurp(string curp);
  bool updateCurp(string curp, string newCurp);
  bool deleteCurp(string curp);
  vector<string> getCurps();
};
