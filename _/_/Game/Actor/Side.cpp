#include "Side.hpp"

namespace NBEA::NGame::NActor
{    
    CSide::CSide(float ACoordinate)
    {
        FPolygon.PX(0.0F).PY(ACoordinate).PWidth(100.0F).PHeight(1.0F).PColor({0.5F , 0.5F , 0.5F , 1.0F}).PApply();
        FComponents.emplace_back(FPolygon);
    }
}