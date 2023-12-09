#pragma once

#include "Engine.hpp"

namespace NBEA::NVideo
{
    inline class CEBO
    {
        private:
            friend class CVAO;
        private:
            unsigned int FIdentifier;
        private:
            void PInitialize();
        public:
            CEBO& PBuffer(const std::vector<unsigned int>& AIndices);
    }
    GEBO;
}