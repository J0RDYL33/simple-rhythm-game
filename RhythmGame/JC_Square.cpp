#include "JC_Square.h"

JC_Square::JC_Square()
{
	Init();
}

JC_Square::~JC_Square()
{

}


void JC_Square::Init()
{
	rect.x = 50;
	rect.y = 50;
	rect.w = 25;
	rect.h = 25;
	R = 0;
	G = 0;
	B = 0;
}

void JC_Square::Init(int pX, int pY, int pW, int pH, int pR, int pG, int pB)
{
	rect.x = pX;
	rect.y = pY;
	rect.w = pW;
	rect.h = pH;
	R = pR;
	G = pG;
	B = pB;
}

void JC_Square::Render(SDL_Renderer* aRenderer)
{
	SDL_SetRenderDrawColor(aRenderer, R, G, B, 255);
	SDL_RenderFillRect(aRenderer, &rect);
}

void JC_Square::ChangeColour(int pR, int pG, int pB)
{
	R = pR;
	G = pG;
	B = pB;
}

bool JC_Square::AddScore()
{
	if (G == 255)
		return true;
	else
		return false;
}