#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Entity.h"
#include "Camera.h"

class Transformations {
public:
	static glm::mat4 createModelMatrix(const Entity& entity) {
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, entity.getPosition());
		model = glm::rotate(model, glm::radians(entity.getRotX()),glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(entity.getRotY()), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(entity.getRotZ()), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::scale(model, glm::vec3(entity.getScale()));
		//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		return model;
	}

	static glm::mat4 createViewMatrix(const Camera& camera) {
		glm::mat4 view = glm::mat4(1.0f);
		
		view = glm::rotate(view, glm::radians(camera.getPitch()), glm::vec3(1.0f, 0.0f, 0.0f));
		view = glm::rotate(view, glm::radians(camera.getYaw()), glm::vec3(0.0f, 1.0f, 0.0f));
		view = glm::rotate(view, glm::radians(camera.getRoll()), glm::vec3(0.0f, 0.0f, 1.0f));
		
		glm::vec3 pos = camera.getPosition();
		view = glm::translate(view, glm::vec3(-pos.x, -pos.y, -pos.z));
		
		return view;
	}

	static glm::mat4 createTransformationMatrix(const glm::vec3 position, float rotX, float rotY, float rotZ, float scale) {
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, position);
		model = glm::rotate(model, glm::radians(rotX), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotY), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(rotZ), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::scale(model, glm::vec3(scale));
		//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		return model;
	}
};