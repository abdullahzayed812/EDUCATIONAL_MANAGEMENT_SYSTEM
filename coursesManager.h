#ifndef COURSES_MANAGER_H
#define COURSES_MANAGER_H 1

#include <vector>

#include "course.h"

struct CoursesManager {
  std::vector<std::shared_ptr<Course>> courses;

  void addDummyData();
  void showCourses();
};

extern std::shared_ptr<CoursesManager> gCoursesManager;

#endif