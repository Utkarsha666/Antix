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
    
    game->createWindow("Breakout", 400, 200, 800, 600, true);


    game->getModelsManager()->drawQuad();
    game->getModelsManager()->drawTriangles(0.15, 0.15,          // x1, y1
                                                               -0.15, -0.15,        // x2, y2
                                                                0.15, -0.15);       // x3, y3

    game->getModelsManager()->drawSprite("../res/image.png");
    game->run();

    return 0;
}
