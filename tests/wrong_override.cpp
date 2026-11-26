#include <timer/counter.hpp>

using namespace mhaa::timer;

class WrongOverride final : public Counter
{
public:
    uint8_t width_bits() override;
};
