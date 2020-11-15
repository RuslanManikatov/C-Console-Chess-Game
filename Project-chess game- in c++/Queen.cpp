#include "Queen.h"


Queen::Queen()
{
	name = "Queen";
	color = 'x';
	symbol = 'x';
	first_move = false;
}
//we pass only the color of the figure, and according to the result, the letter will be 'q' or 'Q'
Queen::Queen(char _color)
{
	first_move = false;
	name = "Queen";

	color = _color;
	if (color == 'w')
		symbol = 'Q';
	else
		symbol = 'q';


}


string  Queen::get_name() const
{
	return name;
}

void    Queen::set_symbol(char _symbol)
{
	symbol = _symbol;
}
char    Queen::get_symbol() const
{
	return symbol;
}

void    Queen::set_color(char _color)
{
	color = _color;
	if (color == 'w')
		symbol = 'Q';
	else
		symbol = 'q';
}
char    Queen::get_color() const
{
	return color;
}

void    Queen::first_set_move(bool _move)
{
	first_move = _move;
}
bool    Queen::first_get_move() const
{
	return first_move;
}
