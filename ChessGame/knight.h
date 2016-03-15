#pragma once

#include "piece.h"
#include <iostream>

using namespace std;

class Knight : public Piece
{
public :
	Knight(int x, int y, bool pieceColor);
	bool Move(int i, int j, Location** board);
};