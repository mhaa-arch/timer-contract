#ifndef MHAA_TIMER_COUNTER_HPP
#define MHAA_TIMER_COUNTER_HPP

#include <stdint.h>
#include <timer/types.hpp>

namespace mhaa
{
    namespace timer
    {
        /** @brief An up counter that wraps in native-width ticks. */
        class Counter
        {
        public:
            virtual ~Counter() = default;
            virtual uint8_t width_bits() const = 0;
            virtual void start() = 0;
            virtual void stop() = 0;
            virtual Count value() const = 0;

            /** @brief Sets the count when supported. Rejection leaves the count unmodified by the call. */
            virtual bool set_value(Count count) = 0;
        };
    }
}

#endif
