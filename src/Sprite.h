/* Sprite Class Header File
    Author: Utkarsh Khanal
    Year: 2020
    Language: C/C++
    Project: Game Engine Sprite Library 
*/

#ifndef _SPRITE_H
#define _SPRITE_H

#include "Model.h"
#include "Quad.h"
#include <map>
#include "Texture.h"
#include <GL/glew.h>
#include "ShaderManager.h"
#include <GL/freeglut.h>

namespace Rendering
{
    namespace Models
    {
        class Sprite : public Models::Model
        {
        public:
            Sprite();
            Sprite(GLchar* path, bool alpha);
            //Sprite(Texture &texture);
            ~Sprite();
            void init();

            // setters //
            void setTexture(GLchar *path, bool alpha);
            void setQuad(Quad *& quad);
            void setWidthAndHeight(GLuint widht, GLuint height);

            virtual void Draw(glm::mat4 projection_matrix, glm::mat4 view_matrix) override final;

            void operator=(const Sprite *& sprite);

            // inline getters //
            GLchar* getPath()
            {
                return path;
            }

            bool getAlpha()
            {
                return alpha;
            }

        private:
            GLuint Width;
            GLuint Height;
            Texture *texture;
            Models::Quad *quad;

            // sprite path and alpha value //
            GLchar* path;
            bool alpha;
           // std::map<std::string, Models::Texture> textures;

        };
    }
}
#endif