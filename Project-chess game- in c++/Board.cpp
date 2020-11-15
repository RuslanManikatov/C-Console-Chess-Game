#include "Board.h"


/*
col[  0  1  2  3  4  5  6  7]
	  a  b  c  d  e  f  g  h
*============================
0]1 | R  N  B  Q  K  B  N  R    -White -(BIG letters)
1]2 | P  P  P  P  P  P  P  P
2]3 | -  -  -  -  -  -  -  -
3]4 | -  -  -  -  -  -  -  -
4]5 | -  -  -  -  -  -  -  -
5]6 | -  -  -  -  -  -  -  -
6]7 | p  p  p  p  p  p  p  p   - Black  -(Small letters)
7]8 | r  n  b  q  k  b  n  r
row
*/

//if you want to put different colors
void Board::form_figure_color(char _color1,char _color2)
{
	for (int i = 0; i < 8; i++)
	{
		pown_w[i].set_color(_color1);
	}
	   
	rook_w[0].set_color(_color1);
	rook_w[1].set_color(_color1);
	knight_w[0].set_color(_color1);
	knight_w[1].set_color(_color1);
	bishop_w[0].set_color(_color1);
	bishop_w[1].set_color(_color1);
    queen_w.set_color(_color1);
	King_w.set_color(_color1);

	for (int i = 0; i < 8; i++)
	{
		pown_b[i].set_color(_color2);
	}

	rook_b[0].set_color(_color2);
	rook_b[1].set_color(_color2);
	knight_b[0].set_color(_color2);
	knight_b[1].set_color(_color2);
	bishop_b[0].set_color(_color2);
	bishop_b[1].set_color(_color2);
	queen_b.set_color(_color2);
	King_b.set_color(_color2);
}
void Board::first_figure_input()
{
	
	for (int col = 0; col < board_size; col++)
	{
		chess_board[1][col].put_new_figure(pown_w[col]);
		
	}
	for (int col = 0; col < board_size; col++)
	{
		chess_board[6][col].put_new_figure(pown_b[col]);
	}

	
	chess_board[0][0].put_new_figure(rook_w[0]);
	chess_board[0][7].put_new_figure(rook_w[1]);
	chess_board[0][1].put_new_figure(knight_w[0]);
	chess_board[0][6].put_new_figure(knight_w[1]);
	chess_board[0][2].put_new_figure(bishop_w[0]);
	chess_board[0][5].put_new_figure(bishop_w[1]);
	chess_board[0][3].put_new_figure(queen_w);
	chess_board[0][4].put_new_figure(King_w);
	

	chess_board[7][0].put_new_figure(rook_b[0]);
	chess_board[7][7].put_new_figure(rook_b[1]);
	chess_board[7][1].put_new_figure(knight_b[0]);
	chess_board[7][6].put_new_figure(knight_b[1]);
	chess_board[7][2].put_new_figure(bishop_b[0]);
	chess_board[7][5].put_new_figure(bishop_b[1]);
	chess_board[7][3].put_new_figure(queen_b);
	chess_board[7][4].put_new_figure(King_b);


}
void Board::print_board()
{
	cout << "   <>THE CHESS GAME<>\n";

	cout << "   ";
	for (int i = 0; i < 8; i++)
	{
		cout << " " << print_board_col[i];
	}
	cout << "\n----------------------\n";

	for (int i = 0; i < 8; i++)
	{
		cout << print_board_row[i] << "]-";
		for (int x = 0; x < 8; x++)
		{
			cout << "|";
			cout << chess_board[i][x].get_symbol();
			//cout << chess_board[i][x].get_busy();

		}
		cout << "|-[]\n";
	}
}


int  Board::input_row_validation()
{
	cout << "Press from 1 to 8 to pick a [ROW]\n ";
	char row;
	cin >> row;
	switch (row)
	{
	case '1':
		return 0;
	case '2':
		return 1;
	case '3':
		return 2;
	case '4':
		return 3;
	case '5':
		return 4;
	case '6':
		return 5;
	case '7':
		return 6;
	case '8':
		return 7;
	default:
		cout << "There is no sutch NUMBER in the ROW of the board!\n";
		return input_row_validation();
		break;
	}
}
int  Board::input_col_validation()
{
	cout << "Press from A to H to pick a [COLUMN]\n ";
	char col;
	cin >> col;
	switch (col)
	{
	case 'a':
	case 'A':
		return 0;
	case 'b':
	case 'B':
		return 1;
	case 'c':
	case 'C':
		return 2;
	case 'd':
	case 'D':
		return 3;
	case 'e':
	case 'E':
		return 4;
	case 'f':
	case 'F':
		return 5;
	case 'g':
	case 'G':
		return 6;
	case 'h':
	case 'H':
		return 7;
	default:
		cout << "There is no sutch CHARACTER in the COLUMN of the board!\n";
		return input_col_validation();
		break;
	}
}



bool Board::empty_space_validation(int _row, int _col)
{
	if (chess_board[_row][_col].get_busy() == true)
	{
		return true;
	}
	else
	{
		cout << "-----------------------------------------\n";
		cout << "You must pick again, the square is EMPTY\n";
		cout << "-----------------------------------------\n";
		return false;
	}
}
bool Board::right_player_validation(int _row, int _col)
{
	if (chess_board[_row][_col].get_color() == player_turn)
	{
		return true;
	}
	else
	{
		cout << "-----------------------------------------\n";
		cout << "You can't pick the opposite figures!\n";
		cout << "-----------------------------------------\n";
		return false;
	}
}

void Board::you_have_picked(int _row, int _col)
{
	cout << "You have picked: <" << chess_board[_row][_col].current_figure->get_name() << ">\n";
	
}

