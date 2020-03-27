#include "Sprite.h"

using namespace Rendering;
using namespace Models;

Sprite::Sprite()
{
    this->texture = new Texture;
    this->quad = new Quad();
}

Sprite::~Sprite()
{

}

void Sprite::setTexture(GLchar *path)
{
    texture->loadTexture(path, false, "sprite");
}

void Sprite::setQuad(Quad *quad)
{
    this->quad = quad;
}

void Sprite::Draw()
{
    texture->bind();
    quad->Create();
    quad->Draw();   
}

