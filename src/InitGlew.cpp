#include "InitGlew.h"

using namespace Antix;
using namespace Antix::Init;

void InitGlew::Init() {
    glewExperimental = true;

    if (glewInit() == GLEW_OK)
    {
        std::cout << "GLEW: Initialize" << std::endl;
    }

    if (glewIsSupported("GL_VERSION_4_5"))
    {
        std::cout << "GLEW GL_VERSION_4_5 is 4.5\n";
    }
    else
    {
        std::cout << "GLEW GL_VERSION_4_5 is not supported\n";
    }

}