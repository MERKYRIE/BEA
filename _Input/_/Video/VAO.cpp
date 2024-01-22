#include "VAO.hpp"

#include "VAO\\VBO.hpp"
#include "VAO\\EBO.hpp"

#include "Debug.hpp"

namespace NBEA::NVideo
{
    void CVAO::FInitialize()
    {
        glGenVertexArrays(1 , &VIdentifier);  
        glBindVertexArray(VIdentifier);
        GVBO.FInitialize();
        GEBO.FInitialize();
        glVertexAttribPointer(0 , 2 , GL_FLOAT , GL_FALSE , 2 * sizeof(float) , reinterpret_cast<void*>(0 * sizeof(float)));
        glEnableVertexAttribArray(0);
        GDebug.FOGL();
    }
}