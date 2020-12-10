#include "api/platform.h"
#include "api/module.h"

namespace api {
Status setup() { return Status::Ready; }

Module get_module() { return Module(); }
} // namespace api
