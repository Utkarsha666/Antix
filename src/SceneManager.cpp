#include "SceneManager.h"

using namespace Managers;

SceneManager::SceneManager()
{
    glEnable(GL_DEPTH_TEST);
    
}

SceneManager::~SceneManager()
{
    if (modelsManager) {
        delete modelsManager;
        modelsManager = NULL;
    }

    if (shaderManager) {
        delete shaderManager;
        shaderManager = NULL;
    }
}

void SceneManager::BeginFrame()
{
    modelsManager->Update();
}

void SceneManager::DisplayFrame()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.5f, 0.5f, 0.5f, 1.0);

    modelsManager->Draw();
}

ModelsManager* SceneManager::getModelsManager() const
{
    return (modelsManager);
}

void SceneManager::EndFrame()
{

}

void SceneManager::Reshape(int width,
                            int height,
                            int previousWidth,
                            int previousHeight)
{
    
}

void SceneManager::setModelsManager(Managers::ModelsManager*& models_manager)
{
    this->modelsManager = models_manager;
}