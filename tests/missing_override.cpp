#include <timer/counter.hpp>

using namespace mhaa::timer;

class Incomplete final : public Counter
{
public:
    void start() override;
    void stop() override;
    Count value() const override;
    bool set_value(Count count) override;
};

int main()
{
    Incomplete implementation;
    (void)implementation;
}
