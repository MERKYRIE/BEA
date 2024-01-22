#pragma once

#include "Engine.hpp"

namespace NBEA::NInput
{
    inline class CKeyboard
    {
        private:
            friend class CInput;
        private:    
            unsigned char VHeld[291];
            unsigned char VPressed[291];
            unsigned char VReleased[291];
        private:    
            void FUpdate(const SDL_Event& PEvent);
        public:
            bool FHeld(unsigned short PKey);
            bool FPressed(unsigned short PKey);
            bool FReleased(unsigned short PKey);
    }
    GKeyboard;
}