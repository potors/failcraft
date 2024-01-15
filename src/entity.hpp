#pragma once
#include "raylib.h"

class Entity {
    protected:
        Color color;
        Vector3 position;
        Vector3 size;

    public:
        Entity();
        Entity(Vector3 position, Vector3 size);

        virtual ~Entity();

        virtual void draw() = 0;

        const Color&   Color()    const;
        const Vector3& Position() const;
        const Vector3& Size()     const;
};
