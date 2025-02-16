#ifndef CP_CG_CAMERA_H
#define CP_CG_CAMERA_H

#include <my_vec3f.h>
#include "conversions.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class camera {
public:
    // Камера позиция, цель и вектор "вверх"
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;

    // Углы эйлера для вращения камеры
    float yaw;
    float pitch;

    // Скорость движения
    float movementSpeed;
    float mouseSensitivity;

    camera(glm::vec3 startPosition, glm::vec3 startUp,
           float startYaw, float startPitch)
            : front(glm::vec3(0.0f, 0.0f, -1.0f)),
              movementSpeed(2.5f), mouseSensitivity(0.1f) {
        position = startPosition;
        up = startUp;
        yaw = startYaw;
        pitch = startPitch;
        updateCameraVectors();
    }

    // Обновление векторов камеры на основе углов эйлера
    void updateCameraVectors() {
        // Calculate the new Front vector
        glm::vec3 front;
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        this->front = glm::normalize(front);

        // Also re-calculate the Right and Up vector
        right = glm::normalize(glm::cross(this->front, up));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        up = glm::normalize(glm::cross(right, this->front));
    }

    // Обработка движения камеры
    void processKeyboard(char direction, float deltaTime) {
        float velocity = movementSpeed * deltaTime;
        if (direction == 'W') // Move forward
            position += front * velocity;
        if (direction == 'S') // Move backward
            position -= front * velocity;
        if (direction == 'A') // Move left
            position -= right * velocity;
        if (direction == 'D') // Move right
            position += right * velocity;
    }

    // Обработка движения мыши
    void processMouseMovement(float xOffset, float yOffset, GLboolean constrainPitch = true) {
        xOffset *= mouseSensitivity;
        yOffset *= mouseSensitivity;

        yaw += xOffset;
        pitch -= yOffset;

        // Убедимся, что "pitch" остается в пределах
        if (constrainPitch) {
            if (pitch > 89.0f)
                pitch = 89.0f;
            if (pitch < -89.0f)
                pitch = -89.0f;
        }

        updateCameraVectors();
    }

    // Получение матрицы вида
    glm::mat4 getViewMatrix() {
        return glm::lookAt(position, position + front, up);
    }
};

//
//class camera {
//public:
//    camera() = default;
//
//camera(const my_vec3f &pos, const my_vec3f &pov, const my_vec3f &global_up, float relation);
//
//    camera(const my_vec3f &pos, const my_vec3f &pov, const my_vec3f &global_up, float width, float height);
//
//    camera(const camera &c);
//
//    camera& operator=(const camera &);
//
//    camera(camera &&c) noexcept;
//
//    [[nodiscard]] mat4 perspective() const;
//
//    [[nodiscard]] mat4 camLookAt() const;
//
//    void rotate(const rotate_t &rotate);
//
//    void scale(float &scale);
//
//    my_vec3f pos, front, up, right, global_up;
//    float near_distance = 0.1;
//    float relation;
//    float angle_of_view=45;
//    float far_distance = 100;
//
//    void move(const move_t &move);
//};
//
//
#endif //CP_CG_CAMERA_H
