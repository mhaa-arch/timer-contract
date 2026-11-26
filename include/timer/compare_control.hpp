#ifndef MHAA_TIMER_COMPARE_CONTROL_HPP
#define MHAA_TIMER_COMPARE_CONTROL_HPP

#include <timer/types.hpp>

namespace mhaa
{
    namespace timer
    {
        /** @brief Sets an optional comparison threshold in counter ticks. */
        class CompareControl
        {
        public:
            virtual ~CompareControl() = default;
            virtual bool set_compare(ChannelId channel, Count threshold) = 0;
        };
    }
}

#endif
