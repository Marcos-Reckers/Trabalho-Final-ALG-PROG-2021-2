#include "raylib.h"
#include "pauseMenu.h"
#include "settings.h"
#include "header.h"

void game(cfg *settings)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    settings->frames_counter = 0;
    settings->exit_window = false;
    settings->pause = false;
    settings->pause_select = 0;
    settings->fx_select = LoadSound("Assets/NESBattleCityJPNSoundEffects/BattleCitySFX5.wav");

    // Player
    settings->player_lives = 3;
    settings->player_score = 1600;
    settings->player_speed = 5;
    settings->player_pos.x = GetScreenWidth() / 2;
    settings->player_pos.y = GetScreenHeight() / 50;
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!settings->exit_window && !WindowShouldClose())
    {

        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_ESCAPE))
        {   
            PlaySound(settings->fx_select);
            WaitTime(10);
            settings->pause = true;
        }

        else
        {
            settings->frames_counter++;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        pauseMenu(settings);
        header(settings);

        DrawText("Hello World!", 100, 100, 20, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------

        if (WindowShouldClose())
        {
            settings->select = 4;
            break;
        }

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadSound(settings->fx_select);
    //--------------------------------------------------------------------------------------
}