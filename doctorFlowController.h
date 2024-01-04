#ifndef DOCTOR_FLOW_CONTROLLER_H
#define DOCTOR_FLOW_CONTROLLER_H 1

#include <memory>
#include <string>

#include "doctor.h"

struct DoctorFlowController {
  std::shared_ptr<Doctor> currentDoctor;

  bool isValidUser(std::string username, std::string password);
  void takeControl(std::string username, std::string password);
  void showMainMenu();
  void listCourses();
};

extern std::shared_ptr<DoctorFlowController> gDoctorFlowController;

#endif