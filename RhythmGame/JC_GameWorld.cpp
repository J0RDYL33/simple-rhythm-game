#include "JC_GameWorld.h"

JC_GameWorld::JC_GameWorld()
{
	Init();
	GameLoop();
}

JC_GameWorld::~JC_GameWorld()
{
	OnClose();
}

void JC_GameWorld::Init()
{
	
}

void JC_GameWorld::GameLoop()
{
	while (done != true)
	{
		startMs = SDL_GetTicks(); //when the frame starts 

		Update();
		Render();

		endMs = SDL_GetTicks(); //when the frame calculations end 
		delayMs = frameMs - (endMs - startMs); //how long to delay 
		SDL_Delay(delayMs);
		currentFrame++;
	}
}

void JC_GameWorld::Update()
{
	while (SDL_PollEvent(&_event))
	{
		if (_event.type == SDL_KEYDOWN)
		{
			switch (_event.key.keysym.sym)
			{
			case SDLK_SPACE:
				gKeys++;
				break;
			}
		}
		if (_event.type == SDL_KEYUP && _event.key.repeat == NULL)
		{
			switch (_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				done = true;
				break;
			case SDLK_p:
				pause = !pause;
				break;
			case SDLK_SPACE:
				if (gKeys >= 2)
				{
					aSquareContainer.spaceHeld = true;
					aSquareContainer.timesPressed++;
					gKeys = 0;
				}
				else
				{
					aSquareContainer.spaceHeld = false;
					aSquareContainer.timesPressed++;
					gKeys = 0;
				}
				break;
			}
		}
	}
		/*if (pause == false)
			aSquareContainer.Update();*/

		if (currentFrame % 180 != 0)
			aSquareContainer.Update();
		else
		{
			if (aSquareContainer.middleSquare.AddScore() == true)
				score++;
			aSquareContainer.Reset();
			aSquareContainer.Update();
		}
		if (currentFrame >= 1800)
		{
			cout << "Score: " << score << endl;
			SDL_Quit();
		}
}

void JC_GameWorld::Render()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);

	if (currentFrame % 180 != 0)
		aSquareContainer.Render(renderer);

	SDL_SetRenderDrawColor(renderer, 10, 0, 20, 255);
	SDL_RenderPresent(renderer);
}

void JC_GameWorld::OnClose()
{

}