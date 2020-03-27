#ifndef _MODELS_MANAGER_H
#define _MODELS_MANAGER_H

#include <map>
#include "ShaderManager.h"
#include "IGameObject.h"
#include "Quad.h"
#include "Triangle.h"
#include "Sprite.h"

using namespace Rendering;

namespace Managers
{
    class ModelsManager
    {
    public:
        ModelsManager();
        ~ModelsManager();

        void Draw();
        void Update();
        void DeleteModel(const std::string& gameModelName);
        const IGameObject& GetModel(const std::string& gameModelName) const;
        void drawTriangles(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3);
        void drawQuad();

    private:
        std::map<std::string, IGameObject*> gameModelList;
    };
}
#endif