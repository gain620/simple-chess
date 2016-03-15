#include "rule.h"
#include <iostream>
#include <conio.h>

using namespace std;

// check whether location x,y is attacked
bool Rule::Attacked(int x, int y, bool color, Location** board)
{
	for ( int i = BOARD_MIN; i <= BOARD_MAX; i++ )
	{
		for ( int j = BOARD_MIN; j <= BOARD_MAX; j++ )
		{
			if ( ( board[i][j].GetPiece() != NULL )&&( board[i][j].GetPiece()->GetColor() != color ) )
			{	// if board[i][j] exists and is enemy
				if ( board[i][j].GetPiece()->Move(x, y, board) == true )
				{	// return true if it can move
					return true;
				}
			}
		}
	}
	return false;
}

// promotion
void Rule::Promotion(int x, int y, Location** board)
{
	bool turn;

	do
	{
		bool color = board[x][y].GetPiece()->GetColor();
		char select;

		turn = false;
		cout << "Promotion is possible!" << endl;
		cout << "1.Queen  2.Knight  3.Rook  4.Bishop" << endl;
		cout << "Input your desired piece : ";
		cin >> select;

		switch (select)
		{
			// queen
			case '1' :
				delete board[x][y].GetPiece();
				board[x][y].SetPiece(new Queen(x, y, color));
				break;

			// knight
			case '2' :
				delete board[x][y].GetPiece();
				board[x][y].SetPiece(new Knight(x, y, color));
				break;

			// rook
			case '3' :
				delete board[x][y].GetPiece();
				board[x][y].SetPiece(new Rook(x, y, color));
				break;

			// bishop
			case '4' :
				delete board[x][y].GetPiece();
				board[x][y].SetPiece(new Bishop(x, y, color));
				break;

			default :
				cout << "Please try again! " << endl;
				turn = true;
				_getch();
				break;

		}
	} while ( turn );

}

// set enpassant, when possible
void Rule::Enpassant(int x, int y, Location** board)
{
	// right side
	if ( ( y + 1 <= BOARD_MAX )&&( board[x][y + 1].GetPiece() != NULL )
		&&( board[x][y + 1].GetPiece()->GetPieceType() == 'P' )
		&&( board[x][y + 1].GetPiece()->GetColor() != board[x][y].GetPiece()->GetColor() ) )
	{	// when enemy pawn is on the right side
		board[x][y + 1].GetPiece()->SetEnp();
		board[x][y].GetPiece()->SetEnp();

	// left side
	} else if ( ( y - 1 >= BOARD_MIN )&&( board[x][y - 1].GetPiece() != NULL )
		&&( board[x][y - 1].GetPiece()->GetPieceType() == 'P')
		&&( board[x][y - 1].GetPiece()->GetColor() != board[x][y].GetPiece()->GetColor() ) )
	{	// when enemy pawn is on the left side
		board[x][y - 1].GetPiece()->SetEnp();
		board[x][y].GetPiece()->SetEnp();
	}
}

// check castling
void Rule::Castling(Location** board)
{
	bool bCastlingMoveAttack;
	int y, i,j;

	// delete any possible castling movements
	for ( i = BOARD_MIN; i <= BOARD_MAX; i++ )
	{
		for ( j = BOARD_MIN; j <= BOARD_MAX; j++ )
		{
			if ( board[i][j].GetPiece() != NULL ) board[i][j].GetPiece()->DelCast();
		}
	}

	// WHITE CASTLING
	if ( ( board[7][3].GetPiece() != NULL )
		&&( board[7][3].GetPiece()->GetPieceType() == 'K' )
		&&( board[7][3].GetPiece()->GetFirst() == true ) )
	{	// if white king doesn't move
		if ( ( board[7][0].GetPiece() != NULL )
			&&( board[7][0].GetPiece()->GetFirst() == true ) )
		{	// check white left col
			if ( ( board[7][3 - 1].GetPiece() == NULL )
				&&( board[7][3 - 2].GetPiece() == NULL ) )
			{	// if rook and king's space empty
				y = 3;
				do
				{	// if there could be a possible attack between two
					bCastlingMoveAttack = Attacked(7, y, WHITE, board);	
					y--;
				} while ( ( y > BOARD_MIN )&&( bCastlingMoveAttack != true ) );	

				if ( bCastlingMoveAttack == false )
				{	// if every condition passes, set castling
					board[7][3].GetPiece()->SetCast();
					board[7][0].GetPiece()->SetCast();
				}
			}
		}

		if ( ( board[7][7].GetPiece() != NULL )
			&&( board[7][7].GetPiece()->GetFirst() == true ) )
		{	//	check white right col
			if ( ( board[7][3 + 1].GetPiece() == NULL )
				&&( board[7][3 + 2].GetPiece() == NULL )
				&&( board[7][3 + 3].GetPiece() == NULL ) )
			{	// if rook and king's space empty
				y = 3;
				do
				{	// if there could be a possible attack between two
					bCastlingMoveAttack = Attacked(7, y, WHITE, board);	
					y++;
				} while ( ( y < BOARD_MAX )&&( bCastlingMoveAttack != true ) );
 
				if ( bCastlingMoveAttack == false )
				{	// if every condition passes, set castling
					board[7][3].GetPiece()->SetCast();
					board[7][7].GetPiece()->SetCast();
				}
			}
		}
	}

	// BLACK CASTLING
	if ( ( board[0][3].GetPiece() != NULL )
		&&( board[0][3].GetPiece()->GetPieceType() == 'K' )
		&&( board[0][3].GetPiece() -> GetFirst() == true) )
	{
		if ( ( board[0][0].GetPiece() != NULL )
			&&( board[0][0].GetPiece()->GetFirst() == true ) )
		{	// check black left col
			if ( ( board[0][3 - 1].GetPiece() == NULL )
				&&( board[0][3 - 2].GetPiece() == NULL ) )
			{	// if rook and king's space empty
				y = 3;
				do
				{	// if there could be a possible attack between two
					bCastlingMoveAttack = Attacked(0, y, BLACK, board);	
					y--;
				} while ( ( y > BOARD_MIN )&&( bCastlingMoveAttack != true ) );

				if ( bCastlingMoveAttack == false )
				{	// if every condition passes, set castling
					board[0][3].GetPiece()->SetCast();
					board[0][0].GetPiece()->SetCast();
				}
			}
		}

		if ( ( board[0][7].GetPiece() != NULL )
			&&( board[0][7].GetPiece()->GetFirst() == true ) )
		{	// check black right col
			if ( ( board[0][3 + 1].GetPiece() == NULL )
				&&( board[0][3 + 2].GetPiece() == NULL )
				&&( board[0][3 + 3].GetPiece() == NULL ) )
			{	// if rook and king's space empty
				y = 3;

				do
				{	// if there could be a possible attack between two
					bCastlingMoveAttack = Attacked(0, y, BLACK, board);	
					y++;
				} while ( ( y < BOARD_MAX )&&( bCastlingMoveAttack != true ) );

				if ( bCastlingMoveAttack == false )
				{	// if every condition passes, set castling
					board[0][3].GetPiece()->SetCast();
					board[0][7].GetPiece()->SetCast();
				}
			}
		}
	}
}