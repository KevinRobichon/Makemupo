#pragma once

#include "CommonGraphics.h"
#include "Program.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

namespace MKEngine {

	class Camera
	{
	public:
		Camera();
		~Camera();
		void init(MKGraphics::Program& program);

		void perspective(float fov, float aspectRatio, float near, float far);

		void rotate(float x, float y, float speed);
		void forward(float speed);
		void backward(float speed);
		void right(float speed);
		void left(float speed);
		void up(float speed);
		void down(float speed);

		void update(double time);
		void use();

		glm::vec3 _up;
		glm::vec3 _right;
		glm::vec3 _forward;

	private:
		MKGraphics::Program *_program;

		glm::vec3 _position;
		glm::vec3 _direction;

		glm::vec3 _translation;
		float _rotationUp;
		float _rotationRight;

		glm::mat4 _model;
		glm::mat4 _view;
		glm::mat4 _projection;

		int _modelLocation;
		int _viewLocation;
		int _projectionLocation;
	};

}