#pragma once

#include "piece.h"
#include "knight.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"

class Rule
{
public :
	// attacking pieces
	bool Attacked(int x, int y, bool color, Location** board);

	// special rules
	void Promotion(int x, int y, Location** board);
	void Enpassant(int x, int y, Location** board);
	void Castling(Location** board);
};