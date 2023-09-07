#pragma once
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

// window size
#define WIN_HEIGHT 720
#define WIN_WIDTH 720

// snails size
#define SNAIL_HEIGHT 100
#define SNAIL_WIDTH 100

// players movement
#define SPEED 10;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Surface* surface;
SDL_Texture* texture;
SDL_Texture* player1;
SDL_Texture* player2;
SDL_Texture* flag_player1;
SDL_Texture* flag_player2;

SDL_Texture* background;


SDL_Rect snail1_src, snail1_des;
SDL_Rect snail2_src, snail2_des;
SDL_Rect flag1, flag2;
SDL_Rect background_size;




// function declaration
bool init_sdl();
void sdl_window();
void sdl_renderer();
void handle_input();
void update_sdl();
void clean_sdl();
SDL_Texture* load_texture(const char* filename, SDL_Renderer* renderer);\
void load_image();
void players_picture();
void game_ball();
void background_picture();
bool has_intersect();
void winners();

