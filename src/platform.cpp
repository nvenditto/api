#include "api/platform.h"

namespace api {
Status setup() { return Status::Ready; }

Module get_module() { return Module(); }
} // namespace api
