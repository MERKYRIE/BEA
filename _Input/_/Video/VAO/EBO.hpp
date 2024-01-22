#pragma once

#include "Engine.hpp"

namespace NBEA::NVideo
{
    inline class CEBO
    {
        private:
            friend class CVAO;
        private:
            unsigned int VIdentifier;
        private:
            void FInitialize();
        public:
            CEBO& FBuffer(const std::vector<unsigned int>& PIndices);
    }
    GEBO;
}