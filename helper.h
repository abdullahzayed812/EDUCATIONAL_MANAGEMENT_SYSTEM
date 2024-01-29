#ifndef HELPER_CLASS_H
#define HELPER_CLASS_H 1

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

struct Helper {
  static int readInt(int low, int high);
  static int runMenu(std::vector<std::string>& menu);
  static std::string toString(int value, int length);
  static double probability();

  template <typename Type>
  static std::vector<Type> getRandomSubset(const std::vector<Type>& originalList,
                                           int subsetLength) {
    assert((int)originalList.size() >= subsetLength);

    std::vector<int> indices;

    for (size_t i = 0; i < originalList.size(); i++) {
      indices.push_back(i);
    }

    std::random_shuffle(indices.begin(), indices.end());

    std::vector<Type> result;

    for (int i = 0; i < subsetLength; i++) {
      result.push_back(originalList[indices[i]]);
    }

    return result;
  }

  template <typename Type>
  static void removeElement(std::vector<std::shared_ptr<Type>>& vec,
                            std::shared_ptr<Type> element) {
    for (int i = 0; i < (int)vec.size(); i++) {
      if (vec[i] == element) {
        vec.erase(vec.begin() + i);
        i--;
      }
    }
  }
};

#endif