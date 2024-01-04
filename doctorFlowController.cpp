#include "doctorFlowController.h"

#include <iostream>
#include <memory>
#include <string>

#include "doctorsManager.h"
#include "helper.h"
#include "student.h"

std::shared_ptr<DoctorFlowController> gDoctorFlowController(new DoctorFlowController());

bool DoctorFlowController::isValidUser(std::string username, std::string password) {
  return gDoctorsManager->getUser(username, password) != nullptr;
}

void DoctorFlowController::takeControl(std::string username, std::string password) {
  this->currentDoctor = gDoctorsManager->getUser(username, password);

  this->showMainMenu();
}

void DoctorFlowController::showMainMenu() {
  std::vector<std::string> menu = {"List Courses", "Create Course", "View Course", "Logout"};

  int choice = Helper::runMenu(menu);

  // if (choice == 1) {
  //   this->listCourses();
  // } else if (choice == 2) {
  //   this->createCourse();
  // } else if (choice == 3) {
  //   this->viewCourse();
  // } else
  //   return;
}

void DoctorFlowController::listCourses() {
  for (std::shared_ptr<Course> course : this->currentDoctor->teachingCourses) {
    std::cout << "Course code: " << course->code << "\t" << course->registeredStudents.size()
              << " registered students\t" << course->assignments.size() << " assignments\n";

    // assignments
    std::cout << "Assignments: \n\t";

    // for (std::shared_ptr<Assignment> assignment : course->assignments) {
    //   std::cout << "Student ID: " << assignment->student->id << "\t";

    // }
  }
}