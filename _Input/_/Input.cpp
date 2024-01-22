#include "Input.hpp"

#include "Input\\Keyboard.hpp"
#include "Input\\Mouse.hpp"

namespace NBEA
{
    void CInput::FInitialize()
    {
        NInput::GMouse.FInitialize();
    }

    void CInput::FUpdate()
    {
        SDL_Event LEvent;
        while(SDL_PollEvent(&LEvent))
        {
            switch(LEvent.type)
            {
                case SDL_KEYDOWN:
                    NInput::GKeyboard.FUpdate(LEvent);
                break;
                case SDL_KEYUP:
                    NInput::GKeyboard.FUpdate(LEvent);
                break;
                case SDL_MOUSEMOTION:
                    NInput::GMouse.FUpdate(LEvent);
                break;
                case SDL_MOUSEBUTTONDOWN:
                    NInput::GMouse.FUpdate(LEvent);
                break;
                case SDL_MOUSEBUTTONUP:
                    NInput::GMouse.FUpdate(LEvent);
                break;
                case SDL_MOUSEWHEEL:
                    NInput::GMouse.FUpdate(LEvent);
                break;
            }
        }
    }
}