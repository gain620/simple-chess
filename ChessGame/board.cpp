#include <iostream>
#include <conio.h>
#include <cctype>

#include "board.h"

using namespace std;

Board::Board()
{
	// initialize board
	board = InitBoard();
	bEnpassantW = bEnpassantB = true;
	turn = 0;
	pawnCountW = pawnCountB = 8;
	bishopCountW = bishopCountB = 2;
	knightCountW = knightCountB = 2;
	rookCountW = rookCountB = 2;
	queenCountW = queenCountB = 1;
}

void Board::BeginGame()
{
	int	tX, tY;

	// for movement inputs
	char inputX, inputY;
	int	nX, nY;	

	bool loop = true;
	bool selectLoop;

	while (loop)
	{
		int	i, j;
		bIndex = false;

		switch (turn % 2)
		{
			// WHITE TURN
			case 0 :
			{

				for ( i = BOARD_MIN; i <= BOARD_MAX; i++ )
				{
					for ( j = BOARD_MIN; j <= BOARD_MAX; j++ )
					{
						// delete before index
						board[i][j].DelIndex();

						// set white pieces index
						if ( ( board[i][j].GetPiece() != NULL )&&( board[i][j].GetPiece()->GetColor() == WHITE ) )
						{
							board[i][j].SetIndex();
							if ( board[i][j].GetPiece()->GetPieceType() == 'K' )
							{	// bCheckMateW == true
								bCheckMateW = mRule.Attacked(i, j, WHITE, board);
							}

						} else if ( ( board[i][j].GetPiece() != NULL )&&( board[i][j].GetPiece()->GetColor() == BLACK ) )
						{	// bCheckMateB == true
							if ( board[i][j].GetPiece()->GetPieceType() == 'K' )
							{
								bCheckMateB = mRule.Attacked(i, j, BLACK, board);
							}
						} 
					}
				}

				do
				{
					selectLoop = false;
					system("cls");
					Draw(board);
					cout << "WHITE Turn : ";
					cin >> inputX >> inputY;

					// char to int conversion
					nX = 8 - (inputY - '0');
					nY = (inputX - 'A');

					if ( ( nX < BOARD_MIN ) || ( nX > BOARD_MAX )
						|| ( nY < BOARD_MIN ) || ( nY > BOARD_MAX )
						|| ( board[nX][nY].GetIndex() == false ) )
					{
						cout << "Please try again!" << endl;
						_getch();
						selectLoop = true;
					} 

				} while ( selectLoop );

				break;
			}

			// BLACK TURN
			case 1 :
			{
				for ( i = BOARD_MIN; i <= BOARD_MAX; i++ )
				{
					for ( j = BOARD_MIN; j <= BOARD_MAX; j++ )
					{
						// delete before index
						board[i][j].DelIndex();
						if ( ( board[i][j].GetPiece() != NULL )&&( board[i][j].GetPiece()->GetColor() == BLACK ) )
						{	// set black pieces index
							board[i][j].SetIndex();
							if ( board[i][j].GetPiece()->GetPieceType() == 'K' )
							{	// bCheckMateB == true
								bCheckMateB = mRule.Attacked(i, j, BLACK, board);
							}

						} else
						if ( ( board[i][j].GetPiece() != NULL )&&( board[i][j].GetPiece()->GetColor() == WHITE ) )
						{
							if ( board[i][j].GetPiece()->GetPieceType() == 'K' )
							{
								// bCheckMateW == true
								bCheckMateW = mRule.Attacked(i, j, WHITE, board);
							}
						}
					}
				}

				do
				{
					selectLoop = false;
					system("cls");
					Draw(board);
					cout << "Black Turn : ";
					cin >> inputX >> inputY;

					// char to int conversion
					nX = 8 - (inputY - '0');
					nY = (inputX - 'A');

					if ( ( nX < BOARD_MIN ) || ( nX > BOARD_MAX ) 
						|| ( nY < BOARD_MIN ) || ( nY > BOARD_MAX ) 
						|| ( board[nX][nY].GetIndex() == false ) )
					{
						cout << "Please try again!" << endl;
						_getch();
						selectLoop = true;
					} 

				} while (selectLoop);

				break;
			}
		}

		// loop through the board
		for ( i = BOARD_MIN; i <= BOARD_MAX; i++ )
		{
			for ( j = BOARD_MIN; j <= BOARD_MAX; j++ )
			{
				// delete before index
				board[i][j].DelIndex();

				if ( board[nX][nY].GetPiece()->Move(i, j, board) == true )
				{
					// set index if movement is possible
					board[i][j].SetIndex();
					bIndex = true;
				}
			}
		}
		
		// if moving to any locations is impossible
		if ( bIndex == false )
		{
			cout << "No possible locations to move!!" << endl;
			_getch();
		
		// if movement is possible
		} else {	
			do
			{
				selectLoop = false;
				system("cls");

				Draw(board); // draw board

				// check possible enpassant movements
				if ( board[nX][nY].GetPiece()->GetEnp() == false )
				{
					for ( i = BOARD_MIN; i <= BOARD_MAX; i++ )
					{	
						for ( j = BOARD_MIN; j <= BOARD_MAX; j++ )
						{
							if ( ( board[i][j].GetPiece() != NULL )&&( board[i][j].GetPiece()->GetEnp() == true ) )
							{	// set bEnpassant to false
								board[i][j].GetPiece()->DelEnp();
							}
						}
					}
				}

				cout << "Input a location to move : ";
				cin >> inputX >> inputY;

				// char to int conversion
				tX = 8 - (inputY - '0');
				tY = inputX - 'A';

				if ( ( tX < BOARD_MIN ) || ( tX > BOARD_MAX ) 
					|| ( tY < BOARD_MIN ) || ( tY > BOARD_MAX ) 
					|| ( board[tX][tY].GetIndex() == false ) )
				{
					cout << "Please try again!" << endl;
					_getch();
					selectLoop = true;
				}

			} while ( selectLoop );


			// check castling movements
			if ( ( board[nX][nY].GetPiece()->GetCast() == true )&&( board[nX][nY].GetPiece()->GetPieceType() == 'K' )
				&&( ( tY == nY + 2 ) || ( tY == nY - 2 ) ) )
			{
				// right col castling
				if ( tY == nY + 2 )
				{
					// move the king
					board[tX][tY].SetPiece(board[nX][nY].GetPiece());
					board[nX][nY].DelPiece();
					board[tX][tY].GetPiece()->SetXY(tX, tY);
					board[tX][tY].GetPiece()->DelCast();

					// move the rook
					board[nX][nY + 1].SetPiece(board[nX][7].GetPiece());
					board[nX][7].DelPiece();
					board[nX][nY + 1].GetPiece()->SetXY(nX, nY + 1);

				// left col castling
				} else if ( tY == nY - 2 )
				{
					// move the king
					board[tX][tY].SetPiece(board[nX][nY].GetPiece());
					board[nX][nY].DelPiece();
					board[tX][tY].GetPiece()->SetXY(tX, tY);
					board[tX][tY].GetPiece()->DelCast();

					// move the rook
					board[nX][nY - 1].SetPiece(board[nX][0].GetPiece());
					board[nX][0].DelPiece();
					board[nX][nY - 1].GetPiece()->SetXY(nX, nY - 1);
				}



			// enpassant movements
			} else if ( ( board[nX][nY].GetPiece()->GetEnp() == true )
				&&( ( tX == nX - 1 ) || ( tX == nX + 1 ) )
				&&( ( tY == nY - 1 ) || ( tY == nY + 1 ) ) )
			{
				// BLACK ENPASSANT
				if ( board[nX][nY].GetPiece()->GetColor() == WHITE )
				{
					if ( board[tX + 1][tY].GetPiece()->GetColor() == BLACK )
					{	// count dead pieces
						pawnCountB--;
					
					} else
					{
						pawnCountW--;
					}

					// delete a piece killed by enpassant
					delete board[tX + 1][tY].GetPiece();
					board[tX + 1][tY].DelPiece();
					board[tX][tY].SetPiece(board[nX][nY].GetPiece());
					board[nX][nY].DelPiece();
					board[tX][tY].GetPiece()->SetXY(tX, tY);
					// set bEnpassantB to false
					bEnpassantB = false;

				// WHITE ENPASSANT
				} else {
					if ( board[tX - 1][tY].GetPiece()->GetColor() == BLACK )
					{	// count dead pieces
						pawnCountB--;
					} else {
						pawnCountW--;
					}

					// delete a piece killed by enpassant
					delete board[tX - 1][tY].GetPiece();
					board[tX - 1][tY].DelPiece();
					board[tX][tY].SetPiece(board[nX][nY].GetPiece());
					board[nX][nY].DelPiece();
					board[tX][tY].GetPiece() -> SetXY(tX, tY);
					// set bEnpassantB to false
					bEnpassantW = false;
				}

				// set enpassant to false
				board[tX][tY].GetPiece() -> DelEnp();


			// normal movements
			} else {
				if ( board[tX][tY].GetPiece() != NULL )
				{	// delete target location's piece
					if ( board[tX][tY].GetPiece()->GetColor() == BLACK )
					{	
						// count the dead pieces
						if (board[tX][tY].GetPiece()->GetPieceType() == 'P')
							pawnCountB--;
						if (board[tX][tY].GetPiece()->GetPieceType() == 'N')
							knightCountB--;
						if (board[tX][tY].GetPiece()->GetPieceType() == 'B')
							bishopCountB--;
						if (board[tX][tY].GetPiece()->GetPieceType() == 'R')
							rookCountB--;
						if (board[tX][tY].GetPiece()->GetPieceType() == 'Q')
							queenCountB--;
					
					} else {
						if (board[tX][tY].GetPiece()->GetPieceType() == 'P')
							pawnCountW--;
						if (board[tX][tY].GetPiece()->GetPieceType() == 'N')
							knightCountW--;
						if (board[tX][tY].GetPiece()->GetPieceType() == 'B')
							bishopCountW--;
						if (board[tX][tY].GetPiece()->GetPieceType() == 'R')
							rookCountW--;
						if (board[tX][tY].GetPiece()->GetPieceType() == 'Q')
							queenCountW--;
					}

					delete board[tX][tY].GetPiece();
				}

				// move to a target location and delete current location index, piece
				board[tX][tY].SetPiece(board[nX][nY].GetPiece());
				board[nX][nY].DelPiece();
				board[tX][tY].GetPiece()->SetXY(tX, tY);

				if ( ( board[tX][tY].GetPiece()->GetPieceType() == 'P' )
					&&( board[tX][tY].GetPiece()->GetEnp() == true ) )
				{	// change from enpassant to normal movement
					for ( i = BOARD_MIN; i <= BOARD_MAX; i++ )
					{
						for ( j = BOARD_MIN; j <= BOARD_MAX; j++ )
						{
							if ( ( board[i][j].GetPiece() != NULL )&&( board[i][j].GetPiece()->GetEnp() == true ) )
							{	// set enpassant to false
								board[i][j].GetPiece()->DelEnp();
							}
						}
					}
				}
			}

			// check any possible enpassant movements
			{
				// check black enpassant
				if ((bEnpassantB != false) && (board[tX][tY].GetPiece()->GetColor() == BLACK))
				{
					if (((tX == 3) || (tX == 4))
						&& (board[tX][tY].GetPiece()->GetPieceType() == 'P')
						&& (board[tX][tY].GetPiece()->GetFirst() == true))
					{	//set enpassant	
						mRule.Enpassant(tX, tY, board);
					}

				}
				// check white enpassant
				else if ((bEnpassantW != false) && (board[tX][tY].GetPiece()->GetColor() == WHITE))
					{
						if (((tX == 3) || (tX == 4))
							&& (board[tX][tY].GetPiece()->GetPieceType() == 'P')
							&& (board[tX][tY].GetPiece()->GetFirst() == true))
						{	// set enpassant	
							mRule.Enpassant(tX, tY, board);
						}
					}
			}
			

			// set piece's first move bool to false
			board[tX][tY].GetPiece()->DelFirst();

			// check any possible castling movements
			mRule.Castling(board);

			// check promotion
			if ( ( board[tX][tY].GetPiece()->GetPieceType() == 'P' )
				&&( ( tX == 0 ) || ( tX == 7 ) ) )
			{	
				mRule.Promotion(tX, tY, board);
			}
		
			if ( EndGame(board) == true )
			{	// check game's end
				loop = false;
			}

			turn++;
		}
	}
}

