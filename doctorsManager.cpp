#include "doctorsManager.h"

#include <iostream>
#include <memory>
#include <vector>

#include "doctor.h"
#include "helper.h"

std::shared_ptr<DoctorsManager> gDoctorsManager(new DoctorsManager());

void DoctorsManager::addDummyData() {
  std::vector<std::string> names = {"Hassan", "Mokhtar", "Salah",  "Emad",   "Karem",
                                    "Mohsen", "Isam",    "Raafat", "Moneer", "Gamil"};

  for (int i = 0; i < (int)names.size(); i++) {
    std::shared_ptr<Doctor> doctor(new Doctor());

    doctor->username = "d" + Helper::toString(i, 3);
    doctor->password = "d" + Helper::toString(i, 3);
    doctor->name =
        names[std::rand() % (int)names.size()] + " " + names[std::rand() % (int)names.size()];
    doctor->email = Helper::toString(i, 3) + "@gmail.com";

    this->doctors.push_back(doctor);
  }
}

void DoctorsManager::showDoctors() {
  for (std::shared_ptr<Doctor> doctor : this->doctors) {
    std::cout << "Doctor " << doctor->name << " is teaching " << (int)doctor->teachingCourses.size()
              << " courses.";

    if (doctor->teachingCourses.size() > 0) {
      std::cout << " Courses codes: ";
      for (std::shared_ptr<Course> course : doctor->teachingCourses) {
        std::cout << " " << course->code;
      }
    }
    std::cout << "\n";
  }
  std::cout << "\n*********************************************************\n";
}

std::shared_ptr<Doctor> DoctorsManager::getUser(std::string username, std::string password) {
  for (std::shared_ptr<Doctor> doctor : this->doctors) {
    if (doctor->username == username && doctor->password == password) {
      return doctor;
    }
  }

  return nullptr;
}