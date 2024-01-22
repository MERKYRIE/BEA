#pragma once

#include "Engine.hpp"

namespace NBEA
{
    inline class CTime
    {
        private:
            friend class CEngine;
        private:
            unsigned int VLast;
            unsigned int VAbsolute;
            unsigned int VRelative;
        private:
            void FUpdate();
        public:
            unsigned int FAbsolute();
            unsigned int FRelative();
    }
    GTime;
}