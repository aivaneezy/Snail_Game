#include "main.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>



void load_image()
{
	int flags = IMG_INIT_PNG;
	if (IMG_Init(flags) != flags)
	{
		printf("SDL_Image format error: SDL_ERROR:%s", SDL_GetError());
	}
	// loading up backgroudnd;
	background_picture();


	// player1 image
	players_picture();


	//loading up ball image
	game_ball();




}


SDL_Texture* load_texture(const char* filename, SDL_Renderer* renderer)
{
	// load the image into a memory using SDL_IMAGE library function
	surface = IMG_Load(filename);
	if (surface == NULL)
	{
		printf("Failed to create a surface. SDL_ERROR:%s", SDL_GetError());
	}


	// loading the image into graphics hardware memory
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL)
	{
		printf("Failed to create a texture. SDL_ERROR:%s", SDL_GetError());
		SDL_DestroyTexture(texture);
	}

	return texture;

}

void players_picture()
{

	// adjusting the image size player 1
	snail1_des.x = 0;
	snail1_des.y = 380;
	snail1_des.w = SNAIL_HEIGHT;
	snail1_des.h = SNAIL_WIDTH;
	player1 = load_texture("C:\\Users\\Golden\\Desktop\\vscodeMicrosfo\\idk\\idk\\src\\snail1.png", renderer);

	// player2 image
	snail2_des.x = 0;
	snail2_des.y = 500;
	snail2_des.w = SNAIL_HEIGHT;
	snail2_des.h = SNAIL_WIDTH;
	player2 = load_texture("C:\\Users\\Golden\\Desktop\\vscodeMicrosfo\\idk\\idk\\src\\snail2.png", renderer);

}

void game_ball()
{
	flag1.x = WIN_WIDTH - 100;
	flag1.y = 350;
	flag1.w = 100;
	flag1.h = 100;
	flag_player1 = load_texture("C:\\Users\\Golden\\Desktop\\vscodeMicrosfo\\idk\\idk\\src\\flag.png", renderer);

	flag2.x = WIN_WIDTH - 100;
	flag2.y = 480;
	flag2.w = 100;
	flag2.h = 100;
	flag_player2 = load_texture("C:\\Users\\Golden\\Desktop\\vscodeMicrosfo\\idk\\idk\\src\\flag2.png", renderer);

}

void background_picture()
{
	background_size.w = 720;
	background_size.h = 720;
	background = load_texture("C:\\Users\\Golden\\Desktop\\vscodeMicrosfo\\idk\\idk\\src\\background1.png", renderer);
}



bool has_intersect()
{
	if (SDL_HasIntersection(&snail1_des, &flag1))
	{
		snail1_des.x = 0;
		snail1_des.y = 380;
		return true;

	}
	if (SDL_HasIntersection(&snail2_des, &flag2))
	{
		snail2_des.x = 0;
		snail2_des.y = 500;
		return true;
	}


	return false;
}

// who will get to the flag first
void winners()
{
	has_intersect();
}