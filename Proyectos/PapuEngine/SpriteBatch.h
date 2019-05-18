#pragma once
#include <GL\glew.h>
#include "Vertex.h"
#include <glm\glm.hpp>
#include <vector>

enum class GlypSortType {
	NONE,
	FRONT_TO_BACK,
	BACK_TO_FRONT,
	TEXTURE
};

struct Glyph {
	GLuint texture;
	float depth;
	Vertex topLeft;
	Vertex bottomLeft;
	Vertex topRight;
	Vertex bottomRight;

};

class Renderbatch {
public:
	Renderbatch(GLuint _offset, GLuint _numVertices, GLuint _texture);
	GLuint _offset;
	GLuint _numVertices;
	GLuint _texture;
};


class SpriteBatch
{
private:
	GLuint vbo;
	GLuint vao;
	std::vector<Glyph*> glyphs;
	std::vector<Renderbatch> renderbatches;
	void createVertexArray();
	void sortGlyph();
	void createRenderBatches();
public:
	void init();
	void begin(GlypSortType sortGlyph = GlypSortType::TEXTURE);
	void end();
	void draw(const glm::vec4& destRect, const glm::vec4& uvRect,
		GLuint texture, float depth, Color& color
	);
	void renderBatch();
	static bool compareFrontToBack(Glyph* a, Glyph* b);
	static bool compareBackToFront(Glyph* a, Glyph* b);
	static bool compareTexture(Glyph* a, Glyph* b);
	SpriteBatch();
	~SpriteBatch();
};

