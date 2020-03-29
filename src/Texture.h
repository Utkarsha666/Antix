#ifndef _TEXTURE_MANAGER_H
#define _TEXTURES_MANAGER_H

/////// Header Files //////////////////
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <map>
#include "SOIL.h"
////////////////////////////////////

namespace Rendering
{
    namespace Models 
    {
        class Texture
        {
        public:
            Texture();
            ~Texture();

            void loadTexture(GLchar* path, bool alpha, std::string name);
            void genTextures(GLuint width, GLuint height, unsigned char* data);
            void bind() const;
        /// These are just the attributes of the textures // 
            Texture& operator=(Texture& tex);
            void unbind() const;
        private:
            GLuint ID;
            GLuint WIDTH;
            GLuint HEIGHT;
            GLuint WRAP_S;
            GLuint WRAP_T;
            GLuint FILTER_MAG;
            GLuint FILTER_MIN;
            GLuint INTERNAL_FORMAT;
            GLuint IMAGE_FORMAT;
        };
    }
}
#endif