#include "studentFlowController.h"

#include <iostream>
#include <memory>
#include <string>
#include <tuple>

#include "assignmentSolution.h"
#include "course.h"
#include "coursesManager.h"
#include "doctor.h"
#include "helper.h"
#include "studentsManager.h"
#include "userFlowController.h"

std::shared_ptr<StudentFlowController> gStudentFlowController(
    new StudentFlowController());

bool StudentFlowController::isValidUser(std::string username,
                                        std::string password) {
  return gStudentsManager->getUser(username, password) != nullptr;
}

void StudentFlowController::takeControl(std::string username,
                                        std::string password) {
  this->currentStudent = gStudentsManager->getUser(username, password);

  std::cout << "\t\t\t******* Welcome " << currentStudent->name
            << " *******\n\n";

  this->showMainMenu();
}

void StudentFlowController::showMainMenu() {
  vector<string> menu = {"Register in Course", "List My Courses", "View Course",
                         "Grades Report", "Log out"};

  while (true) {
    int choice = Helper::runMenu(menu);

    if (choice == 1) {
      this->registerInCourse();
    } else if (choice == 2) {
      this->listCourses();
    } else if (choice == 3) {
      this->viewCourse();
    } else if (choice == 4) {
      this->showGradesReport();
    } else {
      gUserFlowController->showMainMenu();
    }
  }
}

void StudentFlowController::registerInCourse() {
  std::vector<std::shared_ptr<Course>> availableCourses =
      gCoursesManager->getComplementCourses(
          this->currentStudent->registeredCourses);

  std::cout << "\nAvailable courses for you: \n\t";

  int pos = 0;

  for (std::shared_ptr<Course> course : availableCourses) {
    std::cout << ++pos << " - Course name: " << course->name
              << "\twith code: " << course->code
              << "\ttaught by doctor: " << course->doctor << "\n\t";
  }

  std::cout << "\n\tEnter course number [1 - " << availableCourses.size()
            << "]: ";

  int choice = Helper::readInt(1, (int)availableCourses.size());

  availableCourses[choice - 1]->registeredStudents.push_back(
      this->currentStudent);
  this->currentStudent->registeredCourses.push_back(
      availableCourses[choice - 1]);

  std::cout << "\n!!! REGISTERED SUCCESSFULLY !!!\n";
}

void StudentFlowController::listCourses() {
  int pos;

  std::cout << "\nMy courses list: \n";

  for (std::shared_ptr<Course> course :
       this->currentStudent->registeredCourses) {
    std::cout << "\t" << ++pos << " - with code: " << course->name;
    std::cout << "\t course code: " << course->code << "\n";
  }
}

void StudentFlowController::viewCourse() {
  if (this->currentStudent->registeredCourses.size() == 0) {
    std::cout << "\nNo registered courses\n";
    return;
  }

  this->listCourses();

  int coursesCount = (int)this->currentStudent->registeredCourses.size();

  std::cout << "\n\tWhich ith [1 - " << coursesCount << "] course to view: ";

  int choice = Helper::readInt(1, coursesCount) - 1;

  this->currentCourse = this->currentStudent->registeredCourses[choice];

  std::cout << "\n\tCourse name: " << this->currentCourse->name
            << "\t with code: " << this->currentCourse->code << "\n";
  std::cout << "\tTaught by doctor: " << this->currentCourse->doctor->name
            << "\n";
  std::cout << "\tCourse has " << this->currentCourse->assignments.size()
            << " assignments: \n";

  int pos = 0;

  for (std::shared_ptr<Assignment> assignment :
       this->currentCourse->assignments) {
    std::cout << "\t\tAssignment - " << ++pos << " : ";

    std::shared_ptr<AssignmentSolution> assignmentSolution =
        this->currentStudent->getAssignmentSolution(assignment);

    if (assignmentSolution == nullptr) {
      std::cout << "NOT submitted - NA";
    } else {
      std::cout << "submitted ";

      if (assignmentSolution->isGraded) {
        std::cout << assignmentSolution->grade;
      } else {
        std::cout << "NA";
      }
    }

    std::cout << " / " << assignment->maxGrade << "\n";
  }

  this->showCourseMenu();
}

void StudentFlowController::showCourseMenu() {
  std::vector<std::string> menu = {"Unregister from course ", "Submit solution",
                                   "Back"};

  while (true) {
    int choice = Helper::runMenu(menu);

    if (choice == 1) {
      this->unregisterFromCourse();
    } else if (choice == 2) {
      this->submitCourseAssignment();
    } else {
      break;
    }
  }
}

void StudentFlowController::unregisterFromCourse() {
  Helper::removeElement(this->currentCourse->registeredStudents,
                        this->currentStudent);
  Helper::removeElement(this->currentStudent->registeredCourses,
                        this->currentCourse);
}

void StudentFlowController::submitCourseAssignment() {
  int assignmentsCount = (int)this->currentCourse->assignments.size();

  std::cout << "\nWhich ith [1 - " << assignmentsCount
            << " ] assignment to submit? ";

  int choice = Helper::readInt(1, assignmentsCount) - 1;

  std::shared_ptr<Assignment> currentAssignment =
      this->currentCourse->assignments[choice];

  std::shared_ptr<AssignmentSolution> newAssignmentSolution(
      new AssignmentSolution());

  std::cout << "Enter answer: ";
  std::cin >> newAssignmentSolution->answer;

  newAssignmentSolution->isGraded = false;
  newAssignmentSolution->student = this->currentStudent;
  newAssignmentSolution->assignment = currentAssignment;

  std::vector<std::shared_ptr<AssignmentSolution>>&
      studentAssignmentsSolutions = this->currentStudent->assignmentSolutions;

  // ENSURE THIS ASSIGNMENT NOT EXISTED BEFORE
  for (int i = 0; i < (int)studentAssignmentsSolutions.size(); i++) {
    if (studentAssignmentsSolutions[i]->assignment == currentAssignment) {
      std::vector<std::shared_ptr<AssignmentSolution>>&
          currentCourseAssignmentSolutions =
              currentAssignment->assignmentSolutions;

      for (int j = 0; j < (int)currentCourseAssignmentSolutions.size(); j++) {
        if (studentAssignmentsSolutions[i] ==
            currentCourseAssignmentSolutions[j]) {
          currentCourseAssignmentSolutions.erase(
              currentCourseAssignmentSolutions.begin() + j);
          break;
        }
      }

      studentAssignmentsSolutions.erase(studentAssignmentsSolutions.begin() +
                                        i);
      break;
    }
  }

  this->currentStudent->assignmentSolutions.push_back(newAssignmentSolution);
  currentAssignment->assignmentSolutions.push_back(newAssignmentSolution);
}

void StudentFlowController::showGradesReport() {
  std::vector<std::tuple<std::string, int, int, int>> studentGrades =
      this->currentStudent->computeGradesStatistic();

  if (studentGrades.size() == 0) {
    std::cout << "\nNo Assignments to show report\n";
  }

  for (std::tuple<std::string, int, int, int> studentCourseGrade :
       studentGrades) {
    std::cout << "\n\tCourse code: " << std::get<0>(studentCourseGrade)
              << "\tTotal assignments: " << std::get<1>(studentCourseGrade)
              << "\tYour mark: " << std::get<2>(studentCourseGrade) << " / "
              << std::get<3>(studentCourseGrade) << "\n";
  }
}
