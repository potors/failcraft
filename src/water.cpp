#include "water.hpp"
#include "chunk.hpp"
#include <raylib.h>

Drop::Drop()
: Drop({0}) {}

Drop::Drop(Vector3 at)
: Drop::Entity(at, { 0.075, 0.675, 0.075 }) {
    color = { 75, 120, 255, 180 };
    speed = 42;
}

Drop::Drop(Vector2 from, Vector2 to)
: Drop({
    .x = (float) GetRandomValue(from.x, to.x),
    .y = (float) GetRandomValue(CHUNK_SIZE, CHUNK_SIZE * CHUNK_SIZE),
    .z = (float) GetRandomValue(from.y, to.y)
}) {}

Drop::~Drop() {}

void Drop::draw() {
    DrawCubeV(position, size, color);
}

bool Drop::fall(std::function<bool (const float)> dropped) {
    float delta = GetFrameTime();

    position.y -= speed * delta;

    return dropped(position.y);
}

void Drop::regen(Vector2 from, Vector2 to) {
    position = {
        .x = (float) GetRandomValue(from.x, to.x),
        .y = (float) GetRandomValue(CHUNK_SIZE, CHUNK_SIZE * CHUNK_SIZE),
        .z = (float) GetRandomValue(from.y, to.y)
    };
}
