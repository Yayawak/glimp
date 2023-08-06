#include "headers/shaderClass.hpp"

#pragma region cheatsource
const char *vsSrc = "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    // "in vec3 position;\n"
    "in vec3 color;\n"

    "out vec3 Color;\n"

    "uniform mat4 view;\n"
    "uniform mat4 proj;\n"
    "uniform mat4 trans;\n"
    "void main()\n"
    "{\n"
    // "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    // "   Color = color;\n"
    // "   Color = sin(color);\n"
    "   Color = vec3(sin(color.x), color.y, color.z);\n"
    "   gl_Position = proj * view * trans * vec4(position, 1.0);\n"
    "}\0";
const char *fsSrc = "#version 330 core\n\
    in vec3 Color;\n\
    out vec4 outColor;\n\
    void main()\n\
    {\n\
        // FragColor = vec4(0.4f, 0.f, 1.f, 1.f);\n\
        // outColor = vec4(1.0, 0.0, 0.0, 1.0);\n\
        outColor = vec4(Color, 1.0);\n\
    }";
#pragma endregion

std::string get_file_contents(const char *filename)
{
    // std::filesystem::path absPath = std::filesystem::absolute(filename);
    // std::ifstream in(absPath.string(), std::ios::binary);
    std::ifstream in(filename, std::ios::binary);
    if (in)
    {
        // std:: cout << "Hey"<< std::endl;
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        // std::string contents((std::istreambuf_iterator<char>(in)),
        //     std::istreambuf_iterator<char>()
        // );
        in.close();
        return (contents);
    }
    // throw(errno);
    throw std::runtime_error("Failed to open file.");
}

GLuint Shader::CreateShader(const char *txt, GLenum shaderType)
{
    GLuint s = glCreateShader(shaderType);
    glShaderSource(s, 1, &txt, NULL);
    glCompileShader(s);
    glGetShaderiv(s, GL_COMPILE_STATUS, &compileStatus);

    if (!compileStatus)
    {
        glGetShaderInfoLog(s, 512, NULL, compileShaderLog);
        const char *_ = (shaderType == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT";
        std::cout << "Error : " 
            << _
            << " : shader compilation ...\n"
            << compileShaderLog << std::endl;
    }
    return (s);
}


Shader::Shader(const char *vertexFile, const char *fragmentFile)
{
    std::string vertexCode = get_file_contents(vertexFile);
    std::string fragmentCode = get_file_contents(fragmentFile);


    const char *vertexSrc = vertexCode.c_str();
    const char *fragmentSrc = fragmentCode.c_str();
    // std::cout << vertexSrc << std::endl;
    // std::cout << fragmentSrc << std::endl;

    // GLuint vs = CreateShader(vertexFile, GL_VERTEX_SHADER);
    // GLuint fs = CreateShader(fragmentFile, GL_FRAGMENT_SHADER);

    GLuint vs = CreateShader(vsSrc, GL_VERTEX_SHADER);
    GLuint fs = CreateShader(fsSrc, GL_FRAGMENT_SHADER);

    shaderProgramId = glCreateProgram();
    glAttachShader(shaderProgramId, vs);
    glAttachShader(shaderProgramId, fs);

    glLinkProgram(shaderProgramId);
    glUseProgram(shaderProgramId);

    if (!compileStatus)
    {
        glGetShaderInfoLog(shaderProgramId, 512, NULL, compileShaderLog);
        std::cout << "Error : Shader Program Linking " << " : shader compilation ...\n"
            << compileShaderLog << std::endl;
    }
    glDeleteShader(vs);
    glDeleteShader(fs);
}

void Shader::Activate()
{
    glUseProgram(shaderProgramId);
}

void Shader::Delete()
{
    glDeleteProgram(shaderProgramId);
}
