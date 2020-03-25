#include "ModelsManager.h"
using namespace Managers;
using namespace Rendering;

ModelsManager::ModelsManager()
{
    Models::Triangle* triangle = new Models::Triangle();
    triangle->setProgram(ShaderManager::GetShader("colorShader"));
    triangle->Create();
    gameModelList["triangle"] = triangle;

    Models::Quad* quad = new Models::Quad();
    quad->setProgram(ShaderManager::GetShader("colorShader"));
    quad->Create();
    gameModelList["quad"] = quad;
}

ModelsManager::~ModelsManager()
{
    for (auto model : gameModelList)
    {
        delete model.second;
    }
    gameModelList.clear();
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