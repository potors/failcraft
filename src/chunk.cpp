#include "chunk.hpp"
#include <raylib.h>
#include <raymath.h>
#include "draw.h"

Chunk::Chunk() {
    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = 0; y < CHUNK_SIZE; y++) {
            for (int z = 0; z < CHUNK_SIZE; z++) {
                block[x][y][z] = y == 0;
            }
        }
    }
}

Chunk::~Chunk() {}

void Chunk::draw(Vector3 origin) {
    DrawCubeWiresO(origin, { CHUNK_SIZE, CHUNK_SIZE, CHUNK_SIZE }, YELLOW);

    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int y = 0; y < CHUNK_SIZE; y++) {
            for (int z = 0; z < CHUNK_SIZE; z++) {
                if (block[x][y][z]) {
                    Vector3 position = { (float) x, (float) y, (float) z };
                    Vector3 size = { 1, 1, 1 };

                    Color color = ColorFromHSV((((
                        (int) origin.x + x
                        + (int) origin.y + y
                        + (int) origin.z + z) * 20) % 360), 85, 50);

                    DrawCubeO(Vector3Add(origin, position), size, color);
                }
            }
        }
    }
}

void Chunk::process() {
}
