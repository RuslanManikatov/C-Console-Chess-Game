#include "Bishop.h"



Bishop::Bishop()
{
	name = "Bishop ";
	color = 'x';
	symbol = 'x';
	first_move = false;
}
//we pass only the color of the figure, and according to the result, the letter will be 'p' or 'P'
Bishop::Bishop(char _color)
{
	first_move = false;
	name = "Bishop";

	color = _color;
	if (color == 'w')
		symbol = 'B';
	else
		symbol = 'b';


}


string  Bishop::get_name() const
{
	return name;
}

void    Bishop::set_symbol(char _symbol)
{
	symbol = _symbol;
}
char    Bishop::get_symbol() const
{
	return symbol;
}

void    Bishop::set_color(char _color)
{
	color = _color;
	if (color == 'w')
		symbol = 'B';
	else
		symbol = 'b';
}
char    Bishop::get_color() const
{
	return color;
}

void    Bishop::first_set_move(bool _move)
{
	first_move = _move;
}
bool    Bishop::first_get_move() const
{
	return first_move;
}
