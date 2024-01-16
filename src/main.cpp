#include <algorithm>
#include <raylib.h>
#include <rcamera.h>
#include <raymath.h>
#include "draw.h"
#include <vector>

//#include "entity.hpp"
#include "player.hpp"
#include "chunk.hpp"
#include "water.hpp"

#define WIDTH  800
#define HEIGHT 600
#define TITLE  "MINECRAFT!"

int main(void) {
    SetRandomSeed(0);

    Player player;
    std::vector<std::vector<Chunk>> chunks(4);
    std::generate(chunks.begin(), chunks.end(), []() { return std::vector<Chunk>(4); });

    bool raining = true;
    Drop drops[4 * 4][CHUNK_SIZE * CHUNK_SIZE];

    InitWindow(WIDTH, HEIGHT, TITLE);
    DisableCursor();
    SetTargetFPS(0);

    while (!WindowShouldClose()) {
        player.move();
        player.look();
        
//        for (std::vector<Chunk>& row : chunks) {
//            for (Chunk& chunk : row) {
//                chunk.process();
//            }
//        }

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

                        if (!raining) continue;
                        for (int d = 0; d < CHUNK_SIZE; d++) {
                            Drop& drop = drops[i + j][d];

                            bool dropped = drop.fall([](float y) { return y < 0; });
                            if (dropped) {
                                Vector2 from = { origin.x, origin.z };
                                drop.regen(from, Vector2AddValue(from, CHUNK_SIZE));
                            }

                            drop.draw();
                        }
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
