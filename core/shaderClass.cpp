#include "shaderClass.h"


std::string shader_read(const char* filename) {
	std::ifstream file(filename, std::ios::binary);
	if (file) {
		std::string contents;
		file.seekg(0, std::ios::end);
		contents.resize(file.tellg());
		file.seekg(0, std::ios::beg);
		file.read(&contents[0], contents.size());
		file.close();
		return contents;
	}
	throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile) {
	std::string vertexCode = shader_read(vertexFile);
	const char* vertexSrc = vertexCode.c_str();

	std::string fragmentCode = shader_read(fragmentFile);
	const char* fragmentSrc = fragmentCode.c_str();

	// —оздание и компил€ци€ шейдеров
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID, 1, &vertexSrc, NULL);
	glCompileShader(vertexShaderID);

	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID, 1, &fragmentSrc, NULL);
	glCompileShader(fragmentShaderID);

	// —оздание программы шейдеров
	ID = glCreateProgram();
	glAttachShader(ID, vertexShaderID);
	glAttachShader(ID, fragmentShaderID);
	glLinkProgram(ID);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}

void Shader::Activate() {
	glUseProgram(ID);
}

void Shader::Delete() {
	glDeleteProgram(ID);

}