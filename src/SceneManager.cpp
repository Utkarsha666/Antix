#include "SceneManager.h"

using namespace Managers;

SceneManager::SceneManager()
{
    glEnable(GL_DEPTH_TEST);
    view_matrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f),glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    projection_matrix = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.0f, -1.0f);
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

    modelsManager->Draw(projection_matrix, view_matrix);
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