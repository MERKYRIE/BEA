#pragma once

#include "Engine.hpp"

#include "Game\\Actor\\Ball.hpp"
#include "Game\\Actor\\Player.hpp"
#include "Game\\Actor\\Separator.hpp"
#include "Game\\Actor\\Side.hpp"
#include "Video\\Polygon.hpp"

namespace NBEA
{
    inline class CGame
    {    
        private:
            friend class CEngine;
        private:
            std::vector<std::reference_wrapper<NGame::CActor>> FActors;
            NGame::NActor::CSide FUpper;
            NGame::NActor::CSide FLower;
            std::array<NGame::NActor::CSeparator , 14> FSeparators;
            std::array<NGame::NActor::CPlayer , 2> FPlayers;
            NGame::NActor::CBall FBall;
            glm::vec2 FDirection;
        public:
            CGame();
            void PUpdate();
    }
    GGame;
}