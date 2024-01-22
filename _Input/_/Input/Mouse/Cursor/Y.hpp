#pragma once

#include "Engine.hpp"

namespace NBEA::NInput::NMouse::NCursor
{
    inline class CY
    {
        private:
            friend class CCursor;
        private:    
            signed int VAbsolute;
            signed int VRelative;
            bool VChanged;
        private:    
            void FUpdate(const SDL_Event& PEvent);
    }
    GY;
}