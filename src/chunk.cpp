#include "chunk.hpp"
#include <raylib.h>
#include "draw.h"

Chunk::Chunk() {
    for (int i = 0; i < CHUNK_SIZE; i++) {
        for (int j = 0; j < CHUNK_SIZE; j++) {
            for (int k = 0; k < CHUNK_SIZE; k++) {
                block[i][j][k] = GetRandomValue(0, 1) - GetRandomValue(0, 3) / 10;
            }
        }
    }
}

Chunk::~Chunk() {}

void Chunk::draw(Vector3 origin) {
    DrawCubeWiresO(origin, { CHUNK_SIZE, CHUNK_SIZE, CHUNK_SIZE }, YELLOW);

    for (int i = 0; i < CHUNK_SIZE; i++) {
        for (int j = 0; j < CHUNK_SIZE; j++) {
            for (int k = 0; k < CHUNK_SIZE; k++) {
                if (block[i][j][k]) {
                    Vector3 position = { (float) i, (float) j, (float) k };
                    Vector3 size = { 1, 1, 1 };

                    Color color = ColorFromHSV((((i + j + k) * 18) % 360), 100, 50);
                    DrawCubeO(Vector3Add(origin, position), size, color);
                }
            }
        }
    }
}

void Chunk::process() {

}
