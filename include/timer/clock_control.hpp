#ifndef MHAA_TIMER_CLOCK_CONTROL_HPP
#define MHAA_TIMER_CLOCK_CONTROL_HPP

#include <stdint.h>
#include <timer/counter.hpp>
#include <timer/types.hpp>

namespace mhaa
{
    namespace timer
    {
        /** @brief Selects an internally clocked nominal tick rate. */
        class ClockControl : public Counter
        {
        public:
            virtual bool set_tick_frequency_hz(uint32_t frequency_hz) = 0;
        };
    }
}

#endif
