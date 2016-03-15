#include "location.h"

Location::Location()
{
	bIndex = false;
	mPieceInfo = NULL;
}

// release unreturned memories
Location::~Location()
{
	if ( mPieceInfo != NULL )
	{
		delete mPieceInfo;
		mPieceInfo = NULL;
	}
}

// set location index to true
void Location::SetIndex()
{
	bIndex = true;
}

void Location::DelIndex()
{
	bIndex = false;
}

bool Location::GetIndex() const
{
	return bIndex;
}

// set location's piece info
void Location::SetPiece(Piece *pieceInfo)
{
	mPieceInfo = pieceInfo;
}

void Location::DelPiece()
{
	//delete mPieceInfo;
	mPieceInfo = NULL;
}

Piece* Location::GetPiece() const
{
	return mPieceInfo;
}