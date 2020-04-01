///////// Author : utkarsha khanal //////////////
///////// Project: Antix game engine ////////////////////
//////////////////////////////////////////////////////

#include "ModelsManager.h"
using namespace Managers;
using namespace Rendering;

ModelsManager::ModelsManager()
{

}

ModelsManager::~ModelsManager()
{
    for (auto model : gameModelList)
    {
        delete model.second;
    }
    gameModelList.clear();
}

void ModelsManager::drawTriangles(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3)
{
    Models::Triangle* triangle = new Models::Triangle();
    triangle->setProgram(ShaderManager::GetShader("colorShader"));
    triangle->Create(x1, y1, x2, y2, x3, y3);
    this->gameModelList["triangle"] = triangle;
}       //end function drawTriangle()

void ModelsManager::drawQuad()
{
    Models::Quad* quad = new Models::Quad();
    quad->setProgram(ShaderManager::GetShader("spriteShader"));
    quad->Create();
    this->gameModelList["quad"] = quad;
}       // end function drawQuad()

// function that draws quad on the screen first, and then lays texture on top of it ///
/////////////////////////////////////////////////////////////////////////////////////
void ModelsManager::attachSprite(Models::Sprite *& sprite, std::string name)
{
    Models::Sprite *m_sprite = new Models::Sprite();
    m_sprite = sprite;
    Models::Quad *quad = new Models::Quad();
    m_sprite->setProgram(ShaderManager::GetShader("spriteShader"));
    m_sprite->setTexture(m_sprite->getPath(), m_sprite->getAlpha());
    quad->Create();
    m_sprite->setQuad(quad);  // set quad //
    this->gameModelList[name] = sprite;
}       //end function draw sprite //

const IGameObject& ModelsManager::GetModel(const std::string& gameModelName) const
{
    return (*gameModelList.at(gameModelName));
}

void ModelsManager::Update()
{
    for (auto model : gameModelList)
    {
        model.second->Update();
    }
}

void ModelsManager::Draw(glm::mat4 projection_matrix, glm::mat4 view_matrix)
{
    for (auto model : gameModelList)
    {
        model.second->Draw(projection_matrix, view_matrix);
    }
}