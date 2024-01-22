#pragma once

#include "Engine.hpp"

namespace NBEA::NInput::NMouse
{
    inline class CButton
    {
        private:
            friend class CMouse;
        private:    
            bool VHeld[6];
            bool VPressed[6];
            bool VReleased[6];
        private:    
            void FUpdate(const SDL_Event& PEvent);
    }
    GButton;
}