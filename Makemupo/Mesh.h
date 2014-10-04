#pragma once

#include "Vertex.h"
#include "VertexArray.h"
#include "Buffer.h"
#include "Program.h"

#include <vector>

namespace MKEngine {

	class Mesh
	{
	public:
		Mesh();
		~Mesh();
		void init(MKGraphics::Program& program);

		void addVertex(Vertex v);
		void addTriangle(Vertex v1, Vertex v2, Vertex v3);
		void addQuad(Vertex v1, Vertex v2, Vertex v3, Vertex v4);
		void pushVertices();
		void render();

	private:
		std::vector<Vertex> _vertices;
		MKGraphics::Program *_program;

		MKGraphics::VertexArray _vao;
		MKGraphics::Buffer _vbo;
	};

}