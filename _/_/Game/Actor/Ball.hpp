#pragma once

#include "Engine.hpp"

#include "Game\\Actor.hpp"
#include "Game\\Component\\Polygon.hpp"

namespace NBEA::NGame::NActor
{
    class CBall : public CActor
    {
        protected:
            NComponent::CPolygon FPolygon;
            const glm::vec2& FDirection;
        public:
            CBall(const glm::vec2& ADirection);
            virtual float PX();
            virtual float PY();
            virtual float PWidth();
            virtual float PHeight();
            virtual void PUpdate() override;
    };
}