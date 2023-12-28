#ifndef DOCTORS_MANAGER_CLASS_H
#define DOCTORS_MANAGER_CLASS_H 1

#include <memory>
#include <vector>

#include "doctor.h"

struct DoctorsManager {
  std::vector<std::shared_ptr<Doctor>> doctors;

  void addDummyData();
  void showDoctors();
};

extern std::shared_ptr<DoctorsManager> gDoctorsManager;

#endif