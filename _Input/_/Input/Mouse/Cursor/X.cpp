#include "X.hpp"

namespace NBEA::NInput::NMouse::NCursor
{
    void CX::FUpdate(const SDL_Event& AEvent)
    {
        VAbsolute = AEvent.motion.x;
        VRelative = AEvent.motion.xrel;
        VChanged = VRelative;
    }
}