#include "Rook.h"



Rook::Rook()
{
	name = "Rook";
	color = 'x';
	symbol = 'x';
	first_move = false;
}
//we pass only the color of the figure, and according to the result, the letter will be 'r' or 'R'
Rook::Rook(char _color)
{
	first_move = false;
	name = "Rook";

	color = _color;
	if (color == 'w')
		symbol = 'R';
	else
		symbol = 'r';


}


string  Rook::get_name() const
{
	return name;
}

void    Rook::set_symbol(char _symbol)
{
	symbol = _symbol;
}
char    Rook::get_symbol() const
{
	return symbol;
}

void    Rook::set_color(char _color)
{
	color = _color;
	if (color == 'w')
		symbol = 'R';
	else
		symbol = 'r';
}
char    Rook::get_color() const
{
	return color;
}

void    Rook::first_set_move(bool _move)
{
	first_move = _move;
}
bool    Rook::first_get_move() const
{
	return first_move;
}
