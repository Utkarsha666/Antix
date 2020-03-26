#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

#include "ShaderManager.h"
#include "ModelsManager.h"
#include "IListener.h"

namespace Managers
{
    class SceneManager : public Antix::IListener
    {
    public:
        SceneManager();
        ~SceneManager();

        virtual void BeginFrame();
        virtual void DisplayFrame();
        virtual void EndFrame();
        virtual void Reshape(int width,
                            int height,
                            int previousWidth,
                            int previousHeight);

        virtual Managers::ModelsManager* getModelsManager() const;

    private:
        Managers::ShaderManager* shaderManager;
        Managers::ModelsManager* modelsManager;
    };
}
#endif 