// check end game conditions
bool Board::EndGame(Location** board)
{
	int i,j;
	int end = 0;

	// search thorugh the board
	for ( i = BOARD_MIN; i <= BOARD_MAX; i++ )
	{
		for ( j = BOARD_MIN; j <= BOARD_MAX; j++ )
		{
			if ( ( board[i][j].GetPiece() != NULL )&&( board[i][j].GetPiece()->GetPieceType() == 'K' ) )
			{	// find king
				if ( board[i][j].GetPiece()->GetColor() == BLACK )
				{	// BLACK KING
					end++;

				} else
				{	// WHITE KING
					end += 3;
				}
			}
		}
	}

	switch (end)
	{
		case 1 :
			// BLACK KING
			EndGameDraw(BLACK);
			for ( i = BOARD_MIN; i <= BOARD_MAX; i++ ) delete[] board[i];
			delete[] board;
			board = NULL;
			return true;
			break;

		case 3 :
			// WHITE KING
			EndGameDraw(WHITE);
			for(i = BOARD_MIN; i <= BOARD_MAX; i++) delete[] board[i];
			delete[] board;
			board = NULL;
			return true;
			break;
		
		default :
			return false;
			break;
	}
}

// replay the game
void Board::ReplayMode()
{

}

// draw a board
void Board::Draw(Location** board)
{
	for ( int i = 0; i <= BOARD_MAX; i++ )
	{
		if (i == 0) {
			cout << "      TURN : " << turn;
			cout << "        - LEFT PIECES -" << endl;
			cout << "                           WP BP" << endl;
			cout << "                         P " << pawnCountW << "  " << pawnCountB << endl;
			cout << "                         N " << knightCountW << "  " << knightCountB << endl;
			cout << "                         B " << bishopCountW << "  " << bishopCountB << endl;
			cout << "                         R " << rookCountW << "  " << rookCountB << endl;
			cout << "                         Q " << queenCountW << "  " << queenCountB << endl;
		}

		for (int j = 0; j <= BOARD_MAX; j++) {
			if (board[i][j].GetPiece() != NULL)
			{// if piece exists
				// set piece depending on color
				if (board[i][j].GetPiece()->GetColor() == BLACK)
				{
					// black
					char black = tolower(board[i][j].GetPiece()->GetPieceType());
					cout << black << " ";
				}
				else
				{
					// white
					cout << board[i][j].GetPiece()->GetPieceType() << " ";
				}

			}
			else {
				cout << ". ";
			}
		}

		cout << "  " << 8-i << endl; // row

			
		if( i == 7 )
		{
			cout << endl << "A B C D E F G H " << endl << endl; // col
		}
	}
}

