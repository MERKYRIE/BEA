#pragma once

#include "Engine.hpp"

namespace NBEA::NInput::NMouse
{
    inline class CCursor
    {
        private:
            friend class CMouse;
        private:    
            void FInitialize();
            void FUpdate(const SDL_Event& PEvent);
    }
    GCursor;
}