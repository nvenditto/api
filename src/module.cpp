#include "api/module.h"
#include "basic/basic_object.h"

namespace api {
Module::Module() {
  basic::basic_object myObject;
  myObject.initialize();
}

void Module::init() { prv_state = Status::Ready; }

Status Module::get_state() { return prv_state; }
} // namespace api
