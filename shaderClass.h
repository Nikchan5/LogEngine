#ifndef SHADERCLASS_H
#define SHADERCLASS_H

#include <glad/glad.h>
#include <string>
#include <fstream>


std::string shader_read(const char* filename);



class Shader {
public:
	GLuint ID;

	Shader(const char* vertexFile, const char* fragmentFile);

	void Activate();

	void Delete();
};

#endif 