#pragma once

#include "Engine.hpp"

namespace NBEA::NGame
{
    class CComponent
    {
        public:
            virtual void PUpdate() = 0;
    };
}