#pragma once

#include "Engine.hpp"

namespace NBEA::NVideo
{
    class CPolygon
    {
        private:
            float VX;
            float VY;
            float VWidth;
            float VHeight;
            std::array<float , 4> VColor;
            std::vector<std::array<float , 2>> VVertices;
            std::vector<unsigned int> VIndices;
        public:
            CPolygon();
            float FX();
            CPolygon& FX(float PX);
            float FY();
            CPolygon& FY(float PY);
            float FWidth();
            CPolygon& FWidth(float PWidth);
            float FHeight();
            CPolygon& FHeight(float PHeight);
            std::array<float , 4> FColor();
            CPolygon& FColor(const std::array<float , 4>& PColor);
            CPolygon& FCorrectToWidth();
            CPolygon& FCorrectToHeight();
            CPolygon& FUpdate();
            CPolygon& FRender();
    };
}