#pragma once

#include "piece.h"
#include "rule.h"
#include <iostream>

using namespace std;

class King : public Piece
{
public :
	King(int x, int y, bool pieceColor);
	bool Move(int i, int j, Location** board);
};