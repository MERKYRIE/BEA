#pragma once

#include "Engine.hpp"

#include "Component.hpp"

namespace NBEA::NGame
{
    class CActor
    {
        protected:
            std::vector<std::reference_wrapper<CComponent>> VComponents;
        public:
            virtual void FUpdate();
    };
}