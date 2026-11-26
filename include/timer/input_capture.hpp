#ifndef MHAA_TIMER_INPUT_CAPTURE_HPP
#define MHAA_TIMER_INPUT_CAPTURE_HPP

#include <timer/types.hpp>

namespace mhaa
{
    namespace timer
    {
        /** @brief Consumes timestamps captured by an optional input event. */
        class InputCapture
        {
        public:
            virtual ~InputCapture() = default;

            /** @brief Returns immediately and preserves count if no capture is ready. */
            virtual bool try_capture(Count &count) = 0;
        };
    }
}

#endif
