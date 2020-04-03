#include "Sprite.h"

// Antix Game Engine by Utkarsha ///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// this is a simple sprite class //////////////////////////////////////////////////////////////////////////////////////////////////
// the main logic behind this class is simple ////////////////////////////////////////////////////////////////////////////////////
// we already have a quad class that draws quad on the screen ///////////////////////////////////////////////////////////////////
// first load texture into memory same as we did while generating vertex buffers and then bind it ///////////////////////////////
// after we bind the texture, now we can draw the quad. The texture will be mapped accordingly based on the texture coordinate //
// i have made it simple for educational purpose only ///////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace Rendering;
using namespace Models;

Sprite::Sprite()
{
    this->texture = new Texture();
    this->quad = new Quad();
}

Sprite::Sprite(GLchar* path, bool alpha)
{
    this->texture = new Texture;
    this->quad = new Quad();
    this->path = path;
    this->alpha = alpha;
}

Sprite::~Sprite()
{
    delete texture;
    delete quad;
}

void Sprite::setTexture(GLchar *path, bool alpha, std::string name)
{
    texture->loadTexture(path, alpha, name);
}

void Sprite::setQuad(Quad *& quad, GLfloat x, GLfloat y)
{
    this->quad = quad;
    this->quad->Create(x, y);
}

void Sprite::Draw(glm::mat4 projection_matrix, glm::mat4 view_matrix)
{
    glUseProgram(program);
    glUniformMatrix4fv(glGetUniformLocation(program, "projection"), 1, GL_FALSE, glm::value_ptr(projection_matrix));    // passing projection matrix to shaders //
    texture->bind();
    quad->Draw(projection_matrix, view_matrix);
    texture->unbind();
}

void Sprite::setWidthAndHeight(GLuint width, GLuint height)
{
    this->Width = width;
    this->Height = height;
}

void Sprite::operator=(const Models::Sprite *& sprite)
{
    this->texture = sprite->texture;
    this->quad = sprite->quad;
    this->Width = sprite->Width;
    this->Height = sprite->Height;
}

GLchar* Sprite::getPath()
{
    return path;
}

bool Sprite::getAlpha()
{
    return alpha;
}

//const Texture& Sprite::getTexture(std::string name)
//{
 //   return (*textures.at(texture->getName()));
//}