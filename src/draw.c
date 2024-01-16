#include "draw.h"

/*
 * Remainder to myself:
 * * Each "chunk" of `rlVertex3f` is one point of the triangle
 * * Each face has 2 triangles
 * * Don't understand shit? Try to see the pattern on the front face (first 2 triangles)
 * * `origin` expands to `size`
 * * * What? { 0, 0, 0 }, { 2, 2, 2 }
 * * * -> will result in a cube starting at { 0, 0, 0 } and ending at { 2, 2, 2 }
 * * * -> instead of { -1, -1, -1 }, { 1, 1, 1 }
 */

void DrawCubeO(Vector3 origin, Vector3 size, Color color) {
    float x = size.x;
    float y = size.y;
    float z = size.z;

    rlPushMatrix();
        rlTranslatef(origin.x, origin.y, origin.z);

        rlBegin(RL_TRIANGLES);
            rlColor4ub(color.r, color.g, color.b, color.a);

            // Front
                // Bottom-Left Triangle
                rlVertex3f(0, 0, z); // Left  Bottom
                rlVertex3f(x, 0, z); // Right Bottom
                rlVertex3f(0, y, z); // Left  Top

                // Top-Right Triangle
                rlVertex3f(x, y, z); // Right Top
                rlVertex3f(0, y, z); // Left  Top
                rlVertex3f(x, 0, z); // Right Bottom

            // Back
                // Bottom-Left Triangle
                rlVertex3f(0, 0, 0); // Left  Bottom
                rlVertex3f(0, y, 0); // Left  Top
                rlVertex3f(x, 0, 0); // Right Bottom

                // Top-Right Triangle
                rlVertex3f(x, y, 0); // Right Top
                rlVertex3f(x, 0, 0); // Right Bottom
                rlVertex3f(0, y, 0); // Left  Top

            // Top
                // Bottom-Left Triangle
                rlVertex3f(0, y, z); // Left  Top
                rlVertex3f(x, y, 0); // Right Bottom
                rlVertex3f(0, y, 0); // Left  Bottom

                // Top-Right Triangle
                rlVertex3f(x, y, z); // Right Top
                rlVertex3f(z, y, 0); // Left  Top
                rlVertex3f(0, y, x); // Right Bottom

            // Bottom
                // Bottom-Left Triangle
                rlVertex3f(0, 0, z); // Left  Top
                rlVertex3f(0, 0, 0); // Left  Bottom
                rlVertex3f(x, 0, 0); // Right Bottom

                // Top-Right Triangle
                rlVertex3f(x, 0, z); // Right Top
                rlVertex3f(0, 0, z); // Left  Top
                rlVertex3f(x, 0, 0); // Right Bottom

            // Right
                // Bottom-Left Triangle
                rlVertex3f(x, 0, 0); // Right Bottom
                rlVertex3f(x, y, 0); // Right Top
                rlVertex3f(x, 0, z); // Left  Top

                // Top-Right Triangle
                rlVertex3f(x, y, z); // Right Top
                rlVertex3f(x, 0, z); // Right Bottom
                rlVertex3f(x, y, 0); // Left  Top

            // Left
                // Bottom-Left Triangle
                rlVertex3f(0, 0, 0); // Right Bottom
                rlVertex3f(0, 0, z); // Right Top
                rlVertex3f(0, y, 0); // Left  Top

                // Top-Right Triangle
                rlVertex3f(0, y, z); // Right Top
                rlVertex3f(0, y, 0); // Right Bottom
                rlVertex3f(0, 0, z); // Left  Top

        rlEnd();
    rlPopMatrix();
}

void DrawCubeWiresO(Vector3 origin, Vector3 size, Color color) {
    float x = size.x;
    float y = size.y;
    float z = size.z;

    rlPushMatrix();
        rlTranslatef(origin.x, origin.y, origin.z);

        rlBegin(RL_LINES);
            rlColor4ub(color.r, color.g, color.b, color.a);

            // Front
                // Bottom
                rlVertex3f(0, 0, z);  // Bottom left
                rlVertex3f(x, 0, z);  // Bottom right

                // Left
                rlVertex3f(x, 0, z);  // Bottom right
                rlVertex3f(x, y, z);  // Top right

                // Top
                rlVertex3f(x, y, z);  // Top right
                rlVertex3f(0, y, z);  // Top left

                // Right
                rlVertex3f(0, y, z);  // Top left
                rlVertex3f(0, 0, z);  // Bottom left

            // Back
                // Bottom
                rlVertex3f(0, 0, 0);  // Bottom left
                rlVertex3f(x, 0, 0);  // Bottom right

                // Left
                rlVertex3f(x, 0, 0);  // Bottom right
                rlVertex3f(x, y, 0);  // Top right

                // Top
                rlVertex3f(x, y, 0);  // Top right
                rlVertex3f(0, y, 0);  // Top left

                // Right
                rlVertex3f(0, y, 0);  // Top left
                rlVertex3f(0, 0, 0);  // Bottom left

            // Top
                // Left
                rlVertex3f(0, y, z);  // Top left front
                rlVertex3f(0, y, 0);  // Top left back

                // Right
                rlVertex3f(x, y, z);  // Top right front
                rlVertex3f(x, y, 0);  // Top right back

            // Bottom
                // Left
                rlVertex3f(0, 0, z);  // Top left front
                rlVertex3f(0, 0, 0);  // Top left back

                // Right
                rlVertex3f(x, 0, z);  // Top right front
                rlVertex3f(x, 0, 0);  // Top right back
        rlEnd();
    rlPopMatrix();
}

