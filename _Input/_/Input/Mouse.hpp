#pragma once

#include "Engine.hpp"

namespace NBEA::NInput
{
    inline class CMouse
    {
        private:
            friend class CInput;
        private:    
            signed int VPressedX[6];
            signed int VPressedY[6];
            signed int VReleasedX[6];
            signed int VReleasedY[6];
        private:    
            void FInitialize();
            void FUpdate(const SDL_Event& PEvent);
    }
    GMouse;
}