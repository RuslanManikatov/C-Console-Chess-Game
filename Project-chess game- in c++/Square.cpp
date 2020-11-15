#include "Square.h"

// The Board of the chess will be made from 8x8 squares
Square::Square()
{
	busy = false;
	color = 'x';
	current_figure = nullptr;
	symbol = '*';
}


void Square::set_busy(bool _busy)
{
	busy = _busy;
}
bool Square::get_busy() const
{
	return busy;
}

void Square::set_color(char _color)
{
	color = _color;
}
char Square::get_color() const
{
	return color;
}

void Square::set_figure(Figure figure)
{
	current_figure = &figure;
}


void Square::set_symbol(char _symbol)
{
	symbol = _symbol;
}
char Square::get_symbol() const
{
	return symbol;
}

void    Square::set_name(string name)
{
}
string  Square::get_name() const
{
	return name;
}

//put and remove Figures from the square! Just allocate the pointer to point * to a new figure!
void Square::put_new_figure(Figure &figure)
{
	current_figure = &figure;
	set_symbol(figure.get_symbol());
	set_color(figure.get_color());
	set_busy(true);
}
void Square::remove_figure()
{
	current_figure = nullptr;
	set_symbol('*');
	set_color('x');
	set_busy(false);

}