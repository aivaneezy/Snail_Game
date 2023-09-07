#pragma once
#include "main.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>


#define WIDTH 720
#define HEIGHT 720

SDL_Window* GUIWindow;
SDL_Renderer* GUIRenderer;
SDL_Texture* textureBackground;
SDL_Surface* guiSurface;

SDL_Texture* bb;
SDL_Texture* startup;
SDL_Texture* exitup;
SDL_Rect rectBackground, rectStartUp, rectExitUp;




void createGui();
void updateGui();
void events();
void loadGuiImage();
SDL_Texture* loadGuiTexture(const char *filename, SDL_Renderer* ren);
void loadBackground();
void loadStartup();
void loadExitup();
bool isMouseClicked(int mouseX, int mouseY, SDL_Rect buttonRect);