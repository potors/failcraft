#pragma once
#include <raylib.h>
#include <raymath.h>
#include "entity.hpp"
#include <functional>

class Drop : public Entity {
    private:
        float speed;

    public:
        Drop();
        Drop(Vector3 at);
        Drop(Vector2 from, Vector2 to);

        ~Drop();

        void draw() override;

        bool fall(std::function<bool (const float)> dropped);
        void regen(Vector2 from, Vector2 to);
};


