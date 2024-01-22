#include "Polygon.hpp"

#include "ShaderProgram.hpp"
#include "VAO\\VBO.hpp"
#include "VAO\\EBO.hpp"

#include "Debug.hpp"
#include "Video.hpp"

namespace NBEA::NVideo
{
    CPolygon::CPolygon()
    {
        VVertices = {{0.0F , 0.0F} , {0.0F , 0.0F} , {0.0F , 0.0F} , {0.0F , 0.0F}};
        VIndices = {0 , 1 , 2 , 2 , 3 , 0};
        VColor = {0.0F , 0.0F , 0.0F , 0.0F};
    }

    float CPolygon::FX()
    {
        return VX;
    }

    CPolygon& CPolygon::FX(float AX)
    {
        VX = AX;
        return *this;
    }

    float CPolygon::FY()
    {
        return VY;
    }

    CPolygon& CPolygon::FY(float AY)
    {
        VY = AY;
        return *this;
    }

    float CPolygon::FWidth()
    {
        return VWidth;
    }

    CPolygon& CPolygon::FWidth(float AWidth)
    {
        VWidth = AWidth;
        return *this;
    }

    float CPolygon::FHeight()
    {
        return VHeight;
    }

    CPolygon& CPolygon::FHeight(float AHeight)
    {
        VHeight = AHeight;
        return *this;
    }

    std::array<float , 4> CPolygon::FColor()
    {
        return VColor;
    }

    CPolygon& CPolygon::FColor(const std::array<float , 4>& AColor)
    {
        VColor = AColor;
        return *this;
    }

    CPolygon& CPolygon::FCorrectToWidth()
    {
        VY += (VWidth * GVideo.FRatio() - VHeight) / 2.0F;
        VHeight = VWidth * GVideo.FRatio();
        return *this;
    }

    CPolygon& CPolygon::FCorrectToHeight()
    {
        VX += (VWidth - VHeight * GVideo.FInversedRatio()) / 2.0F;
        VWidth = VHeight * GVideo.FInversedRatio();
        return *this;
    }

    CPolygon& CPolygon::FUpdate()
    {
        VVertices = {{VX , VY} , {VX + VWidth , VY} , {VX + VWidth , VY + VHeight} , {VX , VY + VHeight}};
        return *this;
    }

    CPolygon& CPolygon::FRender()
    {
        NVideo::GVBO.FBuffer(VVertices);
        NVideo::GEBO.FBuffer(VIndices);
        GShaderProgram.FColor(VColor);
        glDrawElements(GL_TRIANGLES , static_cast<signed int>(VIndices.size()) , GL_UNSIGNED_INT , nullptr);
        return *this;
    }
}