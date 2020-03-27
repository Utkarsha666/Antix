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
    gameModelList["triangle"] = triangle;
}

void ModelsManager::drawQuad()
{
    Models::Quad* quad = new Models::Quad();
    quad->setProgram(ShaderManager::GetShader("colorShader"));
    quad->Create();
    gameModelList["quad"] = quad;
}

void ModelsManager::drawSprite(GLchar* path)
{
    Models::Sprite *sprite = new Models::Sprite();
    sprite->setProgram(ShaderManager::GetShader("colorShader"));
    sprite->setTexture(path);
    gameModelList["sprite"] = sprite;
}
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