#include "SceneManager.h"

using namespace Managers;

SceneManager::SceneManager()
{
    glEnable(GL_DEPTH_TEST);
    shaderManager = new ShaderManager();
    shaderManager->CreateProgram("colorShader",
                                "../Shaders/basic_vert.glsl",
                                "../Shaders/basic_frag.glsl");
    modelsManager = new ModelsManager();
}

SceneManager::~SceneManager()
{
    delete shaderManager;
    delete modelsManager;
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