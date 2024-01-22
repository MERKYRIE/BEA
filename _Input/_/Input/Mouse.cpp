#include "Mouse.hpp"

#include "Mouse\\Button.hpp"
#include "Mouse\\Cursor.hpp"
#include "Mouse\\Wheel.hpp"

namespace NBEA::NInput
{
    void CMouse::FInitialize()
    {
        NMouse::GCursor.FInitialize();
    }

    void CMouse::FUpdate(const SDL_Event& AEvent)
    {
        switch(AEvent.type)
        {
            case SDL_MOUSEMOTION:
                NMouse::GCursor.FUpdate(AEvent);
            break;
            case SDL_MOUSEBUTTONDOWN:
                NMouse::GButton.FUpdate(AEvent);
                VPressedX[AEvent.button.button - 1] = AEvent.button.x;
                VPressedY[AEvent.button.button - 1] = AEvent.button.y;
            break;
            case SDL_MOUSEBUTTONUP:
                NMouse::GButton.FUpdate(AEvent);
                VReleasedX[AEvent.button.button - 1] = AEvent.button.x;
                VReleasedY[AEvent.button.button - 1] = AEvent.button.y;
            break;
            case SDL_MOUSEWHEEL:
                NMouse::GWheel.FUpdate(AEvent);
            break;
        }
    }
}