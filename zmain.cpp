#include <vector>

#include "coursesManager.h"
#include "doctorsManager.h"
#include "studentsManager.h"

void generateRandomData() {
  // Generate system users
  gStudentsManager->addDummyData();
  gDoctorsManager->addDummyData();

  gCoursesManager->addDummyData();
}

int main() {
  generateRandomData();

  gStudentsManager->showStudents();
  gDoctorsManager->showDoctors();
  gCoursesManager->showCourses();

  return 0;
}