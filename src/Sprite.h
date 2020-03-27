#ifndef _SPRITE_H
    #define _SPRITE_H

#include "Model.h"
#include "Quad.h"
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
            //Sprite(Texture &texture);
            ~Sprite();

            void setTexture(GLchar *path);
            void setQuad(Quad *quad);
            virtual void Draw() override final;

        private:
            Texture *texture;
            Models::Quad *quad;
        };
    }
}
#endif