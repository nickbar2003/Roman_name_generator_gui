#include "program.h"
#include <iostream>
#include <raylib.h>

using namespace std;

int main() {

  const int screenWidth = 800;
  const int screenHeight = 600;
  Vector2 gen_text = {210, 180};
  Vector2 prae_gen_cog_text = {80, 350};
  Vector2 name_text = {90, 300};
  Rectangle gen_button = {200, 150, 370, 100};
  // Rectangle gen_button = {200, 150, 370, 100};
  std::string name_buffer = "";
  const char *completeName = nullptr;

  InitWindow(screenWidth, screenHeight, "Roman Generator");
  SetTargetFPS(60);
  Font romanFont = LoadFont("fonts/romulus.png");
  while (WindowShouldClose() == false) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      if (CheckCollisionPointRec(GetMousePosition(), gen_button)) {
        name_buffer = generateCharacterName();
        completeName = name_buffer.c_str();
      }
    }

    BeginDrawing();
    ClearBackground(LIGHTGRAY);

    DrawRectangleRec(gen_button, MAROON);
    DrawTextEx(romanFont, "GENERATE NAME", gen_text, 30, 10, WHITE);
    if (completeName) {
      Rectangle name_button = {70, 300, name_buffer.size() * 27, 40};
      DrawRectangleRec(name_button, MAROON);
      DrawTextEx(romanFont, completeName, name_text, 30, 10, WHITE);
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}