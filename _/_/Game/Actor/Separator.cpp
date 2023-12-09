#include "Separator.hpp"

namespace NBEA::NGame::NActor
{    
    CSeparator::CSeparator()
    {
        static unsigned int LIndex{0};
        FPolygon.PX(49.5F).PY(5.5F + LIndex * 6.775F).PWidth(1.0F).PHeight(1.0F).PColor({0.5F , 0.5F , 0.5F , 1.0F}).PCorrectToHeight().PApply();
        LIndex++;
        FComponents.emplace_back(FPolygon);
    }
}