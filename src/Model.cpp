#include "Model.h"

using namespace Rendering;
using namespace Models;

Model::Model() {

 }

Model::~Model()
{
    Destroy();
}

void Model::Draw(glm::mat4 projection_matrix, glm::mat4 view_matrix)
{

}

void Model::Update()
{

}

void Model::setProgram(GLuint program)
{
    this->program = program;
}

GLuint Model::GetVao() const
{
    return vao;
}

const std::vector<GLuint>& Model::GetVbos() const
{
    return vbos;
}

void Model::Destroy()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(vbos.size(), &vbos[0]);
    vbos.clear();
}

void Model::operator=(Model *& model)
{
    this->vao = model->vao;
    this->vbos = model->vbos;
}

