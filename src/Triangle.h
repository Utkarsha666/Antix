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
            ~Triangle();

            void Create();
            virtual void Update() override final;
            virtual void Draw() override final;
        };
    }
}
#endif