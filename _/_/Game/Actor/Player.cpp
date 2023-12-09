#include "Player.hpp"

#include "Input\\Keyboard.hpp"
#include "Time.hpp"

namespace NBEA::NGame::NActor
{    
    CPlayer::CPlayer(float ACoordinate , unsigned short AUp , unsigned short ADown)
    {
        FPolygon.PX(ACoordinate).PY(45.0F).PWidth(1.0F).PHeight(10.0F).PColor({1.0F , 1.0F , 1.0F , 1.0F}).PApply();
        FComponents.emplace_back(FPolygon);
        FUp = AUp;
        FDown = ADown;
    }

    float CPlayer::PX()
    {
        return FPolygon.PX();
    }

    float CPlayer::PY()
    {
        return FPolygon.PY();
    }

    float CPlayer::PWidth()
    {
        return FPolygon.PWidth();
    }

    float CPlayer::PHeight()
    {
        return FPolygon.PHeight();
    }

    void CPlayer::PUpdate()
    {
        if(NInput::GKeyboard.PHeld(FUp) && FPolygon.PY() - GTime.PRelative() / 10.0F >= 6.0F)
        {
            FPolygon.PY(FPolygon.PY() - GTime.PRelative() / 10.0F).PApply();
        }
        if(NInput::GKeyboard.PHeld(FDown) && FPolygon.PY() + GTime.PRelative() / 10.0F <= 84.0F)
        {
            FPolygon.PY(FPolygon.PY() + GTime.PRelative() / 10.0F).PApply();
        }
        CActor::PUpdate();
    }
}