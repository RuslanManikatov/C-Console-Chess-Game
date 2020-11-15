#include "Knight.h"

Knight::Knight()
{
	name = "Knight";
	color = 'x';
	symbol = 'x';
	first_move = false;
}
//we pass only the color of the figure, and according to the result, the letter will be 'n' or 'N'
Knight::Knight(char _color)
{
	first_move = false;
	name = "Knight";

	color = _color;
	if (color == 'w')
		symbol = 'N';
	else
		symbol = 'n';


}


string  Knight::get_name() const
{
	return name;
}

void    Knight::set_symbol(char _symbol)
{
	symbol = _symbol;
}
char    Knight::get_symbol() const
{
	return symbol;
}

void    Knight::set_color(char _color)
{
	color = _color;
	if (color == 'w')
		symbol = 'N';
	else
		symbol = 'n';
}
char    Knight::get_color() const
{
	return color;
}

void    Knight::first_set_move(bool _move)
{
	first_move = _move;
}
bool    Knight::first_get_move() const
{
	return first_move;
}
