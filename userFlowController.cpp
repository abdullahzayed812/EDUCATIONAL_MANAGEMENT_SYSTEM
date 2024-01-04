#include "userFlowController.h"

#include <assert.h>

#include <iostream>
#include <memory>
#include <vector>

#include "doctor.h"
#include "doctorFlowController.h"
#include "doctorsManager.h"
#include "helper.h"
#include "studentFlowController.h"
#include "studentsManager.h"

std::shared_ptr<UserFlowController> gUserFlowController(new UserFlowController());

void UserFlowController::showMainMenu() {
  std::vector<std::string> menu = {"Sign In", "Sign Up", "Shutdown"};

  int choice = Helper::runMenu(menu);

  if (choice == 1) {
    this->signIn();
  } else if (choice == 2) {
    this->signUp();
  } else if (choice == 3) {
    return;
  }
}

void UserFlowController::signIn() {
  std::string username;
  std::string password;

  std::cout << "\nEnter username: ";
  std::cin >> username;

  std::cout << "Enter password: ";
  std::cin >> password;

  if (gStudentFlowController->isValidUser(username, password)) {
    gStudentFlowController->takeControl(username, password);
  } else if (gDoctorFlowController->isValidUser(username, password)) {
    gDoctorFlowController->takeControl(username, password);
  } else {
    std::cout << "ERROR: Invalid login... Try again\n";
    this->signIn();
  }
}

void UserFlowController::signUp() {}
