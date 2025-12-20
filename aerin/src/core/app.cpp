#include "core/app.hpp"
#include <chrono>
#include <memory>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define FIXED_UPDATE_MS 16.6

namespace Aerin {
App::App(const AppSpecs &specs) {
  m_window =
      Window::Create(WindowConfig(WINDOW_WIDTH, WINDOW_HEIGHT, specs.name));
}
App::~App() {}

void App::Run() {
  using Clock = std::chrono::high_resolution_clock;
  using TimePoint = std::chrono::time_point<Clock>;
  using Duration = std::chrono::duration<double, std::milli>;

  TimePoint lastUpdate = Clock::now();
  TimePoint lastFixedUpdate = Clock::now();

  // Setting up accumulator to ("discharge") for fixed update
  Clock::duration accumulator = Clock::duration::zero();
  std::chrono::duration<double, std::milli> slice(FIXED_UPDATE_MS);
  auto sliceDuration = std::chrono::duration_cast<Clock::duration>(slice);

  while (m_running) {
    // Calculating delta time
    if (m_window->ShouldClose()) {
      m_running = false;
    }

    TimePoint now = Clock::now();
    m_deltaTime =
        (float)std::chrono::duration_cast<Duration>(now - lastUpdate).count();
    lastUpdate +=
        std::chrono::duration_cast<Clock::duration>(Duration(m_deltaTime));
    accumulator +=
        std::chrono::duration_cast<Clock::duration>(Duration(m_deltaTime));

    while (accumulator > slice) {
      // Calculating fixed delta time
      TimePoint now = Clock::now();
      m_fixedDeltaTime =
          (float)std::chrono::duration_cast<Duration>(now - lastFixedUpdate)
              .count();
      lastFixedUpdate += std::chrono::duration_cast<Clock::duration>(
          Duration(m_fixedDeltaTime));

      // Do as many calculations to catch up
      accumulator -= sliceDuration;
    }
    m_window->PollEvents();
    m_window->SwapBuffers();
  }
}
} // namespace Aerin
