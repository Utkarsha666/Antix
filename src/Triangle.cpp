#include "Triangle.h"

using namespace Rendering;
using namespace Models;

Triangle::Triangle()
{

}

Triangle::Triangle(GLfloat x1, GLfloat y1,
                  GLfloat x2,  GLfloat y2,
                  GLfloat x3, GLfloat y3)
{
    Create(x1, y1, x2, y2, x3, y3);
}

Triangle::~Triangle()
{

}

void Triangle::Create(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3)
{
    GLuint vao;
    GLuint vbo;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    std::vector<Vertex> vertices;
    vertices.push_back(Vertex(glm::vec4(x1, y1, 0.0, 1.0), glm::vec4(1, 0, 0, 1)));
    vertices.push_back(Vertex(glm::vec4(x2, y2, 0.0, 1.0), glm::vec4(0, 1, 0, 1)));
    vertices.push_back(Vertex(glm::vec4(x3, y3, 0.0, 1.0), glm::vec4(0, 0, 1, 1)));

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 3, &vertices[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);
    
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, Vertex::color)));

    glBindVertexArray(0);
    this->vao = vao;
    this->vbos.push_back(vbo); 

}

void Triangle::Update()
{

}

void Triangle::Draw()
{
    glUseProgram(program);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}