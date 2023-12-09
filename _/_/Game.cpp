#include "Game.hpp"

#include "Input\\Keyboard.hpp"
#include "Time.hpp"

namespace NBEA
{
    CGame::CGame() :
        FUpper{5.0F} ,
        FLower{94.0F} ,
        FPlayers{NGame::NActor::CPlayer{5.0F , SDL_SCANCODE_W , SDL_SCANCODE_S} , NGame::NActor::CPlayer{94.0F , SDL_SCANCODE_UP , SDL_SCANCODE_DOWN}} ,
        FBall{FDirection}
    {
        FActors.emplace_back(FUpper);
        FActors.emplace_back(FLower);
        for(unsigned int LSeparator{0} ; LSeparator < FSeparators.size() ; LSeparator++)
        {
            FActors.emplace_back(FSeparators[LSeparator]);
        }
        FActors.emplace_back(FPlayers[0]);
        FActors.emplace_back(FPlayers[1]);
        FActors.emplace_back(FBall);
        FDirection = {1.0F , 0.0F};
    }

    void CGame::PUpdate()
    {
        if(SDL_HasIntersectionF
        (
            std::unique_ptr<SDL_FRect>{std::make_unique<SDL_FRect>(FPlayers[0].PX() , FPlayers[0].PY() , FPlayers[0].PWidth() , FPlayers[0].PHeight())}.get() ,
            std::unique_ptr<SDL_FRect>{std::make_unique<SDL_FRect>(FBall.PX() , FBall.PY() , FBall.PWidth() , FBall.PHeight())}.get()
        ))
        {
            FDirection = glm::clamp
            (
                glm::normalize(glm::vec2{1.0F , ((FBall.PY() + FBall.PHeight() / 2.0F + FPlayers[0].PY() + FPlayers[0].PHeight()) / 2.0F - FPlayers[0].PY()) / FPlayers[0].PHeight() - 0.75F}) ,
                glm::normalize(glm::vec2{94.5F - FBall.PX() , 7.0F - FBall.PY()}) ,
                glm::normalize(glm::vec2{94.5F - FBall.PX() , 92.0F - FBall.PY()})
            );
        }
        if(SDL_HasIntersectionF
        (
            std::unique_ptr<SDL_FRect>{std::make_unique<SDL_FRect>(FPlayers[1].PX() , FPlayers[1].PY() , FPlayers[1].PWidth() , FPlayers[1].PHeight())}.get() ,
            std::unique_ptr<SDL_FRect>{std::make_unique<SDL_FRect>(FBall.PX() , FBall.PY() , FBall.PWidth() , FBall.PHeight())}.get()
        ))
        {
            FDirection = glm::clamp
            (
                glm::normalize(glm::vec2{-1.0F , ((FBall.PY() + FBall.PHeight() / 2.0F + FPlayers[1].PY() + FPlayers[1].PHeight()) / 2.0F - FPlayers[1].PY()) / FPlayers[1].PHeight() - 0.75F}) ,
                glm::normalize(glm::vec2{5.5F - FBall.PX() , 7.0F - FBall.PY()}) ,
                glm::normalize(glm::vec2{5.5F - FBall.PX() , 92.0F - FBall.PY()})
            );
        }
        for(std::reference_wrapper<NGame::CActor>& LActor : FActors)
        {
            LActor.get().PUpdate();
        }
    }
}