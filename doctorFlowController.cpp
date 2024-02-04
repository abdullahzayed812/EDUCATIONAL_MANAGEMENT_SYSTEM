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

  std::cout << "\t\t\t******* Welcome DR " << this->currentDoctor->name << " *******\n\n";

  this->showMainMenu();
}

void DoctorFlowController::showMainMenu() {
  std::vector<std::string> menu = {"List Courses", "Create Course", "View Course", "Logout"};

  int choice = Helper::runMenu(menu);

  while (true) {
    if (choice == 1) {
      this->listCourses();
    } else {
      break;
    }
  }
}

void DoctorFlowController::listCourses() {
  int pos = 0;

  std::cout << "\nMy courses list: \n";

  for (std::shared_ptr<Course> course : this->currentDoctor->teachingCourses) {
    std::cout << "\t" << ++pos << " - Course name: " << course->name;
    std::cout << "\t course code: " << course->code << "\n";
  }
}