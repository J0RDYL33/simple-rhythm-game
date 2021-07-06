#include "JC_PlayingSquares.h"

JC_PlayingSquares::JC_PlayingSquares()
{
	Init();
}

JC_PlayingSquares::~JC_PlayingSquares()
{

}


void JC_PlayingSquares::Init()
{
	rect.x = 50;
	rect.y = 750;
	rect.w = 100;
	rect.h = 100;
	R = 0;
	G = 0;
	B = 200;
}

void JC_PlayingSquares::Init(int pX, int pY, int pW, int pH, int pR, int pG, int pB)
{
	rect.x = pX;
	rect.y = pY;
	rect.w = pW;
	rect.h = pH;
	R = pR;
	G = pG;
	B = pB;
}

void JC_PlayingSquares::Render(SDL_Renderer* aRenderer)
{
	SDL_SetRenderDrawColor(aRenderer, R, G, B, 255);
	SDL_RenderFillRect(aRenderer, &rect);
}

void JC_PlayingSquares::MakeGreen()
{
	G = 255;
	B = 0;
	R = 0;
}

void JC_PlayingSquares::MakeRed()
{
	G = 0;
	B = 0;
	R = 255;
}