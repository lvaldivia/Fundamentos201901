#include "SpriteBatch.h"



SpriteBatch::SpriteBatch()
{
}

void SpriteBatch::createVertexArray()
{
}

void SpriteBatch::sortGlyph()
{
}

void SpriteBatch::createRenderBatches()
{
	std::vector<Vertex> vertices;
	vertices.resize(glyphs.size() *6);
	if (glyphs.empty()) {
		return;
	}
	int cv = 0;
	int offset = 0;
	renderBatch.emplace_back(0, 6, glyphs[0]->texture);
	vertices[cv++] = glyphs[0]->topLeft;
	vertices[cv++] = glyphs[0]->bottomLeft;
	vertices[cv++] = glyphs[0]->bottomRight;
	vertices[cv++] = glyphs[0]->bottomRight;
	vertices[cv++] = glyphs[0]->topRight;
	vertices[cv++] = glyphs[0]->topLeft;
	offset += 6;
	for (size_t i = 1; i < glyphs.size(); i++)
	{
		if (glyphs[i]->texture != glyphs[i - 1]->texture) {
			renderBatch.emplace_back(offset, 6,
				glyphs[i]->texture);
		}
		else {
			renderBatch.back().numVertices = 6;
		}
		vertices[cv++] = glyphs[i]->topLeft;
		vertices[cv++] = glyphs[i]->bottomLeft;
		vertices[cv++] = glyphs[i]->bottomRight;
		vertices[cv++] = glyphs[i]->bottomRight;
		vertices[cv++] = glyphs[i]->topRight;
		vertices[cv++] = glyphs[i]->topLeft;
		offset += 6;
	}
}

void SpriteBatch::init()
{
	createVertexArray();
}

void SpriteBatch::begin(GlyphSortType type)
{
	sortType = type;
	renderBatch.clear();
	glyphs.clear();
}

void SpriteBatch::end()
{
	sortGlyph();
	createRenderBatches();
}

void SpriteBatch::draw(const glm::vec4 & destRect, const glm::vec4 & uvRect, GLuint texture, float depth, const Color & color)
{
}
