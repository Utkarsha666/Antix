#ifndef _VERTEX_H
#define _VERTEX_H

#include <glm/glm.hpp>

namespace Rendering
{
    struct Vertex
    {
        glm::vec4 position;
        glm::vec4 color;
        glm::vec2 texture;

        Vertex(const glm::vec4 &Pos, const glm::vec4 Color)
        {
            position = Pos;
            color = Color;
        }

        Vertex(const glm::vec4 &Pos, const glm::vec2 TexCoords)
        {
            position = Pos;
            texture = TexCoords;
        }
    };
}
#endif