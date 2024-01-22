#include "Button.hpp"

namespace NBEA::NInput::NMouse
{
    void CButton::FUpdate(const SDL_Event& AEvent)
    {
        switch(AEvent.type)
        {
            case SDL_MOUSEBUTTONDOWN:
                VHeld[AEvent.button.button - 1] = true;
                VPressed[AEvent.button.button - 1] = true;
                VReleased[AEvent.button.button - 1] = false;
            break;
            case SDL_MOUSEBUTTONUP:
                VHeld[AEvent.button.button - 1] = false;
                VPressed[AEvent.button.button - 1] = false;
                VReleased[AEvent.button.button - 1] = true;
            break;
        }
    }
}