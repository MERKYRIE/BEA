#include "Time.hpp"

namespace NBEA
{
    void CTime::PUpdate()
    {
        FLast = FAbsolute;
        FAbsolute = SDL_GetTicks();
        FRelative = FAbsolute - FLast;
    }

    unsigned int CTime::PAbsolute()
    {
        return FAbsolute;
    }

    unsigned int CTime::PRelative()
    {
        return FRelative;
    }
}