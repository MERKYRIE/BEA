#include "Game.hpp"

#include "Input\\Keyboard.hpp"
#include "Time.hpp"

namespace NBEA
{
    CGame::CGame() :
        VUpper{5.0F} ,
        VLower{94.0F} ,
        VPlayers{NGame::NActor::CPlayer{5.0F , SDL_SCANCODE_W , SDL_SCANCODE_S} , NGame::NActor::CPlayer{94.0F , SDL_SCANCODE_UP , SDL_SCANCODE_DOWN}} ,
        VBall{VDirection}
    {
        VActors.emplace_back(VUpper);
        VActors.emplace_back(VLower);
        for(unsigned int LSeparator{0} ; LSeparator < VSeparators.size() ; LSeparator++)
        {
            VActors.emplace_back(VSeparators[LSeparator]);
        }
        VActors.emplace_back(VPlayers[0]);
        VActors.emplace_back(VPlayers[1]);
        VActors.emplace_back(VBall);
        VDirection = {1.0F , 0.0F};
    }

    void CGame::FUpdate()
    {
        if(SDL_HasIntersectionF
        (
            std::unique_ptr<SDL_FRect>{std::make_unique<SDL_FRect>(VPlayers[0].FX() , VPlayers[0].FY() , VPlayers[0].FWidth() , VPlayers[0].FHeight())}.get() ,
            std::unique_ptr<SDL_FRect>{std::make_unique<SDL_FRect>(VBall.FX() , VBall.FY() , VBall.FWidth() , VBall.FHeight())}.get()
        ))
        {
            VDirection = glm::clamp
            (
                glm::normalize(glm::vec2{1.0F , ((VBall.FY() + VBall.FHeight() / 2.0F + VPlayers[0].FY() + VPlayers[0].FHeight()) / 2.0F - VPlayers[0].FY()) / VPlayers[0].FHeight() - 0.75F}) ,
                glm::normalize(glm::vec2{94.5F - VBall.FX() , 7.0F - VBall.FY()}) ,
                glm::normalize(glm::vec2{94.5F - VBall.FX() , 92.0F - VBall.FY()})
            );
        }
        if(SDL_HasIntersectionF
        (
            std::unique_ptr<SDL_FRect>{std::make_unique<SDL_FRect>(VPlayers[1].FX() , VPlayers[1].FY() , VPlayers[1].FWidth() , VPlayers[1].FHeight())}.get() ,
            std::unique_ptr<SDL_FRect>{std::make_unique<SDL_FRect>(VBall.FX() , VBall.FY() , VBall.FWidth() , VBall.FHeight())}.get()
        ))
        {
            VDirection = glm::clamp
            (
                glm::normalize(glm::vec2{-1.0F , ((VBall.FY() + VBall.FHeight() / 2.0F + VPlayers[1].FY() + VPlayers[1].FHeight()) / 2.0F - VPlayers[1].FY()) / VPlayers[1].FHeight() - 0.75F}) ,
                glm::normalize(glm::vec2{5.5F - VBall.FX() , 7.0F - VBall.FY()}) ,
                glm::normalize(glm::vec2{5.5F - VBall.FX() , 92.0F - VBall.FY()})
            );
        }
        for(std::reference_wrapper<NGame::CActor>& LActor : VActors)
        {
            LActor.get().FUpdate();
        }
    }
}