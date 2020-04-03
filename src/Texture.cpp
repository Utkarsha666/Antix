#include "Texture.h"

using namespace Rendering;
using namespace Models;

// constructor just generates a textures buffer, initializes some private variables and nothing else //
Texture::Texture() : WIDTH(0), HEIGHT(0), INTERNAL_FORMAT(GL_RGB), IMAGE_FORMAT(GL_RGB), 
                                    WRAP_S(GL_REPEAT), WRAP_T(GL_REPEAT), FILTER_MIN(GL_LINEAR), FILTER_MAG(GL_LINEAR)
{
}

Texture::~Texture()
{
        // texture destructor lol ..
}

// with this functon texture is loaded from the file // the last argument is the texture name //
void Texture::loadTexture(GLchar* path, bool alpha, std::string name)
{
    this->name = name;
    if (alpha)
    {
        INTERNAL_FORMAT = GL_RGBA;
        IMAGE_FORMAT = GL_RGBA;
    }

    int width, height;

    // we have used soil library to load the image
    unsigned char *Image = SOIL_load_image(path, &width, &height, 0, IMAGE_FORMAT == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
    genTextures(width, height, Image);

    SOIL_free_image_data(Image);
}

void Texture::genTextures(GLuint width, GLuint height, unsigned char* data)
{
    this->WIDTH = width;
    this->HEIGHT = height;
    glGenTextures(1, &this->ID);
    glBindTexture(GL_TEXTURE_2D, this->ID);
    glTexImage2D(GL_TEXTURE_2D, 0, this->INTERNAL_FORMAT, width, height, 0, this->IMAGE_FORMAT, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->WRAP_S);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->WRAP_T);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->FILTER_MIN);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->FILTER_MAG);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::bind() const
{
    glBindTexture(GL_TEXTURE_2D, this->ID);
}

void Texture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture& Texture::operator=(Texture& tex)
{
    this->ID = tex.ID;
    this->WIDTH = tex.WIDTH;
    this->HEIGHT = tex.HEIGHT;
    this->WRAP_S = tex.WRAP_S;
    this->WRAP_T = tex.WRAP_T;
    this->FILTER_MAG = tex.FILTER_MAG;
    this->FILTER_MIN = tex.FILTER_MIN;
    this->INTERNAL_FORMAT = tex.INTERNAL_FORMAT;
    this->IMAGE_FORMAT = tex.IMAGE_FORMAT;
    return *this;
}

GLuint Texture::getTexture()
{
    return (this->ID);
}

std::string Texture::getName()
{
    return name;
}