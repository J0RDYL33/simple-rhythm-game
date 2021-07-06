#pragma once
#include "SDL.h"
#include <iostream>
using namespace std;
class JC_Timer
{
public:
	JC_Timer();
	~JC_Timer();
	SDL_Rect leftRect;
	SDL_Rect rightRect;
	int timerW;

	void Init();
	void Update();
	void Render(SDL_Renderer* aRenderer);
	int R, B, G;
};

