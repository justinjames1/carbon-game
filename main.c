#include "raylib.h"

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE); 
    InitWindow(600, 400, "CARBON CILENT");
    SetTargetFPS(180);

Vector3 centerPos = {0,0,0};

 int camY = 500;
 int a = 300;
 Vector3 position = {1,a,1};
 Camera3D camera = { 5 };
    camera.position = (Vector3){ 150,camY,200 }; // Camera position
    camera.target = (Vector3){ 10, 0, 0 };   // Camera looking at point
    camera.up = (Vector3){ 0, 1, 0 };       // Camera up vector (rotation axis)
    camera.fovy = 100;                             // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;          // Camera mode type
    int BASE = 30;
    int HEIGHTBASE = 5;
    int load = 0;
    while (!WindowShouldClose()) { 
        BeginDrawing();
        ClearBackground(GRAY);
       DrawText("untiled 3d game", 100,20,50,BLACK); 
       DrawText("Hit enter to launch!", 100,100,35,BLACK); 
       if (IsKeyPressed(KEY_ENTER))
       {load = 1;}




        if(load == 1){
         UpdateCamera(&camera, CAMERA_FIRST_PERSON);
        BeginMode3D(camera); 
        ClearBackground(BLACK);
        DrawCubeWires(position,100,50,50,GREEN);

if (IsKeyPressed(KEY_M))
       {load = 0;}

int gravity = 3;
double weight = 0.35;
int vel = weight*gravity;
a-=vel; 
position.y = a;
if(BASE>a){a++;}
position.y = a;
DrawGrid(BASE,15);//DrawPlane(centerPos,size,DARKGREEN);
camY--;
camera.position.y = camY; 
if(camY<60){camY++;}
if (camY == -500){camY = 500;}

if (IsKeyPressed(KEY_SPACE))
{camY+=50;}
camera.position.y = camY; 
int LOCAL_X = camera.position.x;


        EndMode3D();
DrawText(TextFormat("Y: %i", camY), 0, 20, 20, GREEN);
DrawText(TextFormat("X: %i",LOCAL_X), 0, 40, 20, GREEN);
DrawText(TextFormat("M for menu"), 0, 60, 20, GREEN);
        }
        DrawFPS(0,1);
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
