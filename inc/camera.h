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

// Default camera values
const float YAW = 0.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.01f;
const float ZOOM = 45.0f;


// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class camera {
public:
    // camera Attributes
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    // euler Angles
    float Yaw;
    float Pitch;
    // camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    float relation;

    glm::mat4 model;

    // constructor with vectors
    camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 0.0f, 1.0f),
           float yaw = YAW, float pitch = PITCH) : Front(glm::vec3(-1.0f, 0.0f, 0.0f)), MovementSpeed(SPEED),
                                                   MouseSensitivity(SENSITIVITY), Zoom(ZOOM), relation(16.f / 9) {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }

    // constructor with scalar values
    camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(
            glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM), relation(
            3.f / 4) {
        Position = glm::vec3(posX, posY, posZ);
        WorldUp = glm::vec3(upX, upY, upZ);
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }

    // returns the view matrix calculated using Euler Angles and the LookAt Matrix
    [[nodiscard]] glm::mat4 camLookAt() const {
        return glm::lookAt(Position, Position + Front, Up);
    }

    // processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    void move(Camera_Movement direction, float delta_time) {
        float velocity = MovementSpeed;
        if (direction == FORWARD) {
//            model = glm::translate(glm::mat4(1.f), -Front);
            Position += Up * velocity;
        }
        if (direction == BACKWARD) {
//            model = glm::translate(glm::mat4(1.f), Front);
            Position -= Up * velocity;
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

    // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    void rotate(float xoffset, float yoffset, bool constrainPitch = true) {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw += xoffset;
        Pitch += yoffset;

        // make sure that when pitch is out of bounds, screen doesn't get flipped
        if (constrainPitch) {
            if (Pitch > 89.0f)
                Pitch = 89.0f;
            if (Pitch < -89.0f)
                Pitch = -89.0f;
        }

        // update Front, Right and Up Vectors using the updated Euler angles
        updateCameraVectors();

        cout << "camera rotated \npos " << Position.x << " " << Position.y << " " << Position.z << "\npov " << Front.x
             << " " << Front.y << " " << Front.z << '\n';
    }

    [[nodiscard]] glm::mat4 perspective() const {
        return glm::perspective(glm::radians(Zoom), relation, 0.1f, 100.f);
    }

    // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    void scale(float yoffset) {
        Zoom -= (float) yoffset;
        if (Zoom < 1.0f)
            Zoom = 1.0f;
        if (Zoom > 45.0f)
            Zoom = 45.0f;
    }


private:
    // calculates the front vector from the camera's (updated) Euler Angles
    void updateCameraVectors() {
        // calculate the new Front vector
        glm::vec3 front;
        front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        front.y = sin(glm::radians(Pitch));
        front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        Front = glm::normalize(front);
        // also re-calculate the Right and Up vector
        Right = glm::normalize(glm::cross(Front,
                                          WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Up = glm::normalize(glm::cross(Right, Front));
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
