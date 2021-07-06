#pragma once
#include "JC_Square.h"
#include "SDL.h"
#include "JC_Timer.h"
#include "JC_PlayingSquares.h"
#include <vector>
using namespace std;
class JC_SquareContainer
{
public:
	JC_SquareContainer();
	~JC_SquareContainer();

	void Init();
	void Render(SDL_Renderer* aRenderer);
	void Update();
	void Reset();
	void GenerateSquares();
	void OnClose();

	JC_Timer timer;
	JC_Square timerBackground;
	vector<JC_PlayingSquares> aPlayingSquares;
	JC_Square middleSquare;
	int numOfSquares = 0;
	int lengthOfSquares = 0;
	int startingPoint = 0;
	int timesPressed = 0;
	bool spaceHeld = false;
	int errors = 0;
};

