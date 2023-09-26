#include "headers/shaderClass.hpp"


std::string get_file_contents(const char *filename)
// const char* get_file_contents(const char *filename)
{
    // STUB old
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

    // STUB new code
    // std::string shaderCode;
    // std::ifstream shaderStream(filename, std::ios::in);
    // if (shaderStream.is_open())
    // {
    //     std::stringstream sstr;
    //     sstr << shaderStream.rdbuf();
    //     shaderCode = sstr.str();
    //     shaderStream.close();
    // }
    // else
    // {
    //     fprintf(stderr, "Can't open file %s. Are you in right directory?\n", filename);
    //     getchar();
    //     return 0;
    // }
    // // return shaderCode.c_str();
    // return (const char *)(shaderCode.c_str());
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

    GLuint vs = CreateShader(vertexSrc, GL_VERTEX_SHADER);
    GLuint fs = CreateShader(fragmentSrc, GL_FRAGMENT_SHADER);

    // GLuint vs = CreateShader(vsSrc, GL_VERTEX_SHADER);
    // GLuint fs = CreateShader(fsSrc, GL_FRAGMENT_SHADER);

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

// void Shader::setMat4fv(glm::mat4 value, const GLchar* name, GLboolean transpose = GL_FALSE)
void Shader::setMat4fv(glm::mat4 value, const GLchar* name, GLboolean transpose)
{
    Activate();
    glUniformMatrix4fv(glGetUniformLocation(shaderProgramId, name), 1, transpose, glm::value_ptr(value));
    Deactivate();
}

void Shader::Deactivate()
{
    glUseProgram(0);
}
