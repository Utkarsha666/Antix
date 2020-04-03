#ifndef _MODEL_H
#define _MODEL_H

#include <vector>
#include "IGameObject.h"

namespace Rendering
{
    namespace Models
    {
        class Model : public IGameObject
        {
        public:
            Model();

            virtual ~Model();
            virtual void Draw(glm::mat4 projection_matrix, glm::mat4 view_matrix) override;
            virtual void Update() override;
            virtual void setProgram(GLuint shaderName) override;
            virtual void Destroy() override;
            virtual GLuint GetVao() const override;
            virtual const std::vector<GLuint>& GetVbos() const override;

            void operator=(Model *&);
        protected:
            GLuint vao;
            GLuint program;
            std::vector<GLuint> vbos;
        };
    }
}
#endif
