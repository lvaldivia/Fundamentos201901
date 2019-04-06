#include "GLSProgram.h"
#include <fstream>
#include <vector>
#include "Error.h"
#include <iostream>

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
		fatalError("El shader en la ruta " 
						+ shaderPath + " no existe");
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
	if (isCompiled == GL_FALSE) {
		GLint maxLenght = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLenght);
		vector<GLchar> errorLog(maxLenght);
		glGetShaderInfoLog(id, maxLenght, &maxLenght, &errorLog[0]);
		std::cout << shaderPath << endl;
		fatalError(&errorLog[0]);
		glDeleteShader(id);
		return;
	}

}

void GLSProgram::compileShaders(const string & vertexShaderFilePath, 
								const string & fragmentShaderFilePath)
{
	programID = glCreateProgram();
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (vertexShaderID == 0) {
		fatalError("El vertext shader no se puede crear ");
	}
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (fragmentShaderID == 0) {
		fatalError("El fragment shader no se puede crear");
	}
	compileShader(vertexShaderFilePath, vertexShaderID);
	compileShader(fragmentShaderFilePath, fragmentShaderID);
	
}

void GLSProgram::linkShader()
{
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);

	glLinkProgram(programID);
	GLint isLinked = 0;
	glGetProgramiv(programID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE) {
		GLint maxLenght = 0;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH
						,&maxLenght);
		vector<GLchar> infoLog(maxLenght);
		glGetProgramInfoLog(programID, maxLenght,&maxLenght, &infoLog[0]);
		glDeleteProgram(programID);
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);
		return;
	}
	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragmentShaderID);
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}
