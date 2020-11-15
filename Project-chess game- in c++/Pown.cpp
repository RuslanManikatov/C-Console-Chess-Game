#include "Pown.h"

Pown::Pown()
{
	name = "Pown";
	color = 'x';
	symbol = 'x';
	first_move = false;
}
//we pass only the color of the figure, and according to the result, the letter will be 'p' or 'P'
Pown::Pown(char _color)
{
	first_move = false;
	name = "Pown";

	color = _color;
	if (color == 'w')	
		symbol = 'P';	
	else
		symbol = 'p';
	

}


string  Pown::get_name() const
{
	return name;
}
void    Pown::set_name(string _name)
{
	name = _name;
}

void    Pown::set_symbol(char _symbol)
{
	symbol = _symbol;
}
char    Pown::get_symbol() const
{
	return symbol;
}

void    Pown::set_color(char _color)
{
	color = _color;

	color = _color;
	if (color == 'w')
		symbol = 'P';
	else
		symbol = 'p';
}
char    Pown::get_color() const
{
	return color;
}

void    Pown::first_set_move(bool _move)
{
	first_move = _move;
}
bool    Pown::first_get_move() const
{
	return first_move;
}