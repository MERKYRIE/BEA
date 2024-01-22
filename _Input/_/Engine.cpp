#pragma comment(lib , "..\\GraphicsLibraryExtensionWrangler\\glew32.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2main.lib")
#pragma comment(lib , "..\\SimpleDirectMediaLayer\\sdl2_image.lib")
#pragma comment(lib , "opengl32.lib")
#pragma comment(lib , "glu32.lib")

#include "Engine.hpp"

#include "Debug.hpp"
#include "Game.hpp"
#include "Input.hpp"
#include "Input\\Keyboard.hpp"
#include "Time.hpp"
#include "Video.hpp"
#include "Video\\ShaderProgram.hpp"

namespace NBEA
{
    void CEngine::FInitiate()
    {
        while(!NInput::GKeyboard.FHeld(SDL_SCANCODE_ESCAPE))
        {
            GVideo.FBegin();
            GInput.FUpdate();
            GTime.FUpdate();
            GGame.FUpdate();
            GVideo.FEnd();
        }
    }

    CEngine::CEngine()
    {
        GDebug.FCode(SDL_Init(SDL_INIT_EVERYTHING));
        GInput.FInitialize();
        GVideo.FInitialize();
    }
    
    CEngine::~CEngine()
    {
        GVideo.FDeinitialize();
        SDL_Quit();
    }
}

signed int main(signed int , char**)
{
    NBEA::GEngine.FInitiate();
    return 0;
}