#pragma once

#include "Engine.hpp"

namespace NBEA
{
    inline class CVideo
    {
        private:
            friend class CEngine;
        private:
            SDL_Window* VWindow;
            SDL_GLContext VContext;
            signed int VWidth;
            signed int VHeight;
            float VRatio;
            float VInversedRatio;
            signed int VProportionalWidth;
            signed int VProportionalHeight;
        private:
            void FInitialize();
            void FBegin();
            void FEnd();
            void FDeinitialize();
        public:
            signed int FWidth();
            signed int FHeight();
            float FRatio();
            float FInversedRatio();
            signed int FProportionalWidth();
            signed int FProportionalHeight();
    }
    GVideo;
}