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
            std::vector<std::reference_wrapper<NGame::CActor>> VActors;
            NGame::NActor::CSide VUpper;
            NGame::NActor::CSide VLower;
            std::array<NGame::NActor::CSeparator , 14> VSeparators;
            std::array<NGame::NActor::CPlayer , 2> VPlayers;
            NGame::NActor::CBall VBall;
            glm::vec2 VDirection;
        public:
            CGame();
            void FUpdate();
    }
    GGame;
}