#ifndef HELPER_CLASS_H
#define HELPER_CLASS_H 1

#include <string>
#include <vector>

using std::string;
using std::vector;

struct Helper {
  static int readInt(int low, int high);
  static int runMenu(vector<string> &menu);
};

#endif