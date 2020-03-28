#include "Antix.h"

using namespace Antix;

Antix::Window AntixEngine::a_Window;

AntixEngine::AntixEngine()
{

}

bool AntixEngine::init()
{
    this->m_ShaderManager = new Managers::ShaderManager();
    this->m_ShaderManager->CreateProgram("colorShader", "../Shaders/basic_vert.glsl", "../Shaders/basic_frag.glsl");
    this->m_SceneManager = new Managers::SceneManager();
    Init::InitAntix::setListener(m_SceneManager);

    if (m_SceneManager && m_ShaderManager)
    {
        this->m_ModelsManager = new Managers::ModelsManager();
        this->m_SceneManager->setModelsManager(m_ModelsManager);
    }
    else
    {
        return false;
    }
    
    
    return true;
}

void AntixEngine::createWindow(std::string name,
                              int pos_x,
                              int pos_y,
                              int width,
                              int height,
                              bool fullscreen)
{
    this->a_Window = Window(name, pos_x, pos_y, width, height, fullscreen);
    Context context(4, 5, true);
    Framebuffer framebuffer(true, true, true, true);

    Init::InitAntix::init(a_Window, context, framebuffer);
    init();
}

void AntixEngine::run()
{
    Init::InitAntix::run();
}

Antix::IListener* AntixEngine::getSceneManager() const
{
    return (this->m_SceneManager);
}

Managers::ShaderManager* AntixEngine::getShaderManager() const
{
    return (this->m_ShaderManager);
}

Managers::ModelsManager* AntixEngine::getModelsManager() const
{
    return m_ModelsManager;
}

AntixEngine::~AntixEngine()
{
    if (m_SceneManager)
        delete m_SceneManager;
    
    if (m_ShaderManager)
        delete m_ShaderManager;

    if (m_ModelsManager)
        delete m_ModelsManager;
}