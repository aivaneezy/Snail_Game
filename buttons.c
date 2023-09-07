
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "buttons.h"
#include <stdbool.h>

bool game = true;

void createGui()
{
	GUIWindow = SDL_CreateWindow("GUI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	if (GUIWindow == NULL)
	{
		printf(" Error window: SDL_ERROR:%s", SDL_GetError());
	}

	GUIRenderer = SDL_CreateRenderer(GUIWindow,-1,  SDL_RENDERER_ACCELERATED);

	if (GUIRenderer == NULL)
	{
		printf("Error renderer: SDL_ERROR: %s", SDL_GetError());
	}

	// rendering images into the window
	loadGuiImage();

	while (game)
	{
		events();
		
		updateGui();
	}
}

void events()
{

	SDL_Event event;
	while (SDL_PollEvent(&event) > 0)
	{
		if (event.type == SDL_QUIT)
		{
			game = false;
			printf("Window is closed...");
			SDL_Quit();

		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				int mouseX = event.button.x;
				int mouseY = event.button.y;
				if (isMouseClicked(mouseX, mouseY, rectStartUp))
				{
					game = false;
					SDL_DestroyWindow(GUIWindow);
				}
				else if (isMouseClicked(mouseX, mouseY, rectExitUp))
				{
					SDL_Quit();
				}
				
			}
		}
		
	}
}

void loadGuiImage()
{
	int flags = IMG_INIT_PNG;
	if (IMG_Init(flags) != flags)
	{
		printf("SDL_Image format error: SDL_ERROR:%s", SDL_GetError());
	}

	loadBackground();
	loadStartup();
	loadExitup();

}

SDL_Texture* loadGuiTexture(const char *filename, SDL_Renderer* ren)
{
	surface = IMG_Load(filename);
	if (surface == NULL)
	{
		printf("Cannot create a surface. SDL_ERROR: %s", SDL_GetError());
	}

	textureBackground = SDL_CreateTextureFromSurface(ren, surface);
	if (textureBackground == NULL)
	{
		printf("cannot create a texture from surface. SDL_ERROR: %s", SDL_GetError());
	}

	return textureBackground;
}

// background of the GUI
void loadBackground()
{
	rectBackground.w = WIDTH;
	rectBackground.h = HEIGHT;
	bb = loadGuiTexture("C:\\Users\\Golden\\Desktop\\vscodeMicrosfo\\idk\\idk\\src\\GUI-backgrond.png", GUIRenderer);
}

// start button
void loadStartup()
{
	rectStartUp.x = WIDTH / 2 - 100;
	rectStartUp.y = 100;
	rectStartUp.w = 200;
	rectStartUp.h = 200;

	startup = loadGuiTexture("C:\\Users\\Golden\\Desktop\\vscodeMicrosfo\\idk\\idk\\src\\start.png", GUIRenderer);
}

void loadExitup()
{
	rectExitUp.x = WIDTH / 2 - 100;
	rectExitUp.y = 300;                                          
	rectExitUp.w = 200;
	rectExitUp.h = 200;                               

	exitup = loadGuiTexture("C:\\Users\\Golden\\Desktop\\vscodeMicrosfo\\idk\\idk\\src\\exit.png", GUIRenderer);
}

bool isMouseClicked(int mouseX, int mouseY, SDL_Rect buttonRect) {
	return mouseX >= buttonRect.x && mouseX < (buttonRect.x + buttonRect.w) &&
		mouseY >= buttonRect.y && mouseY < (buttonRect.y + buttonRect.h);
}
                                                                    
void updateGui()
{
	SDL_RenderClear(GUIRenderer);

	SDL_SetRenderDrawColor(GUIRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

	SDL_RenderCopy(GUIRenderer, bb, NULL, &rectBackground); // loading up bacground into the window
	SDL_RenderCopy(GUIRenderer, startup, NULL, &rectStartUp);
	SDL_RenderCopy(GUIRenderer, exitup, NULL, &rectExitUp);
	SDL_RenderPresent(GUIRenderer);
}

