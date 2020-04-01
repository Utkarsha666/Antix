// Author : Utkarsha //
// ////// Date : 13 Feb 2020 // //////
// Simple C++ Antix Program //
// -----------------------------------------------------
// This is the place where you write your game logic //
///////////////////////////////////////////////////////
#include "Antix.h"
#include "Sprite.h"


using namespace Antix;
using namespace Init;

int main(int argc, char **argv)
{

    AntixEngine *game = new AntixEngine();

    // sprite constructor //
    Models::Sprite *sprite = new Models::Sprite("../textures/block_solid.png", false);
    Models::Sprite *sprite2 = new Models::Sprite("../textures/brickwall.jpg", false);
    
    game->createWindow("My New Game", 400, 200, 800, 600, true);

    game->loadShader("spriteShader", "../Shaders/vert.glsl", "../Shaders/frag.glsl");

    // default shader //
    game->getModelsManager()->drawTriangles(0.15, 0.15,          // x1, y1
                                                              -0.15, -0.15,        // x2, y2
                                                               0.15, -0.15);       // x3, y3

    // draw sprite on the screen //
    game->getModelsManager()->attachSprite(sprite, "block_solid");

    game->getModelsManager()->attachSprite(sprite2, "brickwall");

    ////////////////////////////////////////////////
    // game logics ////////////////////////////////
    ///////////////////////////////////////////////

    game->run();
    
    return 0;
}
