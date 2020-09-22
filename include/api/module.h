#ifndef API_MODULE_H
#define API_MODULE_H

#include "api/types.h"

namespace api {

class Module {

  Status prv_state{Status::Uninitialized};

public:
  Module();

  void init();
  Status get_state();
};

} // namespace api

#endif // API_MODULE_H