bool Board::Same_square_validation(int current_row, int current_col, int _going_to_row, int _going_to_col)
{
	if (current_row == _going_to_row && current_col == _going_to_col)
	{
		cout << "---------------------------------------\n";
		cout << "You can,t move to the SAME square\n";
		cout << "---------------------------------------\n";
		return false;
	}
	else
		return true;

}

bool Board::Same_color_validation(int current_row, int current_col, int _going_to_row, int _going_to_col)
{
	if (chess_board[_going_to_row][_going_to_col].get_busy() == true)
	{
		if (chess_board[current_row][current_col].current_figure->get_color() == chess_board[_going_to_row][_going_to_col].current_figure->get_color())
		{
			cout << "-----------------------------------------\n";
			cout << "You can,t take one of your own!\n";
			cout << "-----------------------------------------\n";
			return false;
		}
		else
			return true;
	}
	
	return true;
}
void Board::change_player_turn()
{
	if (player_turn == 'w')
		player_turn = 'b';
	else
		player_turn = 'w';
}


/*
From here on are only algorithms to validate if the figures can move correct. 

*/
bool Board::figure_movement_validation(int current_row, int current_col, int _going_to_row, int _going_to_col)
{
	char figure_for_valid = chess_board[current_row][current_col].current_figure->get_symbol();
	you_have_picked(current_row, current_col);

	switch (figure_for_valid)
	{
	case 'p':
		return black_pown_validation(current_row, current_col, _going_to_row, _going_to_col);
	case 'P':
		return white_pown_validation(current_row, current_col, _going_to_row, _going_to_col);
	case 'r':
	case 'R':

		return rook_validation(current_row, current_col, _going_to_row, _going_to_col);
		
	case 'n':
	case 'N':
		return knight_validation(current_row, current_col, _going_to_row, _going_to_col);
	
	case 'b':
	case 'B':
		return bishop_validation(current_row, current_col, _going_to_row, _going_to_col);
	case 'q':
	case 'Q':
		return queen_validation(current_row, current_col, _going_to_row, _going_to_col);


	case 'k':
	case 'K':
		if (king_validation(current_row, current_col, _going_to_row, _going_to_col) == true)
		{
			chess_board[current_row][current_col].current_figure->set_king_row_position(_going_to_row);
			chess_board[current_row][current_col].current_figure->set_king_row_position(_going_to_col);
			return true;
		}
		else return false;
		break;
	

	default:
		return false;
		break;
	}
}



