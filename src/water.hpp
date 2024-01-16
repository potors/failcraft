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
        void process() override;

        bool fall(std::function<bool (const float)> dropped);
        void regen(Vector2 from, Vector2 to);
};

class Lightning : public Entity {
    private:
        float duration;

    public:
        Lightning();
        Lightning(Vector3 at);
        Lightning(Vector2 from, Vector2 to);

        ~Lightning();

        void draw() override;
        void process() override;

        const float& Duration() const;
};