// return a initialized board
Location** Board::InitBoard()
{
	Location** board;

	board = new Location*[8];

	for ( int i = BOARD_MIN; i <= BOARD_MAX; i++ )
	{
		board[i] = new Location[8];
	}

	board[0][0].SetPiece(new Rook(0, 0, BLACK));
	board[0][1].SetPiece(new Knight(0, 1, BLACK));
	board[0][2].SetPiece(new Bishop(0, 2, BLACK));
	board[0][3].SetPiece(new King(0, 3, BLACK));
	board[0][4].SetPiece(new Queen(0, 4, BLACK));
	board[0][5].SetPiece(new Bishop(0, 5, BLACK));
	board[0][6].SetPiece(new Knight(0, 6, BLACK));
	board[0][7].SetPiece(new Rook(0, 7, BLACK));
	board[1][0].SetPiece(new Pawn(1, 0, BLACK));
	board[1][1].SetPiece(new Pawn(1, 1, BLACK));
	board[1][2].SetPiece(new Pawn(1, 2, BLACK));
	board[1][3].SetPiece(new Pawn(1, 3, BLACK));
	board[1][4].SetPiece(new Pawn(1, 4, BLACK));
	board[1][5].SetPiece(new Pawn(1, 5, BLACK));
	board[1][6].SetPiece(new Pawn(1, 6, BLACK));
	board[1][7].SetPiece(new Pawn(1, 7, BLACK));

	board[6][0].SetPiece(new Pawn(6, 0, WHITE));
	board[6][1].SetPiece(new Pawn(6, 1, WHITE));
	board[6][2].SetPiece(new Pawn(6, 2, WHITE));
	board[6][3].SetPiece(new Pawn(6, 3, WHITE));
	board[6][4].SetPiece(new Pawn(6, 4, WHITE));
	board[6][5].SetPiece(new Pawn(6, 5, WHITE));
	board[6][6].SetPiece(new Pawn(6, 6, WHITE));
	board[6][7].SetPiece(new Pawn(6, 7, WHITE));
	board[7][0].SetPiece(new Rook(7, 0, WHITE));
	board[7][1].SetPiece(new Knight(7, 1, WHITE));
	board[7][2].SetPiece(new Bishop(7, 2, WHITE));
	board[7][3].SetPiece(new King(7, 3, WHITE));
	board[7][4].SetPiece(new Queen(7, 4, WHITE));
	board[7][5].SetPiece(new Bishop(7, 5, WHITE));
	board[7][6].SetPiece(new Knight(7, 6, WHITE));
	board[7][7].SetPiece(new Rook(7, 7, WHITE));

	return board;
}

void Board::EndGameDraw(bool color)
{
	system("cls");
	cout << "----------------------" << endl;
	cout << "|                    |" << endl;
	cout << "|      GAME OVER     |" << endl;
	if (color == WHITE)
		cout << "|        WHITE       |" << endl;
	else
		cout << "|        BLACK       |" << endl;
	cout << "|       player       |" << endl;
	cout << "|        wins!       |" << endl;
	cout << "|                    |" << endl;
	cout << "----------------------" << endl;
	cout << endl;
	cout << "Please try again!";
	_getch();
}