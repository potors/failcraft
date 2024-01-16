#include <raylib.h>
#include <rcamera.h>
#include <raymath.h>
#include "draw.h"

//#include "entity.hpp"
#include "player.hpp"
#include "chunk.hpp"

#define WIDTH  800
#define HEIGHT 600
#define TITLE  "MINECRAFT!"

int main(void) {
    SetRandomSeed(0);

    Player player;
    Chunk chunk;

    InitWindow(WIDTH, HEIGHT, TITLE);
    DisableCursor();
    SetTargetFPS(0);

    while (!WindowShouldClose()) {
        player.move();
        player.look();
        chunk.process();

        BeginDrawing();
            ClearBackground(BLACK);

            BeginMode3D(player.Camera());
                DrawCubeWiresO(player.Position(), player.Size(), player.Color());
                player.draw();

                chunk.draw({0});
            EndMode3D();

            // debug
            DrawRectangle(5, 35, 335, 30, BLUE);
            DrawText(
                TextFormat("Position: [%06.3f, %06.3f, %06.3f]",
                    player.Position().x,
                    player.Position().y,
                    player.Position().z
                ), 10, 40, 20, BLACK
            );
            // end debug

            DrawFPS(0, 0);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
