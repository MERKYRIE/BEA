#pragma once

#include "Engine.hpp"

namespace NBEA
{
    inline class CDebug
    {
        public:
            void FError(bool PCondition = true , const std::source_location& PLocation = std::source_location::current());
            bool FWarning(bool PCondition = true , const std::source_location& PLocation = std::source_location::current());
            void FCode(signed int PValue , const std::source_location& PLocation = std::source_location::current());
            void FHandle(const void* PPointer , const std::source_location& PLocation = std::source_location::current());
            void FFlags(signed int PValue , const std::source_location& PLocation = std::source_location::current());
            void FOGL(const std::source_location& PLocation = std::source_location::current());
    }
    GDebug;
}