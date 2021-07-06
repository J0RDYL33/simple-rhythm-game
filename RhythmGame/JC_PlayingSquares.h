#pragma once
#include "SDL.h"
class JC_PlayingSquares
{
public:
	JC_PlayingSquares();
	~JC_PlayingSquares();
	SDL_Rect rect;

	void Init();
	void Init(int pX, int pY, int pW, int pH, int pR, int pG, int pB);
	void Render(SDL_Renderer* aRenderer);
	void MakeGreen();
	void MakeRed();
	int R, G, B;
	bool doubleSquare = false;
};
