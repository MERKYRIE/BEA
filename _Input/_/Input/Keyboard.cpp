#include "Keyboard.hpp"

namespace NBEA::NInput
{
    void CKeyboard::FUpdate(const SDL_Event& AEvent)
    {
        switch(AEvent.type)
        {
            case SDL_KEYDOWN:
                VHeld[AEvent.key.keysym.scancode] = true;
                if(!AEvent.key.repeat)
                {
                    VPressed[AEvent.key.keysym.scancode] = true;
                }
                VReleased[AEvent.key.keysym.scancode] = false;
            break;
            case SDL_KEYUP:
                VHeld[AEvent.key.keysym.scancode] = false;
                VPressed[AEvent.key.keysym.scancode] = false;
                if(!AEvent.key.repeat)
                {
                    VReleased[AEvent.key.keysym.scancode] = true;
                }
            break;
        }
    }

    bool CKeyboard::FHeld(unsigned short AKey)
    {
        return VHeld[AKey];
    }

    bool CKeyboard::FPressed(unsigned short AKey)
    {
        return VPressed[AKey];
    }

    bool CKeyboard::FReleased(unsigned short AKey)
    {
        return VReleased[AKey];
    }
}