#include "SDL.h"
#include "JC_Square.h"
#include "JC_SquareContainer.h"
#include <vector>
#include <iostream>
using namespace std;
class JC_GameWorld
{
public:
	JC_GameWorld();
	~JC_GameWorld();

	SDL_Window* window = SDL_CreateWindow("Jordan Cave, 19695697", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event _event;
	bool done;
	double startMs, endMs, delayMs;
	int frameRate = 60;
	double frameMs = 1000 / frameRate;
	int currentFrame = 0;
	JC_SquareContainer aSquareContainer;
	bool pause = false;
	int score = 0;
	int gKeys;

	void Init();

	void GameLoop();

	void Update();

	void Render();

	void OnClose();
};