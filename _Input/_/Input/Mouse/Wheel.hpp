#pragma once

#include "Engine.hpp"

namespace NBEA::NInput::NMouse
{
    inline class CWheel
    {
        private:
            friend class CMouse;
        private:
            signed int VState;
            bool VChanged;
            bool VDown;
            bool VUp;
        private:
            void FUpdate(const SDL_Event& PEvent);
    }
    GWheel;
}