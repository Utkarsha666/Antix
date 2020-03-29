#version 450 core

layout(location = 0) out vec4 out_color;

in vec2 texCoords;
uniform sampler2D image;

void main()
{
    out_color = vec4(texture(image, texCoords));
}
