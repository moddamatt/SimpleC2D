/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "include/raylib.h"
#include "include/rlgl.h"

void MyCube();
void PandR(float xPos, float yPos, float zPos, float xAxisAngle, float yAxisAngle, float zAxisAngle);

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Camera camera = {{0.0f, 10.0f, 10.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 45.0f, 0};
    SetCameraMode(camera, CAMERA_ORBITAL);

    float xPos = 0.0f;
    float yPos = 0.0f;
    float zPos = 0.0f;

    float xAxisAngle = 0.0f;
    float yAxisAngle = 0.0f;
    float zAxisAngle = 0.0f;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);

        if (xAxisAngle != 360)
            xAxisAngle += 1.0f;
        else
            xAxisAngle = 0.0f;

        if (yAxisAngle != 360)
            yAxisAngle += 1.0f;
        else
            yAxisAngle = 0.0f;

        if (zAxisAngle != 360)
            zAxisAngle += 1.0f;
        else
            zAxisAngle = 0.0f;
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        rlPushMatrix();
        //PandR(xPos, yPos, zPos, xAxisAngle, yAxisAngle, zAxisAngle);
        MyCube();
        rlPopMatrix();

        EndMode3D();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

void MyCube()
{

    rlBegin(RL_QUADS);
    rlColor3f(0.0f, 1.0f, 0.0f);
    rlVertex3f(1.0f, 1.0f, -1.0f);
    rlVertex3f(-1.0f, 1.0f, -1.0f);
    rlVertex3f(-1.0f, 1.0f, 1.0f);
    rlVertex3f(1.0f, 1.0f, 1.0f);

    rlVertex3f(1.0f, -1.0f, 1.0f);
    rlVertex3f(-1.0f, -1.0f, 1.0f);
    rlVertex3f(-1.0f, -1.0f, -1.0f);
    rlVertex3f(1.0f, -1.0f, -1.0f);

    rlVertex3f(1.0f, 1.0f, 1.0f);
    rlVertex3f(-1.0f, 1.0f, 1.0f);
    rlVertex3f(-1.0f, -1.0f, 1.0f);
    rlVertex3f(1.0f, -1.0f, 1.0f);

    rlVertex3f(1.0f, -1.0f, -1.0f);
    rlVertex3f(-1.0f, -1.0f, -1.0f);
    rlVertex3f(-1.0f, 1.0f, -1.0f);
    rlVertex3f(1.0f, 1.0f, -1.0f);

    rlVertex3f(-1.0f, 1.0f, 1.0f);
    rlVertex3f(-1.0f, 1.0f, -1.0f);
    rlVertex3f(-1.0f, -1.0f, -1.0f);
    rlVertex3f(-1.0f, -1.0f, 1.0f);

    rlVertex3f(1.0f, 1.0f, -1.0f);
    rlVertex3f(1.0f, 1.0f, 1.0f);
    rlVertex3f(1.0f, -1.0f, 1.0f);
    rlVertex3f(1.0f, -1.0f, -1.0f);
    rlEnd();
}

void PandR(float xPos, float yPos, float zPos, float xAxisAngle, float yAxisAngle, float zAxisAngle)
{
    //TODO: ROTATE AND TRANSLATE
    rlTranslatef(xPos, yPos, zPos);
    rlRotatef(xAxisAngle, 1.0f, 0.0f, 0.0f);
    rlRotatef(yAxisAngle, 0.0f, 1.0f, 0.0f);
    rlRotatef(zAxisAngle, 0.0f, 0.0f, 1.0f);
}