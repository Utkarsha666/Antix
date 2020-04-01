#ifndef _SCENE_MANAGER_H
#define _SCENE_MANAGER_H

#include "ShaderManager.h"
#include "ModelsManager.h"
#include "IListener.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
        virtual void setModelsManager(Managers::ModelsManager*& models_manager);

    private:
        Managers::ShaderManager* shaderManager;
        Managers::ModelsManager* modelsManager;

        glm::mat4 projection_matrix;
        glm::mat4 view_matrix;
    };
}
#endif 