#include "Cursor.hpp"

#include "Cursor\\X.hpp"
#include "Cursor\\Y.hpp"

namespace NBEA::NInput::NMouse
{
    void CCursor::FInitialize()
    {
        SDL_ShowCursor(SDL_DISABLE);
        SDL_WarpMouseInWindow(nullptr , 0 , 0);
    }

    void CCursor::FUpdate(const SDL_Event& AEvent)
    {
        NCursor::GX.FUpdate(AEvent);
        NCursor::GY.FUpdate(AEvent);
    }
}