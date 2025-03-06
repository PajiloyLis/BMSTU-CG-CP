#ifndef CP_CG_CAMERA_H
#define CP_CG_CAMERA_H

#include "conversions.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

using namespace std;

enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const float YAW = 0.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.01f;
const float ZOOM = 45.0f;


class camera {
public:
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    float Yaw;
    float Pitch;
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    float relation;

    glm::mat4 model;

    camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 0.0f, 1.0f),
           float yaw = YAW, float pitch = PITCH) : Front(glm::vec3(-1.0f, 0.0f, 0.0f)), MovementSpeed(SPEED),
                                                   MouseSensitivity(SENSITIVITY), Zoom(ZOOM), relation(16.f / 9) {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }

    camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(
            glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM), relation(
            3.f / 4) {
        Position = glm::vec3(posX, posY, posZ);
        WorldUp = glm::vec3(upX, upY, upZ);
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }

    [[nodiscard]] glm::mat4 camLookAt() const {
        return glm::lookAt(Position, Position + Front, Up);
    }

    void move(Camera_Movement direction, float delta_time) {
        float velocity = MovementSpeed;
        if (direction == FORWARD) {
//            model = glm::translate(glm::mat4(1.f), -Front);
            Position += Up * velocity;
        }
        if (direction == BACKWARD) {
//            model = glm::translate(glm::mat4(1.f), Front);
            Position -= Up * velocity;
            if (Position.z < 0)
                Position.z = 0;
        }
        if (direction == LEFT) {
//            model = glm::translate(glm::mat4(1.f), Right);
            Position += Right * velocity;
        }
        if (direction == RIGHT) {
//            model = glm::translate(glm::mat4(1.f), -Right);
            Position -= Right * velocity;
        }
        cout << "camera moved \npos " << Position.x << " " << Position.y << " " << Position.z << "\npov " << Front.x
             << " " << Front.y << " " << Front.z << '\n';
    }

    void rotate(float xoffset, float yoffset, bool constrainPitch = true) {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw += xoffset;
        Pitch += yoffset;

        if (constrainPitch) {
            if (Pitch > 89.0f)
                Pitch = 89.0f;
            if (Pitch < -89.0f)
                Pitch = -89.0f;
        }

        updateCameraVectors();

        cout << "camera rotated \npos " << Position.x << " " << Position.y << " " << Position.z << "\npov " << Front.x
             << " " << Front.y << " " << Front.z << '\n';
    }

    [[nodiscard]] glm::mat4 perspective() const {
        return glm::perspective(glm::radians(Zoom), relation, 0.1f, 400.f);
    }

    void scale(float yoffset) {
        Zoom -= (float) yoffset;
        if (Zoom < 1.0f)
            Zoom = 1.0f;
        if (Zoom > 45.0f)
            Zoom = 45.0f;
    }


private:
    void updateCameraVectors() {
        glm::vec3 front;
        front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        front.y = sin(glm::radians(Pitch));
        front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        Front = glm::normalize(front);
        Right = glm::normalize(glm::cross(Front,
                                          WorldUp));
        Up = glm::normalize(glm::cross(Right, Front));
    }
};

#endif //CP_CG_CAMERA_H
