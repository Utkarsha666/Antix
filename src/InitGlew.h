#ifndef _INIT_GLEW
#define _INIT_GLEW

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

namespace Antix {
    namespace Init {
        class InitGlew
        {
        public:
            static void Init();
        };
    }
}
#endif