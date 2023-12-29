#ifndef HELPER_CLASS_H
#define HELPER_CLASS_H 1

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Helper {
  static int readInt(int low, int high);
  static int runMenu(vector<string>& menu);
  static string toString(int value, int length);
  static double probability();

  template <typename Type>
  static vector<Type> getRandomSubset(const vector<Type>& originalList, int subsetLength) {
    assert((int)originalList.size() >= subsetLength);

    vector<int> indices;

    for (size_t i = 0; i < originalList.size(); i++) {
      indices.push_back(i);
    }

    std::random_shuffle(indices.begin(), indices.end());

    vector<Type> result;

    for (int i = 0; i < subsetLength; i++) {
      result.push_back(originalList[indices[i]]);
    }

    return result;
  }
};

#endif