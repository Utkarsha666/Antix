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

struct Position
{
    int x = 500;
    int y = 500;
};
Position p;

int main(int argc, char **argv)
{

    AntixEngine *game = new AntixEngine();

    // sprite constructor //
    Models::Sprite *sprite = new Models::Sprite("../textures/block_solid.png", false);
    Models::Sprite *sprite2 = new Models::Sprite("../textures/brickwall.jpg", false);
    Models::Sprite *sprite3 = new Models::Sprite("../textures/block_solid.png", false);
    
    game->createWindow("Game Engine!!!", 400, 200, 800, 600, true);

    game->loadShader("spriteShader", "../Shaders/vert.glsl", "../Shaders/frag.glsl");

    // default shader //
    game->getModelsManager()->drawTriangles(0.15, 0.15,          // x1, y1
                                           -0.15, -0.15,        // x2, y2
                                            0.15, -0.15);       // x3, y3
    
    // draw sprite on the screen //
    game->getModelsManager()->attachSprite(sprite, "block_solid", p.x + 1, p.y + 2);

    game->getModelsManager()->attachSprite(sprite2, "brickwall", 300, 300);

    game->getModelsManager()->attachSprite(sprite3, "block_solid2", 400, 400);
    
    game->getModelsManager()->drawQuad(400, 400);
    

    ////////////////////////////////////////////////
    // game logics ////////////////////////////////
    ///////////////////////////////////////////////

    game->run();
    
    return 0;
}
