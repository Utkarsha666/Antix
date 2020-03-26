#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "Model.h"

namespace Rendering
{
    namespace Models
    {
        class Triangle : public Model
        {
        public:
            Triangle();
            Triangle(GLfloat x1, GLfloat y1,
                    GLfloat x2, GLfloat y2,
                    GLfloat x3, GLfloat y3);
            ~Triangle();

            void Create(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3);
            virtual void Update() override final;
            virtual void Draw() override final;
        };
    }
}
#endif