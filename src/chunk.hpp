#pragma once
#include <raylib.h>
#include <raymath.h>
#include <vector>

using std::vector;

#define CHUNK_SIZE 8

class Chunk {
    private:
        bool block[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];

    public:
        Chunk();

        ~Chunk();

        void draw(Vector3 origin);
        void process();
};

