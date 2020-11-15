#include "MainMenu.h"
#include "Square.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pown.h"
#include "Queen.h"
#include "Rook.h"
#include "Figure.h"

#include <iostream>
#include <string>

using namespace std;




void MainMenu::start_game()
{
	Chess.form_figure_color('w', 'b');
	Chess.first_figure_input();

	bool GameOver;



	do
	{
	GameOver = false;
	Chess.print_board();

	cout << "<Pick a figure>\n";
	int row = 0;
	row = Chess.input_row_validation();
	int col = 0;
	col = Chess.input_col_validation();


	if(Chess.empty_space_validation(row, col)==true)
	{
		if (Chess.right_player_validation(row, col) == true)
		{
			
			Chess.you_have_picked(row, col);
			cout << "<Pick a were you wont to PUT the figure>\n";
			int going_row = Chess.input_row_validation();
			int going_col = Chess.input_col_validation();

			if (Chess.Same_square_validation(row, col, going_row, going_col) == true)
			{
				if (Chess.Same_color_validation(row, col, going_row, going_col) == true)
				{
					if (Chess.figure_movement_validation(row, col, going_row, going_col)==true)
					{
						if (Chess.chessmate_validation(row, col, going_row, going_col) == false)
						{//chess mate validation if this is false(no chess mate) -> go on 
							Chess.chess_board[going_row][going_col].put_new_figure(*Chess.chess_board[row][col].current_figure);
							Chess.chess_board[row][col].remove_figure();
							Chess.change_player_turn();
						}
						else
						{
							cout << "THE KING IS ON THESS\nDO YOU WONT TO GIVE UP\nPRESS\n1)GIVE UP\n2)GO ON -TRY DIFFERENT ACTION\n";
							int choise;
							cin >> choise;
							if (choise == 1)
							{
								cout << "THE GAME IS OVER\n";
								GameOver = true;
							}
						}
					}
				}
			}

		}
	}






	} while (GameOver == false);
	


}