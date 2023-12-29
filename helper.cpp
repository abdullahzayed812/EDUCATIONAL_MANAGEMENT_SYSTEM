#include "helper.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::vector;

int Helper::readInt(int low, int high) {
  string input;
  cin >> input;

  istringstream stringstream(input);
  int value;
  stringstream >> value;

  if (stringstream.fail()) {
    cout << "ERROR: Expected integer input... try again - Enter number: ";
    return readInt(low, high);
  }

  if (value >= low && value <= high) {
    return value;
  }

  cout << "ERROR: Expected integer in range [" << low << "-" << high << "]: ";
  return readInt(low, high);
}

int Helper::runMenu(vector<string>& menu) {
  cout << "\n\nPlease make a choice:\n\n";

  for (int i = 0; i < (int)menu.size(); i++) {
    cout << "\t" << i + 1 << " - " << menu[i] << "\n";
  }

  cout << "\n\tEnter choice: ";
  return Helper::readInt(1, menu.size());
}

string Helper::toString(int value, int length) {
  ostringstream oss;

  oss << value;

  string ret = oss.str();

  while ((int)ret.size() < length) {
    ret = "0" + ret;
  }

  return ret;
}

double Helper::probability() { return std::rand() * 1.0 / RAND_MAX; }
