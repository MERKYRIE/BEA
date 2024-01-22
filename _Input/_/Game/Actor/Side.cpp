#include "Side.hpp"

namespace NBEA::NGame::NActor
{    
    CSide::CSide(float ACoordinate)
    {
        VPolygon.FX(0.0F).FY(ACoordinate).FWidth(100.0F).FHeight(1.0F).FColor({0.5F , 0.5F , 0.5F , 1.0F}).FApply();
        VComponents.emplace_back(VPolygon);
    }
}