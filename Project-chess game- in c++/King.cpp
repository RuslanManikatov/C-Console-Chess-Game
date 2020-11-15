#include "King.h"


King::King()
{
	name = "King";
	color = 'x';
	symbol = 'x';
	first_move = false;
}
//we pass only the color of the figure, and according to the result, the letter will be 'k' or 'K'
King::King(char _color)
{
	first_move = false;
	name = "King";

	color = _color;
	if (color == 'w')
	{
		symbol = 'K';
		king_row_position = 0;
		king_col_position = 4;
	}
	else
	{
		king_row_position = 7;
		king_col_position = 4;
		symbol = 'k';
	}

}


string  King::get_name() const
{
	return name;
}

void    King::set_symbol(char _symbol)
{
	symbol = _symbol;
}
char    King::get_symbol() const
{
	return symbol;
}

void    King::set_color(char _color)
{
	color = _color;
	if (color == 'w')
	{
		symbol = 'K';
		king_row_position = 0;
		king_col_position = 4;
	}
	else
	{
		king_row_position = 7;
		king_col_position = 4;
		symbol = 'k';
	}
}
char    King::get_color() const
{
	return color;
}

void    King::first_set_move(bool _move)
{
	first_move = _move;
}
bool    King::first_get_move() const
{
	return first_move;
}


//to know the exactly position on the Board the King is!
int     King::get_king_row_position() const
{
	return king_row_position;
}
void    King::set_king_row_position(int new_position)
{
	king_row_position = new_position;
}

int     King::get_king_col_position() const
{
	return king_col_position;
}
void    King::set_king_col_position(int new_position)
{
	king_col_position = new_position;
}

