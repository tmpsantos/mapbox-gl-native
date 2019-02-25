#pragma once

#include <mbgl/actor/scheduler.hpp>

#include <memory>

namespace mbgl {
namespace platform {

Scheduler& GetBackgroundScheduler();

} // namespace platform
} // namespace mbgl
