#ifndef COURSES_MANAGER_H
#define COURSES_MANAGER_H 1

#include <vector>

#include "course.h"

struct CoursesManager {
  void addDummyData();
  void showCourses();
  void addDummyRelationshipData();

  std::vector<std::shared_ptr<Course>> courses;
};

extern std::shared_ptr<CoursesManager> gCoursesManager;

#endif