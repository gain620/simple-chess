#include "bishop.h"

Bishop::Bishop(int x, int y, bool pieceColor)
: Piece(x, y, 'B', pieceColor){}

bool Bishop::Move(int i, int j, Location** board)
{
	int x = mX;
	int y = mY;

	if ( i > mX )
	{
		// down diagonal
		if ( j > mY )
		{	// ¢Ù
			x++;
			y++;

			while ( ( x <= BOARD_MAX )&&( y <= BOARD_MAX )&&( board[x][y].GetPiece() == NULL ) )
			{	// move until meeting an obstacle
				if ( ( i == x )&&( j == y ) )
				{
					return true;
				}

				x++;
				y++;
			}

			if ( ( x <= BOARD_MAX )&&( y <= BOARD_MAX )
				&&( board[x][y].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) )
			{	// if enemy exists
				if ( ( i == x )&&( j == y ) )
				{
					return true;
				}
			}

		} else
		if ( j < mY )
		{	// ¢×
			x++;
			y--;

			while ( ( x <= BOARD_MAX )&&( y >= BOARD_MIN )&&( board[x][y].GetPiece() == NULL ) )
			{
				if ( ( i == x )&&( j == y ) )
				{
					return true;
				}

				x++;
				y--;
			}

			if ( ( x <= BOARD_MAX )&&( y >= BOARD_MIN )
				&&(board[x][y].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) )
			{
				if ( ( i == x )&&( j == y ) )
				{
					return true;
				}
			}
		}

	} else
	if ( i < mX )
	{	// up diagonal
		if ( j > mY )
		{	// ¢Ö
			x--;
			y++;

			while ( ( x >= BOARD_MIN )&&( y <= BOARD_MAX )&&( board[x][y].GetPiece() == NULL ) )
			{
				if ( ( i == x )&&( j == y ) )
				{
					return true;
				}

				x--;
				y++;
			}

			if ( ( x >= BOARD_MIN )&&( y <= BOARD_MAX )
				&&( board[x][y].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) )
			{
				if ( ( i == x )&&( j == y ) )
				{
					return true;
				}
			}

		} else
		if ( j < mY )
		{	// ¢Ø
			x--;
			y--;

			while ( ( x >= BOARD_MIN )&&( y >= BOARD_MIN )&&( board[x][y].GetPiece() == NULL ) )
			{
				if ( ( i == x )&&( j == y ) )
				{
					return true;
				}

				x--;
				y--;
			}

			if ( ( x >= BOARD_MIN )&&( y >= BOARD_MIN )
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