// Author : Utkarsha //
// ////// Date : 13 Feb 2020 // //////
// Simple C++ Antix Program //

#pragma once
#include "InitAntix.h"
#include "Antix.h"
#include "Quad.h"

using namespace Antix;
using namespace Init;

int main(int argc, char **argv)
{

    AntixEngine *game = new AntixEngine();
    
    game->createWindow("My New Game", 400, 200, 800, 600, true);

    // default shader //
    game->getModelsManager()->drawTriangles(0.15, 0.15,          // x1, y1
                                                               -0.15, -0.15,        // x2, y2
                                                                0.15, -0.15);       // x3, y3

    // Load Shader from file //                                                               
    game->loadShader("spriteShader", "../Shaders/vert.glsl", "../Shaders/frag.glsl");
    game->getModelsManager()->drawQuad();
    game->getModelsManager()->drawSprite("../textures/block_solid.png");
    game->run();

    return 0;
}
