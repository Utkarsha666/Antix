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
void ModelsManager::drawSprite(GLchar* path)
{
    Models::Sprite *sprite = new Models::Sprite();
    Models::Quad *quad = new Models::Quad();
    sprite->setProgram(ShaderManager::GetShader("spriteShader"));
    sprite->setTexture(path);
    quad->Create();
    sprite->setQuad(quad);  // set quad //
    this->gameModelList["sprite"] = sprite;
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

void ModelsManager::Draw()
{
    for (auto model : gameModelList)
    {
        model.second->Draw();
    }
}