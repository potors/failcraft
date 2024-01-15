#pragma once
#include "raylib.h"
#include "entity.hpp"

class Player : public Entity {
    private:
        float speed;
        float sensitivity;
        float& fov = camera.fovy;

        Camera3D camera;
        CameraMode camera_mode;

    public:
        Player();

        ~Player();

        void draw() override;

        void move();
        void look();

        const float&      Speed()       const;
        const float&      Sensitivity() const;
        const Camera3D&   Camera()      const;
        const CameraMode& CameraMode()  const;
};
