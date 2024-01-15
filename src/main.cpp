#include <raylib.h>
#include <rcamera.h>
#include <raymath.h>
#include <vector>

#define WIDTH  800
#define HEIGHT 600
#define TITLE  "3D Purple Rain"

#define SENSITIVITY 0.003f

class Entity {
    protected:
        Color color;
};

class Entity2D : public Entity {
    protected:
        Vector2 position = {0};
        Vector2 size = {0};

    public:
        virtual void draw() = 0;
};

class Entity3D : public Entity {
    protected:
        Vector3 position = {0};
        Vector3 size = {0};

    public:
        virtual void draw() = 0;

        Vector3 pos() {
            return this->position;
        }
};


class Player : public Entity3D {
    public:
        float speed = 3.5;
        Camera3D camera = {0};
        CameraMode camera_mode = CAMERA_FIRST_PERSON;

        Player() {
            this->color = { 255, 255, 0, 128 };
            this->size = { 1, 2, 1 };

            this->camera.fovy = 70;
            this->camera.target = { 1, this->position.y + this->size.y - 0.5f, 1 };
            this->camera.position = { 0, this->position.y + this->size.y - 0.5f, 0 };
            this->camera.up.y = 1;
        }

        void draw() override {
            //DrawSphere(this->camera.target, 0.025f, DARKPURPLE);
            //DrawCubeV(Vector3Add(this->position, { 0, this->size.y - 1, 0 }), this->size, this->color);
            //DrawCubeWiresV(Vector3Add(this->position, { 0, this->size.y - 1, 0 }), this->size, PINK);
        }

        void move() {
            float delta = GetFrameTime();

            Vector3 move = {
                (float) IsKeyDown(KEY_W) + -IsKeyDown(KEY_S),
                0,
                (float) -IsKeyDown(KEY_A) + IsKeyDown(KEY_D)
            };

            bool running = IsKeyDown(KEY_LEFT_SHIFT);

            move.x *= (this->speed + running * (this->speed / 2)) * delta;
            move.z *= (this->speed + running * (this->speed / 2)) * delta;

            CameraMoveForward(&this->camera, move.x, true);
            CameraMoveRight(&this->camera, move.z, true);

            this->position.x = this->camera.position.x;
            this->position.z = this->camera.position.z;
        }

        void look() {
            Vector2 mouse = GetMouseDelta();

            bool rotate_around = this->camera_mode == CAMERA_THIRD_PERSON;
            
            CameraYaw(&this->camera, -mouse.x * SENSITIVITY, rotate_around);
            CameraPitch(&this->camera, -mouse.y * SENSITIVITY, true, rotate_around, false);
        }
};

class Drop : public Entity3D {
    public:
        Drop() {
            this->position = {0};
            this->size = { 0.1, 0.4, 0.1 };
            this->color = { 100, 75, 255, 255 };
        }

        void draw() override {
            DrawCubeV(this->position, this->size, this->color);
        }

        void fall(float speed) {
            this->position.y--;
        }
};

int main(void) {
    SetRandomSeed(0);

    Player player;

    InitWindow(WIDTH, HEIGHT, TITLE);
    DisableCursor();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        player.move();
        player.look();

        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode3D(player.camera);
                DrawPlane({0}, { 32.0f, 32.0f }, BLACK);

                player.draw();
            EndMode3D();

            DrawFPS(0, 0);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
