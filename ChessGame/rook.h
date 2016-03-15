#pragma once

#include "piece.h"
#include <iostream>

using namespace std;

class Rook : public Piece
{
public :
	Rook(int x, int y, bool pieceColor);
	bool Move(int i, int j, Location** board);
};