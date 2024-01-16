#include "player.hpp"
#include <raylib.h>
#include <raymath.h>
#include <rcamera.h>
#include "draw.h"

Player::Player()
: Player::Entity({ 0, 2, 0 }, { 1, 2, 1 }) {
    color = { 0, 255, 255, 128 };

    speed = 4;
    sensitivity = 0.003f;

    float head = position.y + size.y - 0.5f;

    camera_mode = CAMERA_FIRST_PERSON;
    camera = {
        .position = { 0, head, 0 },
        .target = { 1, head, 1 },
        .up = { 0, 1, 0 },
        .fovy = 65,
        .projection = CAMERA_PERSPECTIVE,
    };
}

Player::~Player() {}

void Player::draw() {}
void Player::process() {}

void Player::move() {
    float delta = GetFrameTime();

    Vector3 move = {0};

    move.x = IsKeyDown(KEY_W) + -IsKeyDown(KEY_S);
    move.y = IsKeyDown(KEY_SPACE) + -IsKeyDown(KEY_LEFT_CONTROL);
    move.z = -IsKeyDown(KEY_A) + IsKeyDown(KEY_D);

    bool running = IsKeyDown(KEY_LEFT_SHIFT);
    float velocity = speed;

    if (running) {
        velocity *= 1.75;
        fov = 70;
    } else {
        fov = 65;
    }

    move = Vector3Scale(move, velocity * delta);

    CameraMoveForward(&camera, move.x, true);
    CameraMoveUp(&camera, move.y);
    CameraMoveRight(&camera, move.z, true);

    /////position = Vector3Subtract(camera.position, size);
    position.x = camera.position.x - size.x / 2;
    position.y = camera.position.y - size.y + 0.5f;
    position.z = camera.position.z - size.z / 2;
}

void Player::look() {
    Vector2 mouse = GetMouseDelta();

    CameraYaw(&camera, -mouse.x * sensitivity, false);
    CameraPitch(&camera, -mouse.y * sensitivity, true, false, false);
}


const float&      Player::Speed()       const { return speed; }
const float&      Player::Sensitivity() const { return sensitivity; }
const Camera3D&   Player::Camera()      const { return camera; }
const CameraMode& Player::CameraMode()  const { return camera_mode; }

