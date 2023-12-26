#ifndef DOCTOR_CLASS_H
#define DOCTOR_CLASS_H 1

#include <string>
#include <vector>

using std::string;
using std::vector;

struct Doctor {
  string username;
  string password;
  string name;
  string email;

  int id;
};

#endif