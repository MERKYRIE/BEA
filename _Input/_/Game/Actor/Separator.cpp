#include "Separator.hpp"

namespace NBEA::NGame::NActor
{    
    CSeparator::CSeparator()
    {
        static unsigned int LIndex{0};
        VPolygon.FX(49.5F).FY(5.5F + LIndex * 6.775F).FWidth(1.0F).FHeight(1.0F).FColor({0.5F , 0.5F , 0.5F , 1.0F}).FCorrectToHeight().FApply();
        LIndex++;
        VComponents.emplace_back(VPolygon);
    }
}