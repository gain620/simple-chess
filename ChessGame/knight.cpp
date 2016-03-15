#include "knight.h"

Knight::Knight(int x, int y, bool pieceColor)
: Piece(x, y, 'N', pieceColor){}

bool Knight::Move(int i, int j, Location** board)
{
	// down
	if ( i == mX + 2 ) {
		if ( ( ( j == mY - 1 ) || ( j == mY + 1 ) )&&( ( board[i][j].GetPiece() == NULL) 
			|| ( board[i][j].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) ) )
		{
			return true;
		}

	// up
	} else if ( i == mX - 2 ) {
		if ( ( ( j == mY - 1 ) || ( j == mY + 1 ) )&&( ( board[i][j].GetPiece() == NULL ) 
			|| ( board[i][j].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) ) )
		{
			return true;
		}

	// right
	} else if ( j == mY + 2 ) {
		if ( ( ( i == mX - 1 ) || ( i == mX + 1 ) )&&( ( board[i][j].GetPiece() == NULL ) 
			|| ( board[i][j].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) ) )
		{
			return true;
		}
	
	// left
	} else if ( j == mY - 2 ) {
		if ( ( ( i == mX - 1 ) || ( i == mX + 1 ) )&&( ( board[i][j].GetPiece() == NULL ) 
			|| ( board[i][j].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) ) )
		{
			return true;
		}
	}

	return false;
}