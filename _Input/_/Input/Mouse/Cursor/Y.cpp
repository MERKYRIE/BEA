#include "Y.hpp"

namespace NBEA::NInput::NMouse::NCursor
{
    void CY::FUpdate(const SDL_Event& AEvent)
    {
        VAbsolute = AEvent.motion.y;
        VRelative = AEvent.motion.yrel;
        VChanged = VRelative;
    }
}