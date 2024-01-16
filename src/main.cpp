#include <algorithm>
#include <raylib.h>
#include <rcamera.h>
#include <raymath.h>
#include "draw.h"
#include <vector>

//#include "entity.hpp"
#include "player.hpp"
#include "chunk.hpp"

#define WIDTH  800
#define HEIGHT 600
#define TITLE  "MINECRAFT!"

int main(void) {
    SetRandomSeed(0);

    Player player;
    std::vector<std::vector<Chunk>> chunks(8);
    std::generate(chunks.begin(), chunks.end(), []() { return std::vector<Chunk>(8); });

    InitWindow(WIDTH, HEIGHT, TITLE);
    DisableCursor();
    SetTargetFPS(0);

    while (!WindowShouldClose()) {
        player.move();
        player.look();
        
//       for (Chunk& chunk : chunks) {
//           chunk.process();
//       }

        BeginDrawing();
            ClearBackground(BLACK);

            BeginMode3D(player.Camera());
                DrawCubeWiresO(player.Position(), player.Size(), player.Color());
                player.draw();

                for (int i = 0; i < chunks.size(); i++) {
                    std::vector<Chunk>& row = chunks[i];

                    for (int j = 0; j < row.size(); j++) {
                        Chunk& chunk = row[j];

                        Vector3 origin = { (float) i * CHUNK_SIZE, 0, (float) j * CHUNK_SIZE };
                    
                        chunk.draw(origin);
                    }
                }
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
