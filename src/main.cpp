// Author : Utkarsha //
// ////// Date : 13 Feb 2020 // //////
// Simple C++ Antix Program //

#pragma once

#include "Antix.h"
#include "Sprite.h"


using namespace Antix;
using namespace Init;

int main(int argc, char **argv)
{

    AntixEngine *game = new AntixEngine();

    // sprite constructor //
    Models::Sprite* sprite = new Models::Sprite("../textures/block_solid.png", false);
    
    game->createWindow("My New Game", 400, 200, 800, 600, true);

    // default shader //
    game->getModelsManager()->drawTriangles(0.15, 0.15,          // x1, y1
                                                              -0.15, -0.15,        // x2, y2
                                                               0.15, -0.15);       // x3, y3

    // Load Shader from file //                                                               
    game->loadShader("spriteShader", "../Shaders/vert.glsl", "../Shaders/frag.glsl");

    // draw sprite on the screen //
    game->getModelsManager()->drawSprite(sprite);
    
    game->run();

    return 0;
}
