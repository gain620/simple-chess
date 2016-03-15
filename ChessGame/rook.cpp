#include "rook.h"


Rook::Rook(int x, int y, bool pieceColor)
: Piece(x, y, 'R', pieceColor){}

bool Rook::Move(int i, int j, Location** board)
{
	int x = mX;
	int y = mY;
		
	if ( i == mX )
	{	// horizontal
		if ( j < mY )
		{	// left
			y--;

			while ( ( y >= BOARD_MIN )&&( board[x][y].GetPiece() == NULL ) )
			{
				if ( y == j )
				{
					return true;
				}

				y--;
			}

			if ( ( y >= BOARD_MIN )
				&&( board[x][y].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) )
			{
				if ( ( i == x )&&( j == y ) )
				{
					return true;
				}
			}

		} else
		if ( j > mY )
		{	// right
			y++;

			while ( ( y <= BOARD_MAX )&&( board[x][y].GetPiece() == NULL ) )
			{
				if ( y == j )
				{
					return true;
				}

				y++;
			}

			if ( ( y <= BOARD_MIN )
				&&( board[x][y].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) )
			{
				if ( ( i == x )&&( j == y ) )
				{
					return true;
				}
			}
		}

	} else
	if ( j == mY )
	{	// vertical
		if ( i < mX )
		{	// up
			x--;

			while ( ( x >= BOARD_MIN )&&( board[x][y].GetPiece() == NULL ) )
			{
				if ( x == i )
				{
					return true;
				}

				x--;
			}

			if ( ( x >= BOARD_MIN )
				&&( board[x][y].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) )
			{
				if ( ( i == x )&&( j == y ) )
				{
					return true;
				}
			}

		} else
		if ( i > mX )
		{	// down
			x++;

			while ( ( x <= BOARD_MAX )&&( board[x][y].GetPiece() == NULL ) )
			{
				if ( x == i )
				{
					return true;
				}

				x++;
			}

			if ( ( x <= BOARD_MAX )
				&&( board[x][y].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) )
			{
				if ( ( i == x )&&( j == y ) )
				{
					return true;
				}
			}
		}
	}

	return false;
}