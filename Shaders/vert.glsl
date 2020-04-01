#version 450 core

layout (location = 0) in vec4 in_position;
layout (location = 1) in vec2 in_texCoords;

uniform mat4 projection;
out vec2 texCoords;

void main()
{
    gl_Position = projection * in_position ;
    texCoords = in_texCoords;
}
