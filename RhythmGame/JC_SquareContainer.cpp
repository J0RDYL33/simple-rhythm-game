#include "JC_SquareContainer.h"

JC_SquareContainer::JC_SquareContainer()
{
	Init();
}

JC_SquareContainer::~JC_SquareContainer()
{

}

void JC_SquareContainer::Init()
{
	timerBackground.Init(410, 40, 1100, 70, 130, 30, 30);
	middleSquare.Init(710, 180, 500, 500, 100, 100, 100);
	GenerateSquares();
}

void JC_SquareContainer::Render(SDL_Renderer* aRenderer)
{
	timerBackground.Render(aRenderer);
	timer.Render(aRenderer);
	middleSquare.Render(aRenderer);
	for (int i = 0; i < aPlayingSquares.size(); i++)
	{
		aPlayingSquares[i].Render(aRenderer);
	}
}

void JC_SquareContainer::Update()
{
	if (timer.rightRect.w > 0)
	{
		timer.Update();
	}

	switch (timesPressed)
	{
	case 1:
		if (aPlayingSquares[0].doubleSquare == true && spaceHeld == true)
			aPlayingSquares[0].MakeGreen();
		else if (aPlayingSquares[0].doubleSquare == false && spaceHeld == false)
			aPlayingSquares[0].MakeGreen();
		else
		{
			errors++;
			aPlayingSquares[0].MakeRed();
		}
		break;
	case 2:
		if (numOfSquares >= 2)
		{
			if (aPlayingSquares[1].doubleSquare == true && spaceHeld == true)
				aPlayingSquares[1].MakeGreen();
			else if (aPlayingSquares[1].doubleSquare == false && spaceHeld == false)
				aPlayingSquares[1].MakeGreen();
			else
				errors++;
		}
		break;
	case 3:
		if (numOfSquares >= 3)
		{
			if (aPlayingSquares[2].doubleSquare == true && spaceHeld == true)
				aPlayingSquares[2].MakeGreen();
			else if (aPlayingSquares[2].doubleSquare == false && spaceHeld == false)
				aPlayingSquares[2].MakeGreen();
			else
				errors++;
		}
		break;
	case 4:
		if (numOfSquares >= 4)
		{
			if (aPlayingSquares[3].doubleSquare == true && spaceHeld == true)
				aPlayingSquares[3].MakeGreen();
			else if (aPlayingSquares[3].doubleSquare == false && spaceHeld == false)
				aPlayingSquares[3].MakeGreen();
			else
				errors++;
		}
		break;
	case 5:
		if (numOfSquares >= 5)
		{
			if (aPlayingSquares[4].doubleSquare == true && spaceHeld == true)
				aPlayingSquares[4].MakeGreen();
			else if (aPlayingSquares[4].doubleSquare == false && spaceHeld == false)
				aPlayingSquares[4].MakeGreen();
			else
				errors++;
		}
		break;
	case 6:
		if (numOfSquares >= 6)
		{
			if (aPlayingSquares[5].doubleSquare == true && spaceHeld == true)
				aPlayingSquares[5].MakeGreen();
			else if (aPlayingSquares[5].doubleSquare == false && spaceHeld == false)
				aPlayingSquares[5].MakeGreen();
			else
				errors++;
		}
		break;
	case 7:
		if (numOfSquares >= 7)
		{
			if (aPlayingSquares[6].doubleSquare == true && spaceHeld == true)
				aPlayingSquares[6].MakeGreen();
			else if (aPlayingSquares[6].doubleSquare == false && spaceHeld == false)
				aPlayingSquares[6].MakeGreen();
			else
				errors++;
		}
		break;
	case 8:
		if (numOfSquares >= 8)
		{
			if (aPlayingSquares[7].doubleSquare == true && spaceHeld == true)
				aPlayingSquares[7].MakeGreen();
			else if (aPlayingSquares[7].doubleSquare == false && spaceHeld == false)
				aPlayingSquares[7].MakeGreen();
			else
				errors++;
		}
		break;
	}
	if (numOfSquares == timesPressed && errors == 0)
	{
		middleSquare.ChangeColour(0, 255, 0);
	}
	else if (timesPressed > numOfSquares || errors >= 1)
	{
		middleSquare.ChangeColour(255, 0, 0);
		errors = 0;
	}
}

void JC_SquareContainer::Reset()
{
	timesPressed = 0;
	timer.leftRect.w = -540;
	timer.rightRect.w = 540;
	aPlayingSquares.clear();
	middleSquare.ChangeColour(100, 100, 100);
	lengthOfSquares = 0;
	startingPoint = 0;
	GenerateSquares();
}

void JC_SquareContainer::GenerateSquares()
{
	srand(time(0));
	numOfSquares = (rand() % 8) + 1;

	for (int i = 0; i < numOfSquares; i++)
	{
		JC_PlayingSquares next;
		if (rand() % 4 == 0)
		{
			next.rect.w *= 2;
			next.doubleSquare = true;
		}
		lengthOfSquares += next.rect.w;
		aPlayingSquares.push_back(next);
	}
	lengthOfSquares += ((numOfSquares - 1) * 20);
	startingPoint = (1920 - lengthOfSquares) / 2;
	for (int i = 0; i < numOfSquares; i++)
	{
		aPlayingSquares[i].rect.x = startingPoint;
		startingPoint = aPlayingSquares[i].rect.x + aPlayingSquares[i].rect.w + 20;
	}
}