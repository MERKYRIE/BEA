#include "Player.hpp"

#include "Input\\Keyboard.hpp"
#include "Time.hpp"

namespace NBEA::NGame::NActor
{    
    CPlayer::CPlayer(float ACoordinate , unsigned short AUp , unsigned short ADown)
    {
        VPolygon.FX(ACoordinate).FY(45.0F).FWidth(1.0F).FHeight(10.0F).FColor({1.0F , 1.0F , 1.0F , 1.0F}).FApply();
        VComponents.emplace_back(VPolygon);
        VUp = AUp;
        VDown = ADown;
    }

    float CPlayer::FX()
    {
        return VPolygon.FX();
    }

    float CPlayer::FY()
    {
        return VPolygon.FY();
    }

    float CPlayer::FWidth()
    {
        return VPolygon.FWidth();
    }

    float CPlayer::FHeight()
    {
        return VPolygon.FHeight();
    }

    void CPlayer::FUpdate()
    {
        if(NInput::GKeyboard.FHeld(VUp) && VPolygon.FY() - GTime.FRelative() / 10.0F >= 6.0F)
        {
            VPolygon.FY(VPolygon.FY() - GTime.FRelative() / 10.0F).FApply();
        }
        if(NInput::GKeyboard.FHeld(VDown) && VPolygon.FY() + GTime.FRelative() / 10.0F <= 84.0F)
        {
            VPolygon.FY(VPolygon.FY() + GTime.FRelative() / 10.0F).FApply();
        }
        CActor::FUpdate();
    }
}