#ifndef STUDENT_MANAGER_CLASS_H
#define STUDENT_MANAGER_CLASS_H 1

#include <memory>
#include <string>
#include <vector>

#include "student.h"

struct StudentsManager {
  std::vector<std::shared_ptr<Student>> students;

  void addDummyData();
  void showStudents();
  std::shared_ptr<Student> getUser(std::string username, std::string password);
};

extern std::shared_ptr<StudentsManager> gStudentsManager;

#endif