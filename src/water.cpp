#include "water.hpp"
#include "chunk.hpp"
#include <locale.h>
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

void Drop::process() {}

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


Lightning::Lightning()
: Lightning({0}) {}

Lightning::Lightning(Vector3 at)
: Lightning::Entity(at, { 1, 128, 1 }) {
    color = { 255, 255, 150, 230 };
    duration = GetRandomValue(100, 600);
}

Lightning::Lightning(Vector2 from, Vector2 to)
: Lightning({
    .x = (float) GetRandomValue(from.x, to.x),
    .y = 0,
    .z = (float) GetRandomValue(from.y, to.y),
}) {}

Lightning::~Lightning() {}

void Lightning::draw() {
    float delta = GetFrameTime();

    DrawCubeV(position, size, color);
    
    duration -= delta * 1000;
}

void Lightning::process() {}

const float& Lightning::Duration() const { return duration; }
