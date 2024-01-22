#pragma once

#include "Engine.hpp"

namespace NBEA::NGame
{
    class CComponent
    {
        public:
            virtual void FUpdate() = 0;
    };
}