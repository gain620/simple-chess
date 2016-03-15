#include "queen.h"

Queen::Queen(int x, int y, bool pieceColor)
: Piece(x, y, 'Q', pieceColor){}

bool Queen::Move(int i, int j, Location** board)
{
	int x = mX;
	int y = mY;


	// diagonal movements = same as bishop's code

	if (i > mX)
	{
		// down diagonal
		if (j > mY)
		{	// ¢Ù
			x++;
			y++;

			while ((x <= BOARD_MAX) && (y <= BOARD_MAX) && (board[x][y].GetPiece() == NULL))
			{	// move until meeting an obstacle
				if ((i == x) && (j == y))
				{
					return true;
				}

				x++;
				y++;
			}

			if ((x <= BOARD_MAX) && (y <= BOARD_MAX)
				&& (board[x][y].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor()))
			{	// if enemy exists
				if ((i == x) && (j == y))
				{
					return true;
				}
			}

		}
		else
			if (j < mY)
			{	// ¢×
				x++;
				y--;

				while ((x <= BOARD_MAX) && (y >= BOARD_MIN) && (board[x][y].GetPiece() == NULL))
				{
					if ((i == x) && (j == y))
					{
						return true;
					}

					x++;
					y--;
				}

				if ((x <= BOARD_MAX) && (y >= BOARD_MIN)
					&& (board[x][y].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor()))
				{
					if ((i == x) && (j == y))
					{
						return true;
					}
				}
			}

	}
	else
		if (i < mX)
		{	// up diagonal
			if (j > mY)
			{	// ¢Ö
				x--;
				y++;

				while ((x >= BOARD_MIN) && (y <= BOARD_MAX) && (board[x][y].GetPiece() == NULL))
				{
					if ((i == x) && (j == y))
					{
						return true;
					}

					x--;
					y++;
				}

				if ((x >= BOARD_MIN) && (y <= BOARD_MAX)
					&& (board[x][y].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor()))
				{
					if ((i == x) && (j == y))
					{
						return true;
					}
				}

			}
			else
				if (j < mY)
				{	// ¢Ø
					x--;
					y--;

					while ((x >= BOARD_MIN) && (y >= BOARD_MIN) && (board[x][y].GetPiece() == NULL))
					{
						if ((i == x) && (j == y))
						{
							return true;
						}

						x--;
						y--;
					}

					if ((x >= BOARD_MIN) && (y >= BOARD_MIN)
						&& (board[x][y].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor()))
					{
						if ((i == x) && (j == y))
						{
							return true;
						}
					}
				}
		}


	// horizontal, vertical movements = same as rook's code

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

			if ( ( y <= BOARD_MAX )
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