#ifndef _IGAME_OBJECT_H
#define _IGAME_OBJECT_H

#include <vector>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "Vertex.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Rendering
{
    class IGameObject
    {
    public:
        virtual ~IGameObject() = 0;

        virtual void Draw(glm::mat4 projection_matrix, glm::mat4 view_matrix) = 0;
        virtual void Update() = 0;
        virtual void setProgram(GLuint shaderName) = 0;
        virtual void Destroy() = 0;
        virtual GLuint GetVao() const = 0;
        virtual const std::vector<GLuint>& GetVbos() const = 0;
        
    private:
    };

    inline IGameObject::~IGameObject()
    {
        
    }
}
#endif