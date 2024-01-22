#pragma once

#include "Engine.hpp"

#include "Game\\Actor.hpp"
#include "Game\\Component\\Polygon.hpp"

namespace NBEA::NGame::NActor
{
    class CPlayer : public CActor
    {
        protected:
            NComponent::CPolygon VPolygon;
            unsigned short VUp;
            unsigned short VDown;
        public:
            CPlayer(float PCoordinate , unsigned short PUp , unsigned short PDown);
            virtual float FX();
            virtual float FY();
            virtual float FWidth();
            virtual float FHeight();
            virtual void FUpdate() override;
    };
}