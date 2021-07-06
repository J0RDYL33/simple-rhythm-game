#pragma once
#include "SDL.h"
class JC_Square
{
public:
	JC_Square();
	~JC_Square();
	SDL_Rect rect;

	void Init();
	void Init(int pX, int pY, int pW, int pH, int pR, int pG, int pB);
	void Render(SDL_Renderer* aRenderer);
	void ChangeColour(int pR, int pG, int pB);
	int R, G, B;
	bool AddScore();
};

