#include "core/app.h"
#include <chrono>
#include <print>

#define UPDATE_MS 8.33

namespace Aerin {
App::App() {}
App::~App() {}

void App::Run() {

  using Clock = std::chrono::high_resolution_clock;
  using TimePoint = std::chrono::time_point<Clock>;
  using Duration = std::chrono::duration<double, std::milli>;

  m_running = true;
  TimePoint lastUpdate = Clock::now();
  Clock::duration accumulator = Clock::duration::zero();
  std::chrono::duration<double, std::milli> slice(UPDATE_MS);
  auto sliceDuration = std::chrono::duration_cast<Clock::duration>(slice);

  while (m_running) {
    TimePoint now = Clock::now();
    m_deltaTime =
        (float)std::chrono::duration_cast<Duration>(now - lastUpdate).count();
    lastUpdate +=
        std::chrono::duration_cast<Clock::duration>(Duration(m_deltaTime));
    accumulator +=
        std::chrono::duration_cast<Clock::duration>(Duration(m_deltaTime));

    while (accumulator > slice) {
      accumulator -= sliceDuration;
      std::println("Update");
    }
    std::println("Render");
  }
}

} // namespace Aerin
