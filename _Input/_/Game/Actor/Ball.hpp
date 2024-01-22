#pragma once

#include "Engine.hpp"

#include "Game\\Actor.hpp"
#include "Game\\Component\\Polygon.hpp"

namespace NBEA::NGame::NActor
{
    class CBall : public CActor
    {
        protected:
            NComponent::CPolygon VPolygon;
            const glm::vec2& VDirection;
        public:
            CBall(const glm::vec2& PDirection);
            virtual float FX();
            virtual float FY();
            virtual float FWidth();
            virtual float FHeight();
            virtual void FUpdate() override;
    };
}