#ifndef _IGAME_OBJECT_H
#define _IGAME_OBJECT_H

#include <vector>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "Vertex.h"

namespace Rendering
{
    class IGameObject
    {
    public:
        virtual ~IGameObject() = 0;

        virtual void Draw() = 0;
        virtual void Update() = 0;
        virtual void setProgram(GLuint shaderName) = 0;
        virtual void Destroy() = 0;
        virtual GLuint GetVao() const = 0;
        virtual const std::vector<GLuint>& GetVbos() const = 0;
    };

    inline IGameObject::~IGameObject()
    {
        
    }
}
#endif