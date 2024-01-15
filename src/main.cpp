#include <raylib.h>
#include <rcamera.h>
#include <raymath.h>
#include "draw.hpp"

//#include "entity.hpp"
#include "player.hpp"
//#include "chunk.hpp"

#define WIDTH  800
#define HEIGHT 600
#define TITLE  "3D Purple Rain"

int main(void) {
    SetRandomSeed(0);

    Player player;

    InitWindow(WIDTH, HEIGHT, TITLE);
    DisableCursor();
    SetTargetFPS(0);

    while (!WindowShouldClose()) {
        player.move();
        player.look();

        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode3D(player.Camera());
                //DrawCubeWires({1, 1, 1}, 2, 2, 2, BLACK);
                DrawCubeV({0}, {2, 2, 2}, GREEN);
                DrawCubeWiresV({0}, {2, 2, 2}, PURPLE);
                player.draw();
            EndMode3D();


            DrawRectangle(5, 35, 335, 30, BLUE);
            DrawText(
                TextFormat("Position: [%06.3f, %06.3f, %06.3f]",
                    player.Position().x,
                    player.Position().y,
                    player.Position().z
                ), 10, 40, 20, BLACK
            );
            
            DrawFPS(0, 0);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
