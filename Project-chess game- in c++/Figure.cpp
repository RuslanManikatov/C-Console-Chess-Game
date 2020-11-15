#include "Figure.h"

Figure::Figure()
{

}
Figure::Figure(char _color)
{
	color = _color;
}


void    Figure::set_name(string name)
{
}
string  Figure::get_name() const
{
	return name;
}

void    Figure::set_symbol(char _symbol)
{
	symbol = _symbol;
}
char    Figure::get_symbol() const
{
	return symbol;
}

void    Figure::set_color(char _color)
{
	color = _color;
}
char    Figure::get_color() const
{
	return color;
}

void    Figure::set_first_move(bool _move)
{
	first_move = _move;
}
bool    Figure::get_first_move() const
{
	return first_move;
}

int     Figure::get_king_row_position() const
{
	return king_row_position;
}
void    Figure::set_king_row_position(int new_position)
{
	king_row_position = new_position;
}
int     Figure::get_king_col_position() const
{
	return king_col_position;
}
void    Figure::set_king_col_position(int new_position)
{
	king_col_position = new_position;
}