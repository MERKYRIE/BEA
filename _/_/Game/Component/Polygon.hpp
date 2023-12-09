#pragma once

#include "Engine.hpp"

#include "Game\\Component.hpp"

namespace NBEA::NGame::NComponent
{
    class CPolygon : public CComponent
    {
        protected:
            float FX;
            float FY;
            float FWidth;
            float FHeight;
            std::array<float , 4> FColor;
            std::vector<std::array<float , 2>> FVertices;
            std::vector<unsigned int> FIndices;
        public:
            CPolygon();
            virtual float PX();
            virtual CPolygon& PX(float AX);
            virtual float PY();
            virtual CPolygon& PY(float AY);
            virtual float PWidth();
            virtual CPolygon& PWidth(float AWidth);
            virtual float PHeight();
            virtual CPolygon& PHeight(float AHeight);
            virtual std::array<float , 4> PColor();
            virtual CPolygon& PColor(const std::array<float , 4>& AColor);
            virtual CPolygon& PCorrectToWidth();
            virtual CPolygon& PCorrectToHeight();
            virtual CPolygon& PApply();
            virtual void PUpdate() override;
    };
}