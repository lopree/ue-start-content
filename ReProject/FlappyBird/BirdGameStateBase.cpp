#include "BirdGameStateBase.h"

ABirdGameStateBase::ABirdGameStateBase()
{
	Score = 0;
}

int32 ABirdGameStateBase::GetScore()
{
	return Score;
}

void ABirdGameStateBase::ResetScore()
{
	Score = 0;
}

void ABirdGameStateBase::AddScore()
{
	Score++;
}

void ABirdGameStateBase::AddDoubleScore()
{
	Score += 2;
}
