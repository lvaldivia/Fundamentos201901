#pragma once
#include <GL\glew.h>
#include "Vertex.h"
#include <glm\glm.hpp>
#include <vector>
using namespace std;
enum class GlyphSortType {
	NONE,
	FRONT_TO_BACK,
	BACK_TO_FRONT,
	TEXTURE
};

class RenderBatch {

public:
	GLuint offset;
	GLuint numVertices;
	GLuint texture;
	RenderBatch(GLuint _offset,
				GLuint _numVertices,
				GLuint _texture) {
		offset = _offset;
		numVertices = _numVertices;
		texture = _texture;
	}
};

struct Glyph {
	GLuint texture;
	float depth;
	Vertex topLeft;
	Vertex bottomLeft;
	Vertex topRight;
	Vertex bottomRight;
};

class SpriteBatch
{
private:
	GLuint vbo;
	GLuint vao;
	vector<Glyph*> glyphs;
	vector<RenderBatch> renderBatch;
	GlyphSortType sortType;
	void createVertexArray();
	void sortGlyph();
	void createRenderBatches();
public:
	void init();
	void begin(GlyphSortType 
				type = GlyphSortType::TEXTURE);
	void end();
	void draw(const glm::vec4& destRect,
		const glm::vec4& uvRect,
		GLuint texture, float depth, const Color& color);
	SpriteBatch();

};

