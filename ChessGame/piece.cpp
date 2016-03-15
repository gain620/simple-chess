#include "piece.h"

Piece::Piece(int x, int y, char pieceType, bool pieceColor)
{
	mX = x;
	mY = y;
	mPieceType = pieceType;
	bPieceColor = pieceColor;

	// special rules booleans set
	bFirstMove = true;
	bEnpassant = false;
	bCastling = false;
}

void Piece::SetXY(int x, int y)
{
	mX = x;
	mY = y;
}
	
char Piece::GetPieceType() const
{
	return mPieceType;
}

bool Piece::GetColor() const
{
	return bPieceColor;
}

// pawn's first move
void Piece::DelFirst()
{
	bFirstMove = false;
}

bool Piece::GetFirst() const
{
	return bFirstMove;
}

// enpassant handle
void Piece::SetEnp()
{
	bEnpassant = true;
}

void Piece::DelEnp()
{
	bEnpassant = false;
}

bool Piece::GetEnp() const
{
	return bEnpassant;
}

// castling handle
void Piece::SetCast()
{
	bCastling = true;
}

void Piece::DelCast()
{
	bCastling = false;
}

bool Piece::GetCast() const
{
	return bCastling;
}