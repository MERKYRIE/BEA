#pragma once

#include "Engine.hpp"

#include "Game\\Actor.hpp"
#include "Game\\Component\\Polygon.hpp"

namespace NBEA::NGame::NActor
{
    class CPlayer : public CActor
    {
        protected:
            NComponent::CPolygon FPolygon;
            unsigned short FUp;
            unsigned short FDown;
        public:
            CPlayer(float ACoordinate , unsigned short AUp , unsigned short ADown);
            virtual float PX();
            virtual float PY();
            virtual float PWidth();
            virtual float PHeight();
            virtual void PUpdate() override;
    };
}