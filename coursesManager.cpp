#include "coursesManager.h"

#include <iomanip>
#include <iostream>
#include <vector>

#include "assignment.h"
#include "assignmentSolution.h"
#include "course.h"
#include "doctorsManager.h"
#include "helper.h"
#include "student.h"
#include "studentsManager.h"

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
    std::cout << "Course name: " << course->name << "\tCode = " << course->code
              << " - Taught by Dr: " << course->doctor->name << "\n";

    std::cout << " Registered students ID: ";
    for (std::shared_ptr<Student> student : course->registeredStudents) {
      std::cout << student->id << " ";
    }
    std::cout << "\n\n";
  }
  std::cout << "\n*********************************************************\n";
}

void CoursesManager::addDummyRelationshipData() {
  // add student and assignments to course,
  // add assignment solution
  for (std::shared_ptr<Course> course : this->courses) {
    // generate 75% of students per course.
    int registeredStudentsCount = (int)gStudentsManager->students.size() * 75.0 / 100.0;

    course->registeredStudents = Helper::getRandomSubset(gStudentsManager->students, registeredStudentsCount);
    course->doctor = Helper::getRandomSubset(gDoctorsManager->doctors, 1)[0];

    for (int r = 1 + std::rand() % 5; r; r--) {
      std::shared_ptr<Assignment> assignment(new Assignment);

      assignment->content = "Assignment " + Helper::toString(r, 3);
      assignment->maxGrade = 10 + std::rand() % 100;
      assignment->course = course;

      course->assignments.push_back(assignment);

      // generate 60% of course registered students solutions.
      int solvedStudentsCount = course->registeredStudents.size() * 60.0 / 100.0;

      std::vector<std::shared_ptr<Student>> someStudents =
          Helper::getRandomSubset(course->registeredStudents, solvedStudentsCount);

      for (std::shared_ptr<Student> student : someStudents) {
        std::shared_ptr<AssignmentSolution> assignmentSolution(new AssignmentSolution());

        assignmentSolution->student = student;
        assignmentSolution->assignment = assignment;
        assignmentSolution->answer = Helper::toString(std::rand() % 10000, 5) +
                                     Helper::toString(std::rand() % 10000, 5) +
                                     Helper::toString(std::rand() % 10000, 5);

        if (Helper::probability() > 5.0) {
          assignmentSolution->isGraded = true;
          assignmentSolution->grade = std::rand() % (1 + assignment->maxGrade);
        }

        // assignment->assignmentSolutions.push_back(assignmentSolution);
        assignmentSolution->student->assignmentSolutions.push_back(assignmentSolution);
      }
    }

    // add course to doctor.
    course->doctor->teachingCourses.push_back(course);

    // add course to student.
    for (std::shared_ptr<Student> student : course->registeredStudents) student->registeredCourses.push_back(course);
  }
}