#include "king.h"

King::King(int x, int y, bool pieceColor)
: Piece(x, y, 'K', pieceColor){}

bool King::Move(int i, int j, Location** board)
{
	if ( ( board[mX][mY].GetPiece()->GetCast() == true )
		&&( board[mX][mY].GetPiece()->GetPieceType() == 'K' )
		&&( i == mX )&&( ( j == mY - 2 ) || ( j == mY + 2 ) ) )
	{	// possible castling locations
		if ( board[mX][0].GetPiece()->GetCast() == true )
		{
			if ( j == mY - 2 )
			{
				return true;
			}

		} else
		if ( board[mX][7].GetPiece()->GetCast() == true )
		{
			if ( j == mY + 2 )
			{
				return true;
			}
		}

	} else
	if ( i == mX + 1 )
	{	// move downwards
		if ( ( j == mY - 1 ) || ( j == mY ) || ( j == mY + 1 ) )
		{
			if ( ( board[i][j].GetPiece() == NULL ) || ( board[i][j].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) )
			{	// if empty
				return true;
			}
		}

	} else
	if ( i == mX )
	{	// move horizontally
		if ( ( j == mY - 1 ) || ( j == mY + 1 ) )
		{
			if ( ( board[i][j].GetPiece() == NULL )
				|| ( board[i][j].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) )
			{	// if empty
				return true;
			}
		}

	} else
	if ( i == mX - 1 )
	{	// move upwards
		if ( ( j == mY - 1 ) || ( j == mY ) || ( j == mY + 1 ) )
		{
			if ( ( board[i][j].GetPiece() == NULL ) 
				|| ( board[i][j].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) )
			{	// if empty
				return true;
			}
		}
	}

	return false;
}