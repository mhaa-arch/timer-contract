#include <timer/counter.hpp>
#include <timer/clock_control.hpp>
#include <timer/compare_control.hpp>
#include <timer/input_capture.hpp>

#include <cassert>

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

class OptionalTimer final : public ClockControl, public CompareControl, public InputCapture
{
public:
    uint8_t width_bits() const override { return 24; }

    void start() override { running = true; }

    void stop() override { running = false; }

    Count value() const override { return current; }
    bool set_value(Count count) override
    {
        if (count > UINT32_C(0xFFFFFF))
        {
            return false;
        }
        current = count;
        return true;
    }

    bool set_tick_frequency_hz(uint32_t hz) override { return hz == 1000000; }

    bool set_compare(ChannelId channel, Count threshold) override
    {
        return channel == ChannelId{} && threshold <= UINT32_C(0xFFFFFF);
    }

    bool try_capture(Count &count) override
    {
        if (!available)
        {
            return false;
        }
        count = current;
        available = false;
        return true;
    }

    bool running = false;
    bool available = true;
    Count current = UINT32_C(0x123456);
};

int main()
{
    Fake basic(8);
    Counter &base = basic;
    assert(base.width_bits() == 8 && !base.set_value(256));
    OptionalTimer extended;
    ClockControl &clock = extended;
    CompareControl &compare = extended;
    InputCapture &capture = extended;
    assert(clock.set_tick_frequency_hz(1000000));
    assert(!compare.set_compare(static_cast<ChannelId>(1), 12));
    assert(compare.set_compare(ChannelId{}, 12));
    Count ticks = 0;
    assert(capture.try_capture(ticks) && ticks == UINT32_C(0x123456));
    assert(!capture.try_capture(ticks) && ticks == UINT32_C(0x123456));
}
