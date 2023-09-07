#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include "main.h"
#include "buttons.h"

bool game_is_running = true;

bool init_sdl()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Cannot initialize SDL. SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	return true;
}

void sdl_window()
{
	window = SDL_CreateWindow("Snail", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Fail to create a window. SDL_ERROR:%s", SDL_GetError());
		SDL_Quit();
	}

}

void sdl_renderer()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Fail to create a renderer. SDL_ERROR:%s", SDL_GetError());

	}
}


void handle_input()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) > 0)
	{
		if (event.type == SDL_QUIT)
		{
			game_is_running = false;
			printf("Window is closed...");
			SDL_Quit();
		}
		else if (event.type == SDL_KEYDOWN) // if user press a key
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_d:
				snail1_des.x += SPEED;
				printf("player press d\n");
				break;
			case SDLK_RIGHT:
				snail2_des.x += SPEED;
				printf("player press arrow key \n");
				break;
			}
		}
	}
}

void update_sdl()
{
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);



	// rendering the sprite into the window
	SDL_RenderCopy(renderer, background, NULL, &background_size); // rendering background
	SDL_RenderCopy(renderer, player1, NULL, &snail1_des); // rendering player1 
	SDL_RenderCopy(renderer, player2, NULL, &snail2_des); // rendering player2
	SDL_RenderCopy(renderer, flag_player1, NULL, &flag1); // rendering flag
	SDL_RenderCopy(renderer, flag_player2, NULL, &flag2); // rendering flag


	SDL_RenderPresent(renderer);
}


void clean_sdl()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_Quit();

}



int main(int argc, char* argv[])
{
	if (!init_sdl())
	{
		return 1;
	}

	// calling the GUI WINDOW FUNCTION
	createGui();

	sdl_window(); // calling window function
	sdl_renderer(); // calling the renderer;
	load_image(); // loading image into the window;

	while (game_is_running)
	{
		handle_input(); // handling user input

		winners(); // calling winners function incase one of the snail touches the "ball"
		update_sdl();// updting sdl

	}

	clean_sdl(); // memory cleaning

	return 0;
}