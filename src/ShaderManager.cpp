#include "ShaderManager.h"

using namespace Managers;

std::map<std::string, GLuint> ShaderManager::programs;

ShaderManager::ShaderManager(void) { }

ShaderManager::~ShaderManager(void)
{
    std::map<std::string, GLuint>::iterator i;
    for (i = programs.begin(); i!= programs.end(); i++)
    {
        GLuint pr = i->second;
        glDeleteProgram(pr);
    }
}

std::string ShaderManager::readShader(const std::string& filename)
{
    std::string shaderCode;
    std::ifstream file(filename, std::ios::in);

    if (!file.good()) {
        std::cout << "Can't read file " << filename.c_str() << std::endl;
        std::terminate();
    }

    file.seekg(0, std::ios::end);
    shaderCode.resize((unsigned int)file.tellg());
    file.seekg(0, std::ios::beg);
    file.read(&shaderCode[0], shaderCode.size());
    file.close();

    return shaderCode;

}

GLuint ShaderManager::createShader(GLenum shaderType, const std::string& source, const std::string& shaderName)
{
    int compileResult = 0;

    GLuint shader = glCreateShader(shaderType);
    const char* shader_code_ptr = source.c_str();
    const int shader_code_size = source.size();

    glShaderSource(shader, 1, &shader_code_ptr, &shader_code_size);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);

    if (compileResult == GL_FALSE)
    {
        int info_log_length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);
        std::vector<char> shader_log(info_log_length);
        glGetShaderInfoLog(shader, info_log_length, NULL, &shader_log[0]);
        std::cout << "ERROR compiling Shader: " << shaderName.c_str() << std::endl << &shader_log[0] << std::endl;
    }
    return shader;
}

void ShaderManager::CreateProgram(const std::string& shaderName,
                                const std::string& vertexShaderFilename,
                                const std::string& fragmentShaderFilename)
{
    std::string vertex_shader_code = readShader(vertexShaderFilename);
    std::string fragment_shader_code = readShader(fragmentShaderFilename);

    GLuint vertex_shader = createShader(GL_VERTEX_SHADER, vertex_shader_code, "vertex shader");
    GLuint fragment_shader = createShader(GL_FRAGMENT_SHADER, fragment_shader_code, "fragment shader");

    int link_result = 0;

    GLuint program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);

    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &link_result);

    if (link_result == GL_FALSE) {
        std::cout << "Shader Link Error!!! " << std::endl;
    }

    programs[shaderName] = program;
}

const GLuint ShaderManager::GetShader(const std::string& shaderName)
{
    return programs.at(shaderName);
}