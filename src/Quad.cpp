#include "Quad.h"

// Quad source file//
// here is how to draw the quad //
/// quad is a children of the model class so it inherits all the member function from it //
// first we define the position vector, allocate buffers in the GPU, fill that buffer and call OpenGL drawing function //
// here the attributes of vertex are Position Vector, Color Vector and Texture Coordinates //


using namespace Rendering;
using namespace Models;

Quad::Quad()
{
}

Quad::~Quad()
{

}

// Just as we said earlier, we first define the position vector and the color vector //
// then we generate buffers for it named as GL_ARRAY_BUFFER, these are allocated in the GPU memory //
// after generating the buffer, in case of binding we are binding this buffer with vertex arrays, later we need vertex arrays for drawing //
// then there is the empty buffer, we need to fill in with our position and color vector in that buffer //
// later for drawing we just bind the vertex array and then call draw function ///

void Quad::Create(GLfloat x, GLfloat y)
{
    GLuint vao;
    GLuint vbo;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    std::vector<Vertex> vertices;
    vertices.push_back(Vertex(glm::vec4(x, y, 0.0, 1.0),
                            glm::vec2(0, 0)));
    vertices.push_back(Vertex(glm::vec4(x, y-80.0f, 0.0, 1.0),
                            glm::vec2(0, 1)));
    vertices.push_back(Vertex(glm::vec4(x+80.0f, y, 0.0, 1.0),
                            glm::vec2(1, 0)));
    vertices.push_back(Vertex(glm::vec4(x+80.0f, y-80.0f, 0.0, 1.0),
                            glm::vec2(1, 1)));

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 4, &vertices[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, Vertex::texture)));
    glBindVertexArray(0);
    this->vao = vao;
    this->vbos.push_back(vbo);
}

void Quad::Update()
{

}

// this is what i am saying //
void Quad::Draw(glm::mat4 projection_matrix, glm::mat4 view_matrix)
{
    glUseProgram(program);
    glUniformMatrix4fv(glGetUniformLocation(program, "projection"),1, GL_FALSE, glm::value_ptr(projection_matrix));
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}
