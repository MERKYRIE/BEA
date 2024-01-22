#pragma once

#include "Engine.hpp"

#include "Game\\Actor.hpp"
#include "Game\\Component\\Polygon.hpp"

namespace NBEA::NGame::NActor
{
    class CSide : public CActor
    {
        protected:
            NComponent::CPolygon VPolygon;
        public:
            CSide(float PCoordinate);
    };
}