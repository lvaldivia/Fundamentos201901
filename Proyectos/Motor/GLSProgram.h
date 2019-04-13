#pragma once
#include <string>
#include <GL/glew.h>

using namespace std;

class GLSProgram {
private:
	GLuint programID;
	GLuint fragmentShaderID;
	GLuint vertexShaderID;
	void compileShader(const string& shaderPath, GLuint id);
	int numAttribute;
public:
	GLSProgram();
	~GLSProgram();
	void compileShaders(const string& vertexShaderFilePath, 
						const string& fragmentShaderFilePath);
	void linkShader();
	void addAtribute(const string atributeName);
	void use();
	void unuse();
	GLuint getUniformLocation(const string& name);
};

