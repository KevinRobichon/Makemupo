#include "Camera.h"

namespace MKEngine {

	Camera::Camera()
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::init(MKGraphics::Program& program)
	{
		_program = &program;
		_up = glm::vec3(0.0, 1.0, 0.0);
		_right = glm::vec3(1.0, 0.0, 0.0);
		_forward = glm::vec3(0.0, 0.0, -1.0);

		_position = glm::vec3(0.0, 0.0, 0.0);
		_direction = _forward;

		_translation = glm::vec3(0.0);

		_model = glm::mat4(1.0);
		_view = glm::mat4(1.0);
		_projection = glm::mat4(1.0);

		_modelLocation = _program->uniformLocation("model");
		_viewLocation = _program->uniformLocation("view");
		_projectionLocation = _program->uniformLocation("projection");
	}

	void Camera::perspective(float fov, float aspectRatio, float near, float far)
	{
		_projection = glm::perspective(fov, aspectRatio, near, far);
	}

	void Camera::forward(float speed)
	{
		_translation += _forward * speed;
	}

	void Camera::backward(float speed)
	{
		_translation -= _forward * speed;
	}

	void Camera::update(double time)
	{
		_position += _translation * (float)time;
		_translation = glm::vec3(0.0);

		_view = glm::lookAt(_position, _position + _direction, _up);
	}

	void Camera::use()
	{
		_program->uniformMatrix4f(_modelLocation, MKGraphics::Bool::True, glm::value_ptr(_model));
		_program->uniformMatrix4f(_viewLocation, MKGraphics::Bool::True, glm::value_ptr(_view));
		_program->uniformMatrix4f(_projectionLocation, MKGraphics::Bool::True, glm::value_ptr(_projection));
	}

}