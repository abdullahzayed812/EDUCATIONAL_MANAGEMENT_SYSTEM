#include "coursesManager.h"

#include <iomanip>
#include <iostream>
#include <vector>

#include "course.h"
#include "student.h"

std::shared_ptr<CoursesManager> gCoursesManager(new CoursesManager);

void CoursesManager::addDummyData() {
  std::shared_ptr<Course> course01(new Course);
  course01->name = "Programming 1";
  course01->code = "CS111";
  this->courses.push_back(course01);

  std::shared_ptr<Course> course02(new Course);
  course02->name = "Programming 2";
  course02->code = "CS112";
  this->courses.push_back(course02);

  std::shared_ptr<Course> course03(new Course);
  course03->name = "Math 1";
  course03->code = "CS123";
  this->courses.push_back(course03);

  std::shared_ptr<Course> course04(new Course);
  course04->name = "Math 2";
  course04->code = "CS191";
  this->courses.push_back(course04);

  std::shared_ptr<Course> course05(new Course);
  course05->name = "Calculus";
  course05->code = "CS183";
  this->courses.push_back(course05);

  std::shared_ptr<Course> course06(new Course);
  course06->name = "Data Structure";
  course06->code = "CS100";
  this->courses.push_back(course06);

  std::shared_ptr<Course> course07(new Course);
  course07->name = "Algorithms";
  course07->code = "CS124";
  this->courses.push_back(course07);
}

void CoursesManager::showCourses() {
  for (std::shared_ptr<Course> course : this->courses) {
    std::cout << "Course name: " << course->name << "\tCode = " << course->code << " - Taught by Dr: " << course->doctor
              << "\n";

    std::cout << " Registered students ID: ";
    for (std::shared_ptr<Student> student : course->registeredStudents) {
      std::cout << student->id << " ";
    }
    std::cout << "\n\n";
  }
  std::cout << "\n*********************************************************\n";
}