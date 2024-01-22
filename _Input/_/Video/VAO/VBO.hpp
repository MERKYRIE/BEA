#pragma once

#include "Engine.hpp"

namespace NBEA::NVideo
{
    inline class CVBO
    {
        private:
            friend class CVAO;
        private:
            unsigned int VIdentifier;
        private:
            void FInitialize();
        public:
            CVBO& FBuffer(const std::vector<std::array<float , 2>>& PVertices);
    }
    GVBO;
}