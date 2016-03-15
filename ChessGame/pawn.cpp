#include "pawn.h"


Pawn::Pawn(int x, int y,  bool pieceColor)
: Piece(x, y, 'P', pieceColor){}
	
bool Pawn::Move(int i, int j, Location** board)
{
	// WHITE
	if ( board[mX][mY].GetPiece()->GetColor() == WHITE )
	{
		// possible enpassant locations
		if ( board[mX][mY].GetPiece()->GetEnp() == true )
		{
			if ( ( mY - 1 >= BOARD_MIN )&&( board[mX][mY - 1].GetPiece() != NULL )
				&&( board[mX][mY - 1].GetPiece()->GetEnp() == true ) 
				&&( board[mX][mY - 1].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) )
			{
				if ( ( i == mX - 1 )&&( j == mY - 1 )&&( board[mX - 1][mY - 1].GetPiece() == NULL ) )
				{
					return true;
				}

			} else if ( ( mY + 1 <= BOARD_MAX )&&( board[mX][mY + 1].GetPiece() != NULL )
				&&( board[mX][mY + 1].GetPiece()->GetEnp() == true ) 
				&&( board[mX][mY + 1].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) )
			{
				if ( ( i == mX - 1 )&&( j == mY + 1 )&&( board[mX - 1][mY + 1].GetPiece() == NULL ) )
				{
					return true;
				}
			}
		}
		// first move, move twice
		if ( GetFirst() == true )
		{
			if ( ( i == mX - 2 )&&( j == mY )&&( board[i][j].GetPiece() == NULL )
				&&( board[mX - 1][mY].GetPiece() == NULL ) )
			{
				return true;
			}
		}
		// move once
		if ( ( i == mX - 1 )&&( j == mY )&&( board[i][j].GetPiece() == NULL ) )
		{
			return true;	

		} else if ( ( i == mX - 1 )&&( ( j == mY - 1 ) || ( j == mY + 1 ) )
			&&( ( board[i][j].GetPiece() != NULL )&&( board[i][j].GetPiece()->GetColor() == BLACK ) ) )
		{// if enemy exists
			return true;			
		}

	// BLACK
	} else {
		if ( board[mX][mY].GetPiece()->GetEnp() == true ) {
			if ( ( mY - 1 >= BOARD_MIN )&&( board[mX][mY - 1].GetPiece() != NULL )
				&&( board[mX][mY - 1].GetPiece()->GetEnp() == true )
				&&( board[mX][mY - 1].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) )
			{
				if ( ( i == mX + 1 )&&( j == mY - 1 )&&( board[mX + 1][mY - 1].GetPiece() == NULL ) )
				{
					return true;
				}

			} else if ( ( mY + 1 <= BOARD_MAX )&&( board[mX][mY + 1].GetPiece() != NULL )
				&&( board[mX][mY + 1].GetPiece()->GetEnp() == true )
				&&( board[mX][mY + 1].GetPiece()->GetColor() != board[mX][mY].GetPiece()->GetColor() ) )
			{
				if ( ( i == mX + 1 )&&( j == mY + 1 )&&( board[mX + 1][mY + 1].GetPiece() == NULL ) )
				{
					return true;
				}
			}
		}

		if ( GetFirst() == true )
		{
			if ( ( i == mX + 2 )&&( j == mY )&&( board[i][j].GetPiece() == NULL )
				&&( board[mX + 1][mY].GetPiece() == NULL ) )
			{
				return true;
			}			
		}
		
		if( ( i == mX + 1 )&&( j == mY )&&( board[i][j].GetPiece() == NULL ) )
		{
			return true;

		} else if ( ( i == mX + 1 )&&( ( j == mY - 1 ) || ( j == mY + 1 ) )
			&&( ( board[i][j].GetPiece() != NULL )&&( board[i][j].GetPiece()->GetColor() == WHITE ) ) )
		{
			return true;			
		}
	}

	return false;
}