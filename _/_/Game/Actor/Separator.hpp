#pragma once

#include "Engine.hpp"

#include "Game\\Actor.hpp"
#include "Game\\Component\\Polygon.hpp"

namespace NBEA::NGame::NActor
{
    class CSeparator : public CActor
    {
        protected:
            NComponent::CPolygon FPolygon;
        public:
            CSeparator();
    };
}