//separate chess FIGURES validation
bool Board::black_pown_validation(int current_row, int current_col, int _going_to_row, int _going_to_col)
{  //B pown must move row-1(-2 the first time) and can take col-1 or +1

	if (current_col == _going_to_col && chess_board[current_row - 1][current_col].get_busy() == true)
	{
		cout << "------------------------------------\n";
		cout << "Pown can't take forward\n";
		cout << "------------------------------------\n";
		return false;
	}
	else if (current_row <= _going_to_row)
	{
		cout << "------------------------------------\n";
		cout << "Pown can't move like that\n";
		cout << "------------------------------------\n";
		return false;
	}
	else if (current_row - 1 > _going_to_row)
	{
		if (current_row - 2 == _going_to_row)
		{
			if (chess_board[current_row][current_col].current_figure->get_first_move() == false)
			{
				if (chess_board[current_row - 1][current_col - 1].get_busy() == true)
				{
					cout << "------------------------------------\n";
					std::cout << "You are not a knight figure\n";
					cout << "------------------------------------\n";
					return false;
				}
			}
			else
			{
				cout << "------------------------------------\n";
				cout << "You can move +2 only the first time\n";
				cout << "------------------------------------\n";
				return false;
			}
		}
		else
		{
			cout << "------------------------------------\n";
			cout << "Pown can't move so mutch forward\n";
			cout << "------------------------------------\n";
			return false;
		}

	}
	else if (current_col != _going_to_col)
	{
		if (current_col + 1 == _going_to_col && current_col - 1 == _going_to_col)
		{
			if (chess_board[_going_to_row][_going_to_col].get_busy() == true)
			{
				if (chess_board[_going_to_row][_going_to_col].current_figure->get_symbol() == 'w')
				{
					cout << "------------------------------------\n";
					cout << "You can,t take one of your own!\n";
					cout << "------------------------------------\n";
					return false;
				}
			}
			else
			{
				cout << "------------------------------------\n";
				cout << "There is nothing to take there!\n";
				cout << "------------------------------------\n";
				return false;
			}

		}
		else
		{
			cout << "------------------------------------\n";
			cout << "Pown can't move like Bishops!\n";
			cout << "------------------------------------\n";
			return false;
		}
	}

	return true;

}
bool Board::white_pown_validation(int current_row, int current_col, int _going_to_row, int _going_to_col)
{  //white pown can move +1 row and can take +1 col  
	if (current_col == _going_to_col && chess_board[current_row + 1][current_col].get_busy() == true)
	{
		cout << "------------------------------------\n";
		cout << "Pown can't take forward\n";
		cout << "------------------------------------\n";
		return false;
	}
	else if (current_row >= _going_to_row)
	{
		cout << "------------------------------------\n";
		cout << "Pown can't move like that\n";
		cout << "------------------------------------\n";
		return false;
	}
	else if (current_row + 1 < _going_to_row)
	{
		if (current_row + 2 == _going_to_row)
		{
			if (chess_board[current_row][current_col].current_figure->get_first_move() == false)
			{
				if (chess_board[current_row + 1][current_col + 1].get_busy() == true)
				{
					cout << "------------------------------------\n";
					std::cout << "You are not a knight figure\n";
					cout << "------------------------------------\n";
					return false;
				}
			}
			else
			{
				cout << "------------------------------------\n";
				cout << "You can move +2 only the first time\n";
				cout << "------------------------------------\n";
				return false;
			}
		}
		else
		{
			cout << "------------------------------------\n";
			cout << "Pown can't move so mutch forward\n";
			cout << "------------------------------------\n";
			return false;
		}

	}
	else if (current_col != _going_to_col)
	{
		if (current_col + 1 == _going_to_col && current_col - 1 == _going_to_col)
		{
			if (chess_board[_going_to_row][_going_to_col].get_busy() == true)
			{
				if (chess_board[_going_to_row][_going_to_col].current_figure->get_symbol() == 'w')
				{
					cout << "------------------------------------\n";
					cout << "You can't take one of your own!\n";
					cout << "------------------------------------\n";
					return false;
				}
			}
			else
			{
				cout << "------------------------------------\n";
				cout << "There is nothing to take there!\n";
				cout << "------------------------------------\n";
				return false;
			}

		}
		else
		{
			cout << "------------------------------------\n";
			cout << "Pown can't move like Bishop!\n";
			cout << "------------------------------------\n";
			return false;
		}
	}


	
	return true;
	


}
bool Board::rook_validation(int current_row, int current_col, int _going_to_row, int _going_to_col)
{ 
	
	if      ((current_row == _going_to_row) && (current_col > _going_to_col))
	{
		for (current_col-- ; current_col > _going_to_col; current_col--)
		{
			if (chess_board[current_row][current_col].get_busy() == true)
			{
				cout << "------------------------------------\n";
				cout << "There is something on your path and you can't skip it like that<Left>\n";
				cout << "------------------------------------\n";
				return false;
			}
		}
		return true;
	}
	else if ((current_row == _going_to_row) && (current_col < _going_to_col))
	{
		for (current_col++; current_col < _going_to_col; current_col++)
		{
			if (chess_board[current_row][current_col].get_busy() == true)
			{
				cout << "------------------------------------\n";
				cout << "There is something on your path and you can't skip it like that<Right>\n";
				cout << "------------------------------------\n";
				return false;
			}
		}
		return true;
	}
	else if ((current_col == _going_to_col) && (current_row > _going_to_row))
	{
		for (current_row--; current_row > _going_to_row; current_row--)
		{
			if (chess_board[current_row][current_col].get_busy() == true)
			{
				cout << "------------------------------------\n";
				cout << "There is something on your path and you can't skip it like that<Up>\n";
				cout << "------------------------------------\n";
				return false;
			}
		}
		return true;
	}
	else if ((current_col == _going_to_col) && (current_row < _going_to_row))
	{
		for (current_row++; current_row < _going_to_row; current_row++)
		{
			
			if (chess_board[current_row][current_col].get_busy() == true)
			{
				cout << "------------------------------------\n";
				cout << "There is something on your path and you can't skip it like that<Down>\n";
				cout << "------------------------------------\n";
				return false;
			}
		}
		return true;
	}

	cout << "------------------------------------\n";
	cout << "ROOK can't move like that\n";
	cout << "------------------------------------\n";
	return false;

}
bool Board::knight_validation(int current_row, int current_col, int _going_to_row, int _going_to_col)
{
	//knight can move only 8 different lacations at this point of the program in variations of current row (+-2) and col (+-1)
	
	if      ((current_row + 1 == _going_to_row) && (current_col + 2 == _going_to_col))
		return true;
	else if ((current_row + 1 == _going_to_row) && (current_col - 2 == _going_to_col))
		return true;
	else if ((current_row - 1 == _going_to_row) && (current_col + 2 == _going_to_col))
		return true;
	else if ((current_row - 1 == _going_to_row) && (current_col - 2 == _going_to_col))
		return true;
	else if ((current_row + 2 == _going_to_row) && (current_col + 1 == _going_to_col))
		return true;
	else if ((current_row + 2 == _going_to_row) && (current_col - 1 == _going_to_col))
		return true;
	else if ((current_row - 2 == _going_to_row) && (current_col + 1 == _going_to_col))
		return true;
	else if ((current_row - 2 == _going_to_row) && (current_col - 1 == _going_to_col))
		return true;
	else
	{
		cout << "------------------------------------\n";
		cout << "Knights can't do that\n";
		cout << "------------------------------------\n";
		return false;
	}

}
bool Board::bishop_validation(int current_row, int current_col, int _going_to_row, int _going_to_col)
{  
if (current_row + current_col == _going_to_row + _going_to_col)
{
	if (current_row > _going_to_row)
	{
		for (current_row = current_row - 1; current_row > _going_to_row; current_row--)
		{
			++current_col;
			if (chess_board[current_row][current_col].get_busy() == true)
			{
				cout << "------------------------------------\n";
				cout << "There is something on the path<Up,Right>\n";
				cout << "------------------------------------\n";
				return false;
			}
		}
		return true;
	}
	if (current_row < _going_to_row)
	{
		for (current_row = current_row + 1; current_row < _going_to_row; current_row++)
		{
			--current_col;
			if (chess_board[current_row][current_col].get_busy() == true)
			{
				cout << "------------------------------------\n";
				cout << "There is something on the path<Up,Right>\n";
				cout << "------------------------------------\n";
				return false;
			}
		}
		return true;
	}
}
else if (current_row + _going_to_col == _going_to_row + current_col)
{
	if (current_row > _going_to_row)
	{
		for (current_row = current_row - 1; current_row > _going_to_row; current_row--)
		{
			--current_col;
			if (chess_board[current_row][current_col].get_busy() == true)
			{
				cout << "------------------------------------\n";
				cout << "There is something on the path<Up,Right>\n";
				cout << "------------------------------------\n";
				return false;
			}
		}
		return true;
	}
	if (current_row < _going_to_row)
	{
		for (current_row = current_row + 1; current_row < _going_to_row; current_row++)
		{
			++current_col;
			if (chess_board[current_row][current_col].get_busy() == true)
			{
				cout << "------------------------------------\n";
				cout << "There is something on the path<Up,Right>\n";
				cout << "------------------------------------\n";
				return false;
			}
		}
		return true;
	}
}
else
{
	cout << "------------------------------------\n";
	cout << "Bishops can't do that\n";
	cout << "------------------------------------\n";
	return false;
}
}
bool Board::king_validation(int current_row, int current_col, int _going_to_row, int _going_to_col)
{
	if (current_row +1 == _going_to_row || current_row - 1 == _going_to_row || current_row  == _going_to_row)
	{
		if (current_col + 1 == _going_to_col || current_col - 1 == _going_to_col || current_col == _going_to_col)
		{
			return true;
		}
		else
		{
			cout << "-------------------------------------\n";
			cout << "Eaven the KING can't do that\n";
			cout << "-------------------------------------\n";
			return false;
		}

	}
	else
	{
		cout << "-------------------------------------\n";
		cout << "Eaven the KING can't do that\n";
		cout << "-------------------------------------\n";
		return false;
	}
		
}
bool Board::queen_validation(int current_row, int current_col, int _going_to_row, int _going_to_col)
{
	if ((current_row == _going_to_row) && (current_col > _going_to_col))
	{
		for (current_col--; current_col > _going_to_col; current_col--)
		{
			if (chess_board[current_row][current_col].get_busy() == true)
			{
				cout << "------------------------------------\n";
				cout << "There is something on your path and you can't skip it like that<Left>\n";
				cout << "------------------------------------\n";
				return false;
			}
		}
		return true;
	}
	else if ((current_row == _going_to_row) && (current_col < _going_to_col))
	{
		for (current_col++; current_col < _going_to_col; current_col++)
		{
			if (chess_board[current_row][current_col].get_busy() == true)
			{
				cout << "------------------------------------\n";
				cout << "There is something on your path and you can't skip it like that<Right>\n";
				cout << "------------------------------------\n";
				return false;
			}
		}
		return true;
	}
	else if ((current_col == _going_to_col) && (current_row > _going_to_row))
	{
		for (current_row--; current_row > _going_to_row; current_row--)
		{
			if (chess_board[current_row][current_col].get_busy() == true)
			{
				cout << "------------------------------------\n";
				cout << "There is something on your path and you can't skip it like that<Up>\n";
				cout << "------------------------------------\n";
				return false;
			}
		}
		return true;
	}
	else if ((current_col == _going_to_col) && (current_row < _going_to_row))
	{
		for (current_row++; current_row < _going_to_row; current_row++)
		{

			if (chess_board[current_row][current_col].get_busy() == true)
			{
				cout << "------------------------------------\n";
				cout << "There is something on your path and you can't skip it like that<Down>\n";
				cout << "------------------------------------\n";
				return false;
			}
		}
		return true;
	}
	else if (current_row + current_col == _going_to_row + _going_to_col)
	{
		if (current_row > _going_to_row)
		{
			for (current_row = current_row - 1; current_row > _going_to_row; current_row--)
			{
				++current_col;
				if (chess_board[current_row][current_col].get_busy() == true)
				{
					cout << "------------------------------------\n";
					cout << "There is something on the path<Up,Right>\n";
					cout << "------------------------------------\n";
					return false;
				}
			}
			return true;
		}
		if (current_row < _going_to_row)
		{
			for (current_row = current_row + 1; current_row < _going_to_row; current_row++)
			{
				--current_col;
				if (chess_board[current_row][current_col].get_busy() == true)
				{
					cout << "------------------------------------\n";
					cout << "There is something on the path<Up,Right>\n";
					cout << "------------------------------------\n";
					return false;
				}
			}
			return true;
		}
	}
	else if (current_row + _going_to_col == _going_to_row + current_col)
	{
		if (current_row > _going_to_row)
		{
			for (current_row = current_row - 1; current_row > _going_to_row; current_row--)
			{
				--current_col;
				if (chess_board[current_row][current_col].get_busy() == true)
				{
					cout << "------------------------------------\n";
					cout << "There is something on the path<Up,Right>\n";
					cout << "------------------------------------\n";
					return false;
				}
			}
			return true;
		}
		if (current_row < _going_to_row)
		{
			for (current_row = current_row + 1; current_row < _going_to_row; current_row++)
			{
				++current_col;
				if (chess_board[current_row][current_col].get_busy() == true)
				{
					cout << "------------------------------------\n";
					cout << "There is something on the path<Up,Right>\n";
					cout << "------------------------------------\n";
					return false;
				}
			}
			return true;
		}
	}
	else
	{
		cout << "------------------------------------\n";
		cout << "Queens can't do that\n";
		cout << "------------------------------------\n";
		return false;
	}
}
//this is the chess mate validation and will scan all the squares around the KING to see if someone can take him!!!

