#include "studentsManager.h"

#include <iostream>
#include <string>
#include <vector>

#include "helper.h"
#include "student.h"

std::shared_ptr<StudentsManager> gStudentsManager(new StudentsManager());

void StudentsManager::addDummyData() {
  std::vector<std::string> names = {"Ahmed",   "Mohamed", "Ali",      "Mahmoud", "Salem", "Kamal",
                                    "Soliman", "Omar",    "Eldesoqy", "Khaled",  "Saad"};

  for (int i = 1; i <= 20; i++) {
    std::shared_ptr<Student> student(new Student());

    student->username = "s" + Helper::toString(i, 3);
    student->password = "s" + Helper::toString(i, 3);
    student->name = names[std::rand() % (int)names.size()] + " " + names[std::rand() % (int)names.size()];
    student->id = Helper::toString(i, 3) + Helper::toString((i * 12345) % 10000, 5);
    student->email = Helper::toString(i, 3) + "@gmail.com";

    this->students.push_back(student);
  }
}

void StudentsManager::showStudents() {
  for (std::shared_ptr<Student> student : this->students) {
    std::cout << "\nStudent " << student->name << " with ID " << student->id << " registered in "
              << (int)student->registeredCourses.size() << " courses.";

    if (student->registeredCourses.size() > 0) {
      std::cout << "\tCourses list:";
      for (std::shared_ptr<Course> course : student->registeredCourses) {
        std::cout << " " << course->code;
      }
    }
  }
  std::cout << "\n*********************************************************\n";
}

std::shared_ptr<Student> StudentsManager::getUser(std::string username, std::string password) {
  for (std::shared_ptr<Student> student : this->students) {
    if (student->username == username && student->password == password) {
      return student;
    }
  }

  return nullptr;
}