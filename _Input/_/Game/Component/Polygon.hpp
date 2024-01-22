#pragma once

#include "Engine.hpp"

#include "Game\\Component.hpp"

namespace NBEA::NGame::NComponent
{
    class CPolygon : public CComponent
    {
        protected:
            float VX;
            float VY;
            float VWidth;
            float VHeight;
            std::array<float , 4> VColor;
            std::vector<std::array<float , 2>> VVertices;
            std::vector<unsigned int> VIndices;
        public:
            CPolygon();
            virtual float FX();
            virtual CPolygon& FX(float PX);
            virtual float FY();
            virtual CPolygon& FY(float PY);
            virtual float FWidth();
            virtual CPolygon& FWidth(float PWidth);
            virtual float FHeight();
            virtual CPolygon& FHeight(float PHeight);
            virtual std::array<float , 4> FColor();
            virtual CPolygon& FColor(const std::array<float , 4>& PColor);
            virtual CPolygon& FCorrectToWidth();
            virtual CPolygon& FCorrectToHeight();
            virtual CPolygon& FApply();
            virtual void FUpdate() override;
    };
}