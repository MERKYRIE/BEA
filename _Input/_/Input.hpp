#pragma once

#include "Engine.hpp"

namespace NBEA
{
    inline class CInput
    {
        private:
            friend class CEngine;
        private:
            void FInitialize();
            void FUpdate();
    }
    GInput;
}