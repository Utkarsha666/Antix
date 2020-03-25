#ifndef _SHADER_MANAGER_H
#define _SHADER_MANAGER_H

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>

#include <GL/glew.h>
#include <GL/freeglut.h>

namespace Managers
{
    class ShaderManager
    {
    public:
        ShaderManager(void);
        ~ShaderManager(void);

        void CreateProgram(const std::string& shaderName,
                           const std::string& vertexShaderFilename,
                           const std::string& fragmentShaderFilename);

        static const GLuint GetShader(const std::string&);

    private:
        std::string readShader(const std::string& filename);
        GLuint createShader(GLenum shaderType, const std::string& source, const std::string& shaderName);
        static std::map<std::string, GLuint> programs;
    };
}
#endif