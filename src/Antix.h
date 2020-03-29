#ifndef _ANTIX_H
#define _ANTIX_H

#include "InitAntix.h"
#include "SceneManager.h"
#include "IListener.h"
#include "Window.h"
#include "Context.h"
#include "Framebuffer.h"

namespace Antix
{
    class AntixEngine
    {
    public:
        AntixEngine();
        ~AntixEngine();

       
        void run();

        void createWindow(std::string name, int pos_x, int pos_y, int width, int height, bool fullscreen);

        Antix::IListener* getSceneManager() const;
        Managers::ShaderManager* getShaderManager() const;
        Managers::ModelsManager* getModelsManager() const;

        // loading shaders //
        void loadShader(std::string name, GLchar* vert_path, GLchar* frag_path);

    private:
        bool init();

        static Antix::Window a_Window;
        int w_Width, w_Height;
       
        Antix::IListener* m_SceneManager;
        Managers::ShaderManager* m_ShaderManager;
        Managers::ModelsManager* m_ModelsManager;
    };
}

#endif