#pragma once

#include "piece.h"
#include <iostream>

using namespace std;

class Pawn : public Piece
{
public :
	Pawn(int x, int y, bool pieceInfo);
	bool Move(int i, int j, Location** board);
};