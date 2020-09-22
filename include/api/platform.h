#ifndef API_PLATFORM_H
#define API_PLATFORM_H

#include "api/types.h"

namespace api {

class Module;

Status setup();

Module get_module();

} // namespace api

#endif // API_PLATFORM_H
