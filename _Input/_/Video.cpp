#include "Video.hpp"

#include "Debug.hpp"
#include "Video\\ShaderProgram.hpp"
#include "Video\\VAO.hpp"

namespace NBEA
{
    void CVideo::FInitialize()
    {
        GDebug.FCode(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION , 4));
        GDebug.FCode(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION , 6));
        GDebug.FCode(SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS , 1));
        GDebug.FCode(SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES , 8));
        GDebug.FHandle(VWindow = SDL_CreateWindow("BCG" , 0 , 0 , 0 , 0 , SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL));
        GDebug.FHandle(VContext = SDL_GL_CreateContext(VWindow));
        if(GDebug.FWarning(SDL_GL_SetSwapInterval(0) < 0))
        {
            if(GDebug.FWarning(SDL_GL_SetSwapInterval(1) < 0))
            {
                GDebug.FWarning(SDL_GL_SetSwapInterval(-1) < 0);
            }
        }
        SDL_DisplayMode LMode;
        SDL_GetWindowDisplayMode(VWindow , &LMode);
        VWidth = LMode.w;
        VHeight = LMode.h;
        VRatio = static_cast<float>(VWidth) / static_cast<float>(VHeight);
        VInversedRatio = static_cast<float>(VHeight) / static_cast<float>(VWidth);
        for(signed int LMultiplier{2} ; LMultiplier <= 100 ; LMultiplier++)
        {
            if(std::abs(VRatio * LMultiplier - std::round(VRatio * LMultiplier)) <= 0.1F)
            {
                VProportionalWidth = static_cast<signed int>(std::round(VRatio * LMultiplier));
                VProportionalHeight = LMultiplier;
                break;
            }
        }
        GDebug.FFlags(IMG_Init(IMG_INIT_PNG));
        glewInit();
        glEnable(GL_MULTISAMPLE);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA);
        GDebug.FOGL();
        NVideo::GShaderProgram.FInitialize();
        NVideo::GVAO.FInitialize();
    }

    void CVideo::FBegin()
    {
        glClearColor(0.0F , 0.0F , 0.0F , 1.0F);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        NVideo::GShaderProgram.FUpdate();
    }

    void CVideo::FEnd()
    {
        SDL_GL_SwapWindow(VWindow);
    }

    void CVideo::FDeinitialize()
    {
        IMG_Quit();
        SDL_GL_DeleteContext(VContext);
        SDL_DestroyWindow(VWindow);
    }

    signed int CVideo::FWidth()
    {
        return VWidth;
    }

    signed int CVideo::FHeight()
    {
        return VHeight;
    }

    float CVideo::FRatio()
    {
        return VRatio;
    }

    float CVideo::FInversedRatio()
    {
        return VInversedRatio;
    }

    signed int CVideo::FProportionalWidth()
    {
        return VProportionalWidth;
    }

    signed int CVideo::FProportionalHeight()
    {
        return VProportionalHeight;
    }
}