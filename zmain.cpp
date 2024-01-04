#include <vector>

#include "coursesManager.h"
#include "doctorsManager.h"
#include "studentsManager.h"
#include "userFlowController.h"

void generateRandomData() {
  // Generate system users
  gStudentsManager->addDummyData();
  gDoctorsManager->addDummyData();

  gCoursesManager->addDummyData();

  // Connect objects.
  gCoursesManager->addDummyRelationshipData();
}

int main() {
  generateRandomData();

  gStudentsManager->showStudents();
  gDoctorsManager->showDoctors();
  gCoursesManager->showCourses();

  gUserFlowController->showMainMenu();

  return 0;
}