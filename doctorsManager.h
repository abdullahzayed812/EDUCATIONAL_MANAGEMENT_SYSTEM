#ifndef DOCTORS_MANAGER_CLASS_H
#define DOCTORS_MANAGER_CLASS_H 1

#include <memory>
#include <string>
#include <vector>

#include "doctor.h"

struct DoctorsManager {
  std::vector<std::shared_ptr<Doctor>> doctors;

  void addDummyData();
  void showDoctors();
  std::shared_ptr<Doctor> getUser(std::string username, std::string password);
};

extern std::shared_ptr<DoctorsManager> gDoctorsManager;

#endif