bool Board::chessmate_validation(int current_row, int current_col, int _going_to_row, int _going_to_col)
{
//1) change the busy and collor of the squares (curent and going to) to make the calidation



	chess_board[current_row][current_col].set_busy(false);
	chess_board[_going_to_row][_going_to_col].set_busy(true); //eaven if takes figure will be again true!
	char color_before = chess_board[_going_to_row][_going_to_col].get_color();
	chess_board[_going_to_row][_going_to_col].set_color(chess_board[current_row][current_col].current_figure->get_color());


	
	//the bord is only 64 squares, so its not a problem if every time we scan for ALL the figures
	//KING is on chess_bord[king_row_position][king_col_position]
	if (player_turn == 'w')
	{
		//take the position of the white king
		int k_row = King_w.get_king_row_position();
		int k_col = King_w.get_king_col_position();
		//1) chek if a knight can take the KING -> 8 options
		     if (k_row - 2 >= 0 && k_col - 1 >= 0)
		{
			if (chess_board[k_row - 2][k_col - 1].get_busy() == true)
			{
				if (chess_board[k_row - 2][k_col - 1].get_color() == 'b')
				{
					cout << "------------------------------------\n";
					cout << "The KING is on <CHESS> by black KNIGHT\n";
					cout << "------------------------------------\n";
					chess_board[current_row][current_col].set_busy(true);
					chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
					chess_board[_going_to_row][_going_to_col].set_color(color_before);
					return true;
				}
			}
		}
		else if (k_row - 2 >= 0 && k_col + 1 <= 8)
		{
			if (chess_board[k_row - 2][k_col + 1].get_busy() == true)
			{
				if (chess_board[k_row - 2][k_col + 1].get_color() == 'b')
				{
					cout << "------------------------------------\n";
					cout << "The KING is on <CHESS> by black KNIGHT\n";
					cout << "------------------------------------\n";
					chess_board[current_row][current_col].set_busy(true);
					chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
					chess_board[_going_to_row][_going_to_col].set_color(color_before);
					return true;
				}
			}
		}

		else if (k_row + 2 <= 8 && k_col + 1 <= 8)
		{
			if (chess_board[k_row + 2][k_col + 1].get_busy() == true)
			{
				if (chess_board[k_row + 2][k_col + 1].get_color() == 'b')
				{
					cout << "------------------------------------\n";
					cout << "The KING is on <CHESS> by black KNIGHT\n";
					cout << "------------------------------------\n";
					chess_board[current_row][current_col].set_busy(true);
					chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
					chess_board[_going_to_row][_going_to_col].set_color(color_before);
					return true;
				}
			}
		}
		else if (k_row + 2 <= 8 && k_col - 1 <= 0)
		{
			if (chess_board[k_row + 2][k_col - 1].get_busy() == true)
			{
				if (chess_board[k_row + 2][k_col - 1].get_color() == 'b')
				{
					cout << "------------------------------------\n";
					cout << "The KING is on <CHESS> by black KNIGHT\n";
					cout << "------------------------------------\n";
					chess_board[current_row][current_col].set_busy(true);
					chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
					chess_board[_going_to_row][_going_to_col].set_color(color_before);
					return true;
				}
			}
		}

		else if (k_row - 1 >= 0 && k_col - 2 >= 0)
		{
			if (chess_board[k_row - 1][k_col - 2].get_busy() == true)
			{
				if (chess_board[k_row - 1][k_col - 2].get_color() == 'b')
				{
					cout << "------------------------------------\n";
					cout << "The KING is on <CHESS> by black KNIGHT\n";
					cout << "------------------------------------\n";
					chess_board[current_row][current_col].set_busy(true);
					chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
					chess_board[_going_to_row][_going_to_col].set_color(color_before);
					return true;
				}
			}
		}
		else if (k_row - 1 >= 0 && k_col + 2 >= 8)
		{
			if (chess_board[k_row - 1][k_col + 2].get_busy() == true)
			{
				if (chess_board[k_row - 1][k_col + 2].get_color() == 'b')
				{
					cout << "------------------------------------\n";
					cout << "The KING is on <CHESS> by black KNIGHT\n";
					cout << "------------------------------------\n";
					chess_board[current_row][current_col].set_busy(true);
					chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
					chess_board[_going_to_row][_going_to_col].set_color(color_before);
					return true;
				}
			}
		}
		else if (k_row + 1 <= 8 && k_col - 2 >= 0)
		{
			if (chess_board[k_row + 1][k_col - 2].get_busy() == true)
			{
				if (chess_board[k_row + 1][k_col - 2].get_color() == 'b')
				{
					cout << "------------------------------------\n";
					cout << "The KING is on <CHESS> by black KNIGHT\n";
					cout << "------------------------------------\n";
					chess_board[current_row][current_col].set_busy(true);
					chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
					chess_board[_going_to_row][_going_to_col].set_color(color_before);
					return true;
				}
			}
		}
		else if (k_row + 1 <= 8 && k_col + 2 >= 8)
		{
			if (chess_board[k_row + 1][k_col + 2].get_busy() == true)
			{
				if (chess_board[k_row + 1][k_col + 2].get_color() == 'b')
				{
					cout << "------------------------------------\n";
					cout << "The KING is on <CHESS> by black KNIGHT\n";
					cout << "------------------------------------\n";
					chess_board[current_row][current_col].set_busy(true);
					chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
					chess_board[_going_to_row][_going_to_col].set_color(color_before);
					return true;
				}
			}
		}
		
		//2) chek prom king position UP the bord for chess
		else if (chess_val_UP(k_row, k_col) == true)
			 {
			 chess_board[current_row][current_col].set_busy(true);
			 chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
			 chess_board[_going_to_row][_going_to_col].set_color(color_before);
				 return true;
			 }
		//3) chek prom king position DOWN the bord for chess
		else if (chess_val_DOWN(k_row, k_col) == true)
		{
		chess_board[current_row][current_col].set_busy(true);
		chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
		chess_board[_going_to_row][_going_to_col].set_color(color_before);
		return true;
			 }
		//4)chek prom king position LEFT the bord for chess
		else if (chess_val_LEFT(k_row, k_col) == true)
		{
		chess_board[current_row][current_col].set_busy(true);
		chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
		chess_board[_going_to_row][_going_to_col].set_color(color_before);
		return true;
			 }
		//5)chek prom king position RIGHT the bord for chess
		else if (chess_val_RIGHT(k_row, k_col) == true)
		{
		chess_board[current_row][current_col].set_busy(true);
		chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
		chess_board[_going_to_row][_going_to_col].set_color(color_before);
		return true;
			 }
		//6)chek prom king position UP and LEFT the bord for chess
		else if (chess_val_UP_LEFT(k_row, k_col)==true)
		{
		chess_board[current_row][current_col].set_busy(true);
		chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
		chess_board[_going_to_row][_going_to_col].set_color(color_before);
		return true;
			 }
		//7)chek prom king position UP and RIGHT the bord for chess
		else if (chess_val_UP_RIGHT(k_row, k_col) == true)
		{
		chess_board[current_row][current_col].set_busy(true);
		chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
		chess_board[_going_to_row][_going_to_col].set_color(color_before);
		return true;
			 }
		//8)chek prom king position DOWN and LEFT the bord for chess
		else if (chess_val_DOWN_LEFT(k_row, k_col) == true)
		{
		chess_board[current_row][current_col].set_busy(true);
		chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
		chess_board[_going_to_row][_going_to_col].set_color(color_before);
		return true;
			 }
		//9)chek prom king position DOWN and RIGHT the bord for chess
		else if (chess_val_DOWN_RIGHT(k_row, k_col) == true)
		{
		chess_board[current_row][current_col].set_busy(true);
		chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
		chess_board[_going_to_row][_going_to_col].set_color(color_before);
		return true;
			 }
	}



	else //player 'b'
	{
	//take the position of the white king
	int k_row = King_b.get_king_row_position();
	int k_col = King_b.get_king_col_position();
	//1) chek if a knight can take the KING -> 8 options
	if (k_row - 2 >= 0 && k_col - 1 >= 0)
	{
		if (chess_board[k_row - 2][k_col - 1].get_busy() == true)
		{
			if (chess_board[k_row - 2][k_col - 1].get_color() == 'w')
			{
				cout << "------------------------------------\n";
				cout << "The KING is on <CHESS> by black KNIGHT\n";
				cout << "------------------------------------\n";
				
			 chess_board[current_row][current_col].set_busy(true);
			 chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
			 chess_board[_going_to_row][_going_to_col].set_color(color_before);
				
			 
				return true;
			}
		}
	}
	else if (k_row - 2 >= 0 && k_col + 1 <= 8)
	{
		if (chess_board[k_row - 2][k_col + 1].get_busy() == true)
		{
			if (chess_board[k_row - 2][k_col + 1].get_color() == 'w')
			{
				cout << "------------------------------------\n";
				cout << "The KING is on <CHESS> by black KNIGHT\n";
				cout << "------------------------------------\n";
				chess_board[current_row][current_col].set_busy(true);
				chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
				chess_board[_going_to_row][_going_to_col].set_color(color_before);
				return true;
			}
		}
	}

	else if (k_row + 2 <= 8 && k_col + 1 <= 8)
	{
		if (chess_board[k_row + 2][k_col + 1].get_busy() == true)
		{
			if (chess_board[k_row + 2][k_col + 1].get_color() == 'w')
			{
				cout << "------------------------------------\n";
				cout << "The KING is on <CHESS> by black KNIGHT\n";
				cout << "------------------------------------\n";
				chess_board[current_row][current_col].set_busy(true);
				chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
				chess_board[_going_to_row][_going_to_col].set_color(color_before);
				return true;
			}
		}
	}
	else if (k_row + 2 <= 8 && k_col - 1 <= 0)
	{
		if (chess_board[k_row + 2][k_col - 1].get_busy() == true)
		{
			if (chess_board[k_row + 2][k_col - 1].get_color() == 'w')
			{
				cout << "------------------------------------\n";
				cout << "The KING is on <CHESS> by black KNIGHT\n";
				cout << "------------------------------------\n";
				chess_board[current_row][current_col].set_busy(true);
				chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
				chess_board[_going_to_row][_going_to_col].set_color(color_before);
				return true;
			}
		}
	}

	else if (k_row - 1 >= 0 && k_col - 2 >= 0)
	{
		if (chess_board[k_row - 1][k_col - 2].get_busy() == true)
		{
			if (chess_board[k_row - 1][k_col - 2].get_color() == 'w')
			{
				cout << "------------------------------------\n";
				cout << "The KING is on <CHESS> by black KNIGHT\n";
				cout << "------------------------------------\n";
				chess_board[current_row][current_col].set_busy(true);
				chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
				chess_board[_going_to_row][_going_to_col].set_color(color_before);
				return true;
			}
		}
	}
	else if (k_row - 1 >= 0 && k_col + 2 >= 8)
	{
		if (chess_board[k_row - 1][k_col + 2].get_busy() == true)
		{
			if (chess_board[k_row - 1][k_col + 2].get_color() == 'w')
			{
				cout << "------------------------------------\n";
				cout << "The KING is on <CHESS> by black KNIGHT\n";
				cout << "------------------------------------\n";
				chess_board[current_row][current_col].set_busy(true);
				chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
				chess_board[_going_to_row][_going_to_col].set_color(color_before);
				return true;
			}
		}
	}
	else if (k_row + 1 <= 8 && k_col - 2 >= 0)
	{
		if (chess_board[k_row + 1][k_col - 2].get_busy() == true)
		{
			if (chess_board[k_row + 1][k_col - 2].get_color() == 'w')
			{
				cout << "------------------------------------\n";
				cout << "The KING is on <CHESS> by black KNIGHT\n";
				cout << "------------------------------------\n";
				chess_board[current_row][current_col].set_busy(true);
				chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
				chess_board[_going_to_row][_going_to_col].set_color(color_before);
				return true;
			}
		}
	}
	else if (k_row + 1 <= 8 && k_col + 2 >= 8)
	{
		if (chess_board[k_row + 1][k_col + 2].get_busy() == true)
		{
			if (chess_board[k_row + 1][k_col + 2].get_color() == 'w')
			{
				cout << "------------------------------------\n";
				cout << "The KING is on <CHESS> by black KNIGHT\n";
				cout << "------------------------------------\n";
				chess_board[current_row][current_col].set_busy(true);
				chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
				chess_board[_going_to_row][_going_to_col].set_color(color_before);
				return true;
			}
		}
	}

	//2) chek prom king position UP the bord for chess
	else if (chess_val_UP(k_row, k_col) == true)
	{
	chess_board[current_row][current_col].set_busy(true);
	chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
	chess_board[_going_to_row][_going_to_col].set_color(color_before);
		return true;
	}
	//3) chek prom king position DOWN the bord for chess
	else if (chess_val_DOWN(k_row, k_col) == true)
		{
		chess_board[current_row][current_col].set_busy(true);
		chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
		chess_board[_going_to_row][_going_to_col].set_color(color_before);
		return true;
	}
	//4)chek prom king position LEFT the bord for chess
	else if (chess_val_LEFT(k_row, k_col) == true)
		{
		chess_board[current_row][current_col].set_busy(true);
		chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
		chess_board[_going_to_row][_going_to_col].set_color(color_before);
		return true;
	}
	//5)chek prom king position RIGHT the bord for chess
	else if (chess_val_RIGHT(k_row, k_col) == true)
		{
		chess_board[current_row][current_col].set_busy(true);
		chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
		chess_board[_going_to_row][_going_to_col].set_color(color_before);
		return true;
	}
	//6)chek prom king position UP and LEFT the bord for chess
	else if (chess_val_UP_LEFT(k_row, k_col) == true)
		{
		chess_board[current_row][current_col].set_busy(true);
		chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
		chess_board[_going_to_row][_going_to_col].set_color(color_before);
		return true;
	}
	//7)chek prom king position UP and RIGHT the bord for chess
	else if (chess_val_UP_RIGHT(k_row, k_col) == true)
		{
		chess_board[current_row][current_col].set_busy(true);
		chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
		chess_board[_going_to_row][_going_to_col].set_color(color_before);
		return true;
	}
	//8)chek prom king position DOWN and LEFT the bord for chess
	else if (chess_val_DOWN_LEFT(k_row, k_col) == true)
		{
		chess_board[current_row][current_col].set_busy(true);
		chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
		chess_board[_going_to_row][_going_to_col].set_color(color_before);
		return true;
	}
	//9)chek prom king position DOWN and RIGHT the bord for chess
	else if (chess_val_DOWN_RIGHT(k_row, k_col) == true)
		{
		chess_board[current_row][current_col].set_busy(true);
		chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
		chess_board[_going_to_row][_going_to_col].set_color(color_before);
		return true;
	}

    }


	

	

	cout << "NO CHESS FOUND\n";
		chess_board[current_row][current_col].set_busy(true);
		chess_board[_going_to_row][_going_to_col].set_busy(false); //eaven if takes figure will be again true!
		chess_board[_going_to_row][_going_to_col].set_color(color_before);

	return false;

}

