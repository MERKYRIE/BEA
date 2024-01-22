#include "VBO.hpp"

#include "Debug.hpp"

namespace NBEA::NVideo
{
    void CVBO::FInitialize()
    {
        glGenBuffers(1 , &VIdentifier);
        glBindBuffer(GL_ARRAY_BUFFER , VIdentifier);
        GDebug.FOGL();
    }

    CVBO& CVBO::FBuffer(const std::vector<std::array<float , 2>>& AVertices)
    {
        glBufferData(GL_ARRAY_BUFFER , AVertices.size() * sizeof(std::array<float , 2>) , AVertices.data() , GL_STATIC_DRAW);
        return *this;
    }
}