#include "raylib.h"

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE); 
    InitWindow(600, 400, "CARBON CILENT");
    SetTargetFPS(180);

Vector3 centerPos = {0,0,0};
 int a = 300;
 Vector3 position = {1,a,1};
 Camera3D camera = { 5 };
    camera.position = (Vector3){ 150,91,200 }; // Camera position
    camera.target = (Vector3){ 10, 0, 0 };   // Camera looking at point
    camera.up = (Vector3){ 0, 1, 0 };       // Camera up vector (rotation axis)
    camera.fovy = 100;                             // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;          // Camera mode type

    while (!WindowShouldClose()) {
           DisableCursor();   
        BeginDrawing();
         UpdateCamera(&camera, CAMERA_FIRST_PERSON);
        BeginMode3D(camera); 
        ClearBackground(BLACK);
        DrawCubeWires(position,100,50,50,GREEN);
    int BASE = 30;
    int HEIGHTBASE = 5;


int gravity = 3;
double weight = 0.35;
int vel = weight*gravity;
a-=vel; 
position.y = a;
if(BASE>a){a++;}
position.y = a;
DrawGrid(BASE,10);//DrawPlane(centerPos,size,DARKGREEN);  
        EndMode3D();

        DrawFPS(0,1);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
