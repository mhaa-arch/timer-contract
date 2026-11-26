# Timer contract

## Base counter

[Counter](../include/timer/counter.hpp) provides 1 to 32 unsigned bits. Count increments in ticks and wraps to zero after the maximum value. Start resumes and stop pauses without implicitly resetting the count. `set_value` may reject an unsupported or out-of-range value and leaves the count unmodified by that call on rejection.

## Add capabilities individually

- [ClockControl](../include/timer/clock_control.hpp) extends the same counter and accepts a supported positive nominal tick rate in hertz for an internally clocked mode.
- [CompareControl](../include/timer/compare_control.hpp) accepts a counter-local channel and a threshold in ticks. Configuring it does not change the base counter modulus.
- [InputCapture](../include/timer/input_capture.hpp) supplies the last available event timestamp. Reading it consumes availability. An empty poll returns false and preserves the output.

## Implementation boundary

The Adapter owns resource state. The caller must keep the implementation alive during each call and arrange access from other execution contexts. Document the contexts and concurrency guarantees of the actual implementation. Shared public types are in [`timer/types.hpp`](../include/timer/types.hpp).
