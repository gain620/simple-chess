#pragma once

#include <iostream>
class Piece;

class Location
{
private:
	bool bIndex; // possible indexes to move
	Piece *mPieceInfo; // piece info pointer

public :
	Location();
	~Location();

	void SetIndex();
	void DelIndex();
	bool GetIndex() const;
	void SetPiece(Piece *pieceInfo);
	void DelPiece();
	Piece* GetPiece() const;
};