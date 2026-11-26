# Timer Contract example

[The conformance program](../tests/conformance.cpp) pairs a simulated implementation with assertions at the Contract boundary. The base fake is eight bits wide and rejects a write of 256. A second fixture implements optional clock, compare and capture interfaces independently. The test rejects an unmapped compare channel, accepts a known threshold, consumes one capture, then confirms that an empty capture leaves the timestamp unchanged.

## Implementation excerpt

This class is taken from the program. The linked source contains the test cases and any additional fixtures.

```cpp
#include <timer/counter.hpp>
#include <timer/clock_control.hpp>
#include <timer/compare_control.hpp>
#include <timer/input_capture.hpp>


using namespace mhaa::timer;

class Fake final : public Counter
{
public:
    explicit Fake(uint8_t width) : width_(width) {}

    uint8_t width_bits() const override { return width_; }

    void start() override { running = true; }

    void stop() override { running = false; }

    Count value() const override { return count_; }

    bool set_value(Count count) override
    {
        if (width_ < 32 && count >= (Count{1} << width_))
        {
            return false;
        }
        count_ = count;
        return true;
    }

    bool running = false;

private:
    uint8_t width_;
    Count count_ = 0;
};
```

## Build and run

From this repository root, with assertions enabled, compile the full program. A passing run exits with status 0 and prints no output. Use `conformance.exe` on Windows.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude tests/conformance.cpp -o conformance
./conformance
```

To verify enforcement of the abstract interface, compile the two negative sources separately. The first should diagnose an abstract type and the second an incompatible override.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/missing_override.cpp
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/wrong_override.cpp
```
