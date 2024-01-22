#include "Time.hpp"

namespace NBEA
{
    void CTime::FUpdate()
    {
        VLast = VAbsolute;
        VAbsolute = SDL_GetTicks();
        VRelative = VAbsolute - VLast;
    }

    unsigned int CTime::FAbsolute()
    {
        return VAbsolute;
    }

    unsigned int CTime::FRelative()
    {
        return VRelative;
    }
}