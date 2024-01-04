#include "studentFlowController.h"

#include <iostream>
#include <memory>
#include <string>

#include "helper.h"
#include "student.h"
#include "studentsManager.h"

std::shared_ptr<StudentFlowController> gStudentFlowController(new StudentFlowController());

bool StudentFlowController::isValidUser(std::string username, std::string password) {
  return gStudentsManager->getUser(username, password) != nullptr;
}

void StudentFlowController::takeControl(std::string username, std::string password) {
  this->currentStudent = gStudentsManager->getUser(username, password);

  std::cout << "\t\t\t******* Welcome " << currentStudent->name << " *******\n\n";

  this->showMainMenu();
}

void StudentFlowController::showMainMenu() {
  vector<string> menu = {"Register in Course", "List My Courses", "View Course", "Grades Report", "Log out"};

  int choice = Helper::runMenu(menu);
}