bool Board::chess_val_UP(int krow, int kcol)
{
	//see all the squares up to the fisrs busy square
	for (krow; krow >= 0; krow--)
	{
		if (chess_board[krow][kcol].get_busy() == true)
		{
			if (chess_board[krow][kcol].get_color() != player_turn)
			{
				if (chess_board[krow][kcol].get_symbol() == 'r' || chess_board[krow][kcol].get_symbol() == 'R'
					|| chess_board[krow][kcol].get_symbol() == 'k' || chess_board[krow][kcol].get_symbol() == 'K'
					|| chess_board[krow][kcol].get_symbol() == 'q' || chess_board[krow][kcol].get_symbol() == 'Q')
				{
					cout << "------------------------------------\n";
					cout << "The KING is on <CHESS> by black ROOK, Queen or KING\n";
					cout << "------------------------------------\n";
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
	
	}
	return false;

}
bool Board::chess_val_DOWN(int krow, int kcol)
{
	//see all the squares up to the fisrs busy square
	for (krow; krow <= 7; krow++)
	{
		if (chess_board[krow][kcol].get_busy() == true)
		{
			if (chess_board[krow][kcol].get_color() != player_turn)
			{
				if (chess_board[krow][kcol].get_symbol() == 'r' || chess_board[krow][kcol].get_symbol() == 'R'
					|| chess_board[krow][kcol].get_symbol() == 'k' || chess_board[krow][kcol].get_symbol() == 'K'
					|| chess_board[krow][kcol].get_symbol() == 'q' || chess_board[krow][kcol].get_symbol() == 'Q')
				{
					cout << "------------------------------------\n";
					cout << "The KING is on <CHESS> by black ROOK, Queen or KING\n";
					cout << "------------------------------------\n";
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}

	}
	return false;


}
bool Board::chess_val_RIGHT(int krow, int kcol)
{
	//see all the squares up to the fisrs busy square
	for (kcol; kcol >= 0; kcol--)
	{
		if (chess_board[krow][kcol].get_busy() == true)
		{
			if (chess_board[krow][kcol].get_color() != player_turn)
			{
				if (chess_board[krow][kcol].get_symbol() == 'r' || chess_board[krow][kcol].get_symbol() == 'R'
					|| chess_board[krow][kcol].get_symbol() == 'k' || chess_board[krow][kcol].get_symbol() == 'K'
					|| chess_board[krow][kcol].get_symbol() == 'q' || chess_board[krow][kcol].get_symbol() == 'Q')
				{
					cout << "------------------------------------\n";
					cout << "The KING is on <CHESS> by black ROOK, Queen or KING\n";
					cout << "------------------------------------\n";
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}

	}
	return false;



}
bool Board::chess_val_LEFT(int krow, int kcol)
{
	for (kcol; kcol <= 7; kcol++)
	{
		if (chess_board[krow][kcol].get_busy() == true)
		{
			if (chess_board[krow][kcol].get_color() != player_turn)
			{
				if (chess_board[krow][kcol].get_symbol() == 'r' || chess_board[krow][kcol].get_symbol() == 'R'
					|| chess_board[krow][kcol].get_symbol() == 'k' || chess_board[krow][kcol].get_symbol() == 'K'
					|| chess_board[krow][kcol].get_symbol() == 'q' || chess_board[krow][kcol].get_symbol() == 'Q')
				{
					cout << "------------------------------------\n";
					cout << "The KING is on <CHESS> by black ROOK, Queen or KING\n";
					cout << "------------------------------------\n";
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}

	}
	return false;


}
bool Board::chess_val_UP_LEFT(int krow, int kcol)
{
	for (krow; krow >= 0; krow--)
	{
		kcol--;
		if (kcol >= 0)
		{
			if (chess_board[krow][kcol].get_busy() == true)
			{
				if (chess_board[krow][kcol].get_color() != player_turn)
				{
					if    (chess_board[krow][kcol].get_symbol() == 'p' || chess_board[krow][kcol].get_symbol() == 'P'
						|| chess_board[krow][kcol].get_symbol() == 'b' || chess_board[krow][kcol].get_symbol() == 'B'
						|| chess_board[krow][kcol].get_symbol() == 'k' || chess_board[krow][kcol].get_symbol() == 'K'
						|| chess_board[krow][kcol].get_symbol() == 'q' || chess_board[krow][kcol].get_symbol() == 'Q')
					{
						cout << "------------------------------------\n";
						cout << "The KING is on <CHESS> by black ROOK, Queen or KING\n";
						cout << "------------------------------------\n";
						return true;
					}
					else
						return false;
				}
				else
					return false;
			}
		}

	}
	return false;


}
bool Board::chess_val_UP_RIGHT(int krow, int kcol)
{
	for (krow; krow >= 0; krow--)
	{
		kcol++;
		if (kcol <= 7)
		{
			if (chess_board[krow][kcol].get_busy() == true)
			{
				if (chess_board[krow][kcol].get_color() != player_turn)
				{
					if (chess_board[krow][kcol].get_symbol() == 'p' || chess_board[krow][kcol].get_symbol() == 'P'
						|| chess_board[krow][kcol].get_symbol() == 'b' || chess_board[krow][kcol].get_symbol() == 'B'
						|| chess_board[krow][kcol].get_symbol() == 'k' || chess_board[krow][kcol].get_symbol() == 'K'
						|| chess_board[krow][kcol].get_symbol() == 'q' || chess_board[krow][kcol].get_symbol() == 'Q')
					{
						cout << "------------------------------------\n";
						cout << "The KING is on <CHESS> by black ROOK, Queen or KING\n";
						cout << "------------------------------------\n";
						return true;
					}
					else
						return false;
				}
				else
					return false;
			}
		}

	}
	return false;

}
bool Board::chess_val_DOWN_LEFT(int krow, int kcol)
{
	for (krow; krow <= 7; krow++)
	{
		kcol--;
		if (kcol >= 0)
		{
			if (chess_board[krow][kcol].get_busy() == true)
			{
				if (chess_board[krow][kcol].get_color() != player_turn)
				{
					if (chess_board[krow][kcol].get_symbol() == 'p' || chess_board[krow][kcol].get_symbol() == 'P'
						|| chess_board[krow][kcol].get_symbol() == 'b' || chess_board[krow][kcol].get_symbol() == 'B'
						|| chess_board[krow][kcol].get_symbol() == 'k' || chess_board[krow][kcol].get_symbol() == 'K'
						|| chess_board[krow][kcol].get_symbol() == 'q' || chess_board[krow][kcol].get_symbol() == 'Q')
					{
						cout << "------------------------------------\n";
						cout << "The KING is on <CHESS> by black ROOK, Queen or KING\n";
						cout << "------------------------------------\n";
						return true;
					}
					else
						return false;
				}
				else
					return false;
			}
		}
	}
}
bool Board::chess_val_DOWN_RIGHT(int krow, int kcol)
{
	for (krow; krow <= 7; krow++)
	{
		kcol++;
		if (kcol <= 7)
		{
			if (chess_board[krow][kcol].get_busy() == true)
			{
				if (chess_board[krow][kcol].get_color() != player_turn)
				{
					if (chess_board[krow][kcol].get_symbol() == 'p' || chess_board[krow][kcol].get_symbol() == 'P'
						|| chess_board[krow][kcol].get_symbol() == 'b' || chess_board[krow][kcol].get_symbol() == 'B'
						|| chess_board[krow][kcol].get_symbol() == 'k' || chess_board[krow][kcol].get_symbol() == 'K'
						|| chess_board[krow][kcol].get_symbol() == 'q' || chess_board[krow][kcol].get_symbol() == 'Q')
					{
						cout << "------------------------------------\n";
						cout << "The KING is on <CHESS> by black ROOK, Queen or KING\n";
						cout << "------------------------------------\n";
						return true;
					}
					else
						return false;
				}
				else
					return false;
			}
		}
	}
}