#pragma once
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



const int board_size = 8;
class Board
{
private:

	char player_turn = 'w'; //white start first


	//just to illustrate the Board
	unsigned int print_board_row[board_size] = { 1,2,3,4,5,6,7,8 };
	char         print_board_col[board_size] = { 'A','B', 'C', 'D', 'E', 'F', 'G','H' };
	
	
	//All  inherit class Figure-> (symbol, color, first_move)
	Pown   pown_w[8];
	Rook   rook_w[2];
	Knight knight_w[2];
	Bishop bishop_w[2];
	Queen  queen_w;
	King   King_w;

	Pown   pown_b[8];
	Rook   rook_b[2];
	Knight knight_b[2];
	Bishop bishop_b[2];
	Queen  queen_b;
	King   King_b;

public:
	
	Square chess_board[board_size][board_size];

	void form_figure_color(char _color1, char _color2);
	void first_figure_input();
	void print_board();
	int  input_row_validation();
	int  input_col_validation();	

	bool empty_space_validation(int _row, int _col);
	bool right_player_validation(int _row, int _col);

	void you_have_picked(int row, int col);
	bool Same_square_validation(int curent_row, int curent_col, int _going_to_row, int _going_to_col);
	bool Same_color_validation(int curent_row, int curent_col, int _going_to_row, int _going_to_col);
	void change_player_turn();

	bool figure_movement_validation(int curent_row, int curent_col, int _going_to_row, int _going_to_col);

	bool white_pown_validation(int curent_row, int curent_col, int _going_to_row, int _going_to_col);
	bool black_pown_validation(int curent_row, int curent_col, int _going_to_row, int _going_to_col);
	bool rook_validation(int curent_row, int curent_col, int _going_to_row, int _going_to_col);
	bool knight_validation(int curent_row, int curent_col, int _going_to_row, int _going_to_col);
	bool bishop_validation(int curent_row, int curent_col, int _going_to_row, int _going_to_col);
	bool king_validation(int curent_row, int curent_col, int _going_to_row, int _going_to_col);
	bool queen_validation(int curent_row, int curent_col, int _going_to_row, int _going_to_col);

	//chess mate validation 
	bool chessmate_validation(int curent_row, int curent_col, int _going_to_row, int _going_to_col);
	bool chess_val_UP(int krow, int kcol);
	bool chess_val_DOWN(int krow, int kcol);
	bool chess_val_RIGHT(int krow, int kcol);
	bool chess_val_LEFT(int krow, int kcol);
	bool chess_val_UP_LEFT(int krow, int kcol);
	bool chess_val_UP_RIGHT(int krow, int kcol);
	bool chess_val_DOWN_LEFT(int krow, int kcol);
	bool chess_val_DOWN_RIGHT(int krow, int kcol);
};

