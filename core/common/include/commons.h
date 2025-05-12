#ifndef CRACKITOS_PHYSICS_COMMON_COMMONS_H_
#define CRACKITOS_PHYSICS_COMMON_COMMONS_H_
#include "dmath/gamefloat/ieee_float_inline_asm.h"

namespace crackitos_core::commons
{
    // using fp = sixit::dmath::ieee_float_inline_asm;
    using fp = float;
    constexpr static fp kPi = 3.14159265358979323846f;
    constexpr static fp kEpsilon = 0.000001f;


    template <typename T>
    [[nodiscard]] constexpr bool Approx(T value, T target)
    {
        return abs(value - target) <= kEpsilon;
    }
} // namespace commons
#endif // CRACKITOS_PHYSICS_COMMON_COMMONS_H_
