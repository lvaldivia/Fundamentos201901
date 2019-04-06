#include "GLSProgram.h"
#include <fstream>

GLSProgram::GLSProgram(): programID(0),
						vertexShaderID(0), 
						fragmentShaderID(0)
{
}

GLSProgram::~GLSProgram() {

}

void GLSProgram::compileShader(const string& shaderPath, GLuint id)
{
	string filecontent = "";
	string line = "";

	ifstream shaderFile(shaderPath);
	if(shaderFile.fail()) {
		//shader no existe en la rut
	}
	while (getline(shaderFile, line)) {
		filecontent += line + "\n";
	}
	shaderFile.close();
	const char* contents = filecontent.c_str();
	glShaderSource(id, 1, &contents, nullptr);
	glCompileShader(id);


	GLint isCompiled = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);

}

void GLSProgram::compileShaders(const string & vertexShaderFilePath, const string & fragmentShaderFilePath)
{
}

void GLSProgram::linkShader()
{
}
