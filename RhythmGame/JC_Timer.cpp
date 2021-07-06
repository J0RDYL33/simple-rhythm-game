#include "JC_Timer.h"

JC_Timer::JC_Timer()
{
	Init();
}

JC_Timer::~JC_Timer()
{

}


void JC_Timer::Init()
{
	leftRect.x = 960;
	leftRect.y = 50;
	leftRect.w = -540;
	leftRect.h = 50;
	rightRect.x = 960;
	rightRect.y = 50;
	rightRect.w = 540;
	rightRect.h = 50;
	R = 0;
	G = 255;
	B = 0;
	timerW = leftRect.w / (60 * 3);
}

void JC_Timer::Update()
{
	leftRect.w = leftRect.w - timerW;
	rightRect.w = rightRect.w + timerW;
}

void JC_Timer::Render(SDL_Renderer* aRenderer)
{
	SDL_SetRenderDrawColor(aRenderer, R, G, B, 255);
	SDL_RenderFillRect(aRenderer, &leftRect);
	SDL_RenderFillRect(aRenderer, &rightRect);
}