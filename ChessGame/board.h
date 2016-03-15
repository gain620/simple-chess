#pragma once

#include "location.h"
#include "rule.h"
#include "pawn.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "queen.h"
#include "king.h"

class Board
{
private:
	Location** board;
	Rule mRule;
	int	turn; // for counting turns
	int pawnCountW, pawnCountB;
	int bishopCountW, bishopCountB;
	int knightCountW, knightCountB;
	int rookCountW, rookCountB;
	int queenCountW, queenCountB;

	bool bIndex; // for location checking
	bool bCheckMateW, bCheckMateB;
	bool bEnpassantW, bEnpassantB;

public :
	Board();
	void BeginGame();
	void ReplayMode();
	void Draw(Location** board);
	Location** InitBoard();
	bool EndGame(Location** board);
	void EndGameDraw(bool color);
};