#include "Mesh.h"
#include <iostream>
namespace MKEngine {

	Mesh::Mesh()
	{
	}

	Mesh::~Mesh()
	{
	}

	void Mesh::init(MKGraphics::Program& program)
	{
		_program = &program;
		_vbo.init();
		_vbo.bind(MKGraphics::Buffer::Target::ArrayBuffer);
		_vao.init(program);
		Vertex::configureVAO(_vao);
	}

	void Mesh::addVertex(Vertex v)
	{
		_vertices.push_back(v);
	}

	void Mesh::addTriangle(Vertex v1, Vertex v2, Vertex v3)
	{
		_vertices.push_back(v1);
		_vertices.push_back(v2);
		_vertices.push_back(v3);
	}

	void Mesh::addQuad(Vertex v1, Vertex v2, Vertex v3, Vertex v4)
	{
		addTriangle(v1, v2, v3);
		addTriangle(v3, v4, v1);
	}

	void Mesh::pushVertices()
	{
		size_t size = _vertices.size() * sizeof(Vertex);
		_vbo.allocate(size, MKGraphics::Buffer::Usage::StaticDraw);
		_vbo.fill(0, size, _vertices.data());
	}

	void Mesh::render()
	{
		_program->use();
		_vao.bind();
		_vbo.bind(MKGraphics::Buffer::Target::ArrayBuffer);
		_program->drawArrays(MKGraphics::Program::Primitive::Triangles, 0, _vertices.size());
	}

}