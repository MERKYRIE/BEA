#pragma once

#include "Engine.hpp"

namespace NBEA::NVideo
{
    inline class CShaderProgram
    {
        private:
            friend class CVideo;
        private:
            unsigned int VIdentifier;
        private:
            void FInitialize();
            void FUpdate();
        public:
            CShaderProgram& FColor(const std::array<float , 4> PColor);
    }
    GShaderProgram;
}