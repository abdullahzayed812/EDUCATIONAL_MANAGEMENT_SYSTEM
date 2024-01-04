#ifndef USER_FLOW_CONTROLLER_CLASS_H
#define USER_FLOW_CONTROLLER_CLASS_H 1

#include <memory>

struct UserFlowController {
  void signIn();
  void signUp();
  void showMainMenu();
};

extern std::shared_ptr<UserFlowController> gUserFlowController;

#endif