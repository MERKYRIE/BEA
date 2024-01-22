#include "Ball.hpp"

#include "Input\\Keyboard.hpp"
#include "Time.hpp"

namespace NBEA::NGame::NActor
{    
    CBall::CBall(const glm::vec2& ADirection) : VDirection{ADirection}
    {
        VPolygon.FWidth(1.0F).FHeight(1.0F).FColor({1.0F , 1.0F , 1.0F , 1.0F}).FCorrectToWidth().FX(6.0F).FY(50.0F - VPolygon.FHeight() / 2.0F).FApply();
        VComponents.emplace_back(VPolygon);
    }

    float CBall::FX()
    {
        return VPolygon.FX();
    }

    float CBall::FY()
    {
        return VPolygon.FY();
    }

    float CBall::FWidth()
    {
        return VPolygon.FWidth();
    }

    float CBall::FHeight()
    {
        return VPolygon.FHeight();
    }

    void CBall::FUpdate()
    {
        VPolygon.FX(VPolygon.FX() + VDirection[0] * GTime.FRelative() / 10.0F).FY(VPolygon.FY() + VDirection[1] * GTime.FRelative() / 10.0F).FApply();
        CActor::FUpdate();
    }
}