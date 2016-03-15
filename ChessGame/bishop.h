#pragma once

#include "piece.h"
#include <iostream>

using namespace std;

class Bishop : public Piece
{
public :
	Bishop(int x, int y, bool pieceColor);
	bool Move(int i, int j, Location** board);
};