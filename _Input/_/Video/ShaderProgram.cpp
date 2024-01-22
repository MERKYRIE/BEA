#include "ShaderProgram.hpp"

#include "Debug.hpp"
#include "Time.hpp"

namespace NBEA::NVideo
{
    void CShaderProgram::FInitialize()
    {
        VIdentifier = glCreateProgram();
        for(const auto& LShader : std::vector<std::tuple<std::string , unsigned int>>{{"Shaders\\Vertex.glsl" , GL_VERTEX_SHADER} , {"Shaders\\Fragment.glsl" , GL_FRAGMENT_SHADER}})
        {
            std::ifstream LShaderFileStream{std::get<0>(LShader)};
            GDebug.FError(!LShaderFileStream);
            std::ostringstream LShaderStringStream;
            LShaderStringStream << LShaderFileStream.rdbuf();
            std::string LShaderString{LShaderStringStream.str()};
            const char* LShaderPointer{LShaderString.c_str()};
            unsigned int LShaderIdentifier{glCreateShader(std::get<1>(LShader))};
            glShaderSource(LShaderIdentifier , 1 , &LShaderPointer , nullptr);
            glCompileShader(LShaderIdentifier);
            glAttachShader(VIdentifier , LShaderIdentifier);
            glDeleteShader(LShaderIdentifier);
        }
        glLinkProgram(VIdentifier);
        glUseProgram(VIdentifier);
        GDebug.FOGL();
    }

    void CShaderProgram::FUpdate()
    {
        static glm::mat4 LProjection{glm::ortho(0.0F , 100.0F , 100.0F , 0.0F)};
        static signed int LProjectionLocation{glGetUniformLocation(VIdentifier , "UProjection")};
        glUniformMatrix4fv(LProjectionLocation , 1 , GL_FALSE , &LProjection[0][0]);
        static glm::mat4 LView{1.0F};
        static signed int LViewLocation{glGetUniformLocation(VIdentifier , "UView")};
        glUniformMatrix4fv(LViewLocation , 1 , GL_FALSE , &LView[0][0]);
        static glm::mat4 LModel{1.0F};
        static signed int LModelLocation{glGetUniformLocation(VIdentifier , "UModel")};
        glUniformMatrix4fv(LModelLocation , 1 , GL_FALSE , &LModel[0][0]);
    }

    CShaderProgram& CShaderProgram::FColor(const std::array<float , 4> AColor)
    {
        static signed int LColor{glGetUniformLocation(VIdentifier , "UColor")};
        glUniform4fv(LColor , 1 , AColor.data());
        return *this;
    }
}