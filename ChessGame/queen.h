#pragma once

#include "piece.h"
#include <iostream>

using namespace std;

class Queen : public Piece
{
public :
	Queen(int x, int y, bool pieceColor);
	bool Move(int i, int j, Location** board);
};