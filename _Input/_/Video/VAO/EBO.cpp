#include "EBO.hpp"

#include "Debug.hpp"

namespace NBEA::NVideo
{
    void CEBO::FInitialize()
    {
        glGenBuffers(1 , &VIdentifier);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , VIdentifier);
        GDebug.FOGL();
    }

    CEBO& CEBO::FBuffer(const std::vector<unsigned int>& AIndices)
    {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER , AIndices.size() * sizeof(unsigned int) , AIndices.data() , GL_STATIC_DRAW);
        return *this;
    }
}