#include <iostream>

#include "helper.h"
// #include "string"

using std::cin;
using std::cout;
using std::string;

int main() {
  vector<string> menu = {"View Course", "Register In Course", "Grades Report", "Logout"};
  Helper::runMenu(menu);

  return 0;
}