#include "Wheel.hpp"

namespace NBEA::NInput::NMouse
{
    void CWheel::FUpdate(const SDL_Event& AEvent)
    {
        switch(AEvent.wheel.y)
        {
            case -1:
                VState = AEvent.wheel.y;
                VChanged = true;
                VDown = true;
                VUp = false;
            break;
            case 0:
                VState = AEvent.wheel.y;
                VChanged = false;
                VDown = false;
                VUp = false;
            break;
            case +1:
                VState = AEvent.wheel.y;
                VChanged = true;
                VDown = false;
                VUp = true;
            break;
        }
    }
}