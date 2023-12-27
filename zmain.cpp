#include <iostream>
#include <vector>

#include "assignment.h"
#include "assignmentSolution.h"
#include "course.h"
#include "doctor.h"
#include "helper.h"
#include "student.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  vector<int> result = Helper::getRandomSubset<int>(nums, 8);

  for (vector<int>::iterator it = result.begin(); it != result.end(); it++) {
    cout << *it << "\n";
  }

  return 0;
}