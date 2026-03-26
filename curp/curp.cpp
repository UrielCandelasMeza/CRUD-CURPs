#include "curp.hpp"
#include <algorithm>
#include <cstddef>
#include <utility>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

CURP::CURP(){}

CURP::CURP(vector<string>& c): curps(c) {}


int CURP::partition(int low, int high) {
  
  string pivot = curps[high];

  int i = low - 1;


  for (int j = low; j < high ; j++) {
    if(curps[j] < pivot) {
      i++;
      swap(curps[i], curps[j]);
    }

  }

  swap(curps[i + 1], curps[high]);

  return i + 1;
}

void CURP::quickSort(int low, int high) {
  if(low < high) {
    int partitionIdx = partition(low, high);

    quickSort(low, partitionIdx - 1);
    quickSort(partitionIdx + 1, high);
  }
}

int CURP::binarySearch(int low, int high, string value) {

  if(low > high) {
    return -1;
  }

  int middle = low + (high - low) / 2;

  if (curps[middle] == value) {
    return middle;
  } else if(curps[middle] < value) {
    return binarySearch(middle + 1, high, value);
  } else {
    return binarySearch(low, middle - 1, value);
  }
}

string CURP::findCurp(string curp) {
  if(curps.empty()) return "empty";

  quickSort(0, curps.size() - 1);
  int position = binarySearch(0, curps.size() - 1, curp);

  if(position == -1) {
    return "not_found";
  }

  return curps[position];

}

int CURP::findIndex(string curp) {
  if(curps.empty()) return -1;


  quickSort(0, curps.size() - 1);
  int position = binarySearch(0, curps.size() - 1, curp);

  if(position == -1) {
    return -1;
  }

  return position;
}

bool CURP::addCurp(string curp) {

  string finded = findCurp(curp);

  if(finded == curp) {
    return false;
  }

  curps.push_back(curp);
  return true;
}

vector<string> CURP::getCurps() {
  return curps;
}

bool CURP::deleteCurp(string curp) {

  int position = findIndex(curp);

  if(position == -1) {
    return false;
  }

  curps.erase(curps.begin() + position);

  return true;
  
}

bool CURP::updateCurp(string curp, string newCurp) {
  int positionOld = findIndex(curp);
  int positionNew = findIndex(newCurp);

  if(positionOld == -1) {
    return false;
  }

  if(positionNew != -1) {
    return false;
  }

  curps.at(positionOld) = newCurp;

  return true;

}

