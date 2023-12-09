#include "X.hpp"

namespace NBEA::NInput::NMouse::NCursor
{
    void CX::PUpdate(const SDL_Event& AEvent)
    {
        FAbsolute = AEvent.motion.x;
        FRelative = AEvent.motion.xrel;
        FChanged = FRelative;
    }
}