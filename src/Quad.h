#ifndef _QUAD_H
#define _QUAD_H
#include "Model.h"

namespace Rendering
{
    namespace Models
    {
        class Quad : public Models::Model
        {
        public:
            Quad();
            ~Quad();
            
            void Create(GLfloat x, GLfloat y);
            virtual void Draw(glm::mat4 projection_matrix, glm::mat4 view_matrix) override final;
            virtual void Update() override final;
        };
    }
}

#endif