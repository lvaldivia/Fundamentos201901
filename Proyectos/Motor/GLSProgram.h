#pragma once
#include <string>


using namespace std;

class GLSProgram {
private:
	int programID;
	int fragmentShaderID;
	int vertexShaderID;
	void compileShader(const string& shaderPath, int id);
public:
	GLSProgram();
	~GLSProgram();
	void compileShaders(const string& vertexShaderFilePath, 
						const string& fragmentShaderFilePath);
};

