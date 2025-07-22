#include "core/app.h"
#include <chrono>
#include <cstdlib>
#include <iostream>

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
  std::chrono::duration<double, std::milli> slice(8.33);
  auto sliceDuration = std::chrono::duration_cast<Clock::duration>(slice);

  while (m_running) {
    TimePoint now = Clock::now();
    m_deltaTime =
        std::chrono::duration_cast<Duration>(now - lastUpdate).count();
    lastUpdate +=
        std::chrono::duration_cast<Clock::duration>(Duration(m_deltaTime));
    accumulator +=
        std::chrono::duration_cast<Clock::duration>(Duration(m_deltaTime));

    std::cout << "Delta Time: " << m_deltaTime << " ms" << std::endl;
    std::cout << "Accumulator: " << accumulator << " ms" << std::endl;

    while (accumulator > slice) {
      accumulator -= sliceDuration;
      std::cout << "Update Loop" << std::endl;
    }
    std::cout << "Render loop" << std::endl;
  }
}

} // namespace Aerin
