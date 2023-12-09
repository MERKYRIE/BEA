#include "Ball.hpp"

#include "Input\\Keyboard.hpp"
#include "Time.hpp"

namespace NBEA::NGame::NActor
{    
    CBall::CBall(const glm::vec2& ADirection) : FDirection{ADirection}
    {
        FPolygon.PWidth(1.0F).PHeight(1.0F).PColor({1.0F , 1.0F , 1.0F , 1.0F}).PCorrectToWidth().PX(6.0F).PY(50.0F - FPolygon.PHeight() / 2.0F).PApply();
        FComponents.emplace_back(FPolygon);
    }

    float CBall::PX()
    {
        return FPolygon.PX();
    }

    float CBall::PY()
    {
        return FPolygon.PY();
    }

    float CBall::PWidth()
    {
        return FPolygon.PWidth();
    }

    float CBall::PHeight()
    {
        return FPolygon.PHeight();
    }

    void CBall::PUpdate()
    {
        FPolygon.PX(FPolygon.PX() + FDirection[0] * GTime.PRelative() / 10.0F).PY(FPolygon.PY() + FDirection[1] * GTime.PRelative() / 10.0F).PApply();
        CActor::PUpdate();
    }
}