#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <source_location>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <memory>
#include <optional>
#include <array>

#pragma warning(push)
#pragma warning(disable : 26819 26451)
#include "..\\GraphicsLibraryExtensionWrangler\\glew.h"
#include "..\\SimpleDirectMediaLayer\\sdl_opengl.h"
#include "..\\SimpleDirectMediaLayer\\sdl_image.h"
#include "..\\GraphicsLibraryMathematics\\glm.hpp"
#include "..\\GraphicsLibraryMathematics\\gtc\\matrix_transform.hpp"
#include "..\\GraphicsLibraryMathematics\\gtc\\type_ptr.hpp"
#pragma warning(pop)

#include <gl\\glu.h>

namespace NBEA
{
    inline class CEngine
    {
        private:
            friend signed int ::main(signed int , char**);
        private:
            void FInitiate();
        public:
            CEngine();
            ~CEngine();
    }
    GEngine;
}