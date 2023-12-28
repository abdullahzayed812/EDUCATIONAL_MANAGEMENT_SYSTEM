#ifndef STUDENT_MANAGER_CLASS_H
#define STUDENT_MANAGER_CLASS_H 1

#include <memory>
#include <vector>

#include "student.h"

struct StudentsManager {
  std::vector<std::shared_ptr<Student>> students;

  void addDummyData();
  void showStudents();
};

extern std::shared_ptr<StudentsManager> gStudentsManager;

#endif