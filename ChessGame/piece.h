#pragma once

#include "location.h"
#include <iostream>

#define BOARD_MAX 7
#define BOARD_MIN 0

enum COLOR { BLACK, WHITE };

using namespace std;

class Piece
{
private:
	char mPieceType; // pieceType
	bool bPieceColor; // pieceColor
	bool bFirstMove; // firstMove
	bool bEnpassant; // enpassant check
	bool bCastling; // castling check

protected:
	int mX, mY;

public :
	Piece(int x, int y, char pieceType, bool pieceColor);
	void SetXY(int x, int y);	
	char GetPieceType() const;
	bool GetColor() const;
	void DelFirst();
	bool GetFirst() const;
	void SetEnp();
	void DelEnp();
	bool GetEnp() const;
	void SetCast();
	void DelCast();
	bool GetCast() const;
	virtual bool Move(int i, int j, Location** board) = 0;
};