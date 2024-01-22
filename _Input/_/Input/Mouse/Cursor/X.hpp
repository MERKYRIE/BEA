#pragma once

#include "Engine.hpp"

namespace NBEA::NInput::NMouse::NCursor
{
    inline class CX
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
    GX;
}