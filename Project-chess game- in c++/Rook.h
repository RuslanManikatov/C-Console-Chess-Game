#pragma once

#include "Figure.h"


class Rook : public Figure
{
private:




public:
	Rook();
	//we pass only the color of the figure, and according to the result, the letter will be 'r' or 'R'
	Rook(char _color);

	string  get_name() const;

	void    set_symbol(char _symbol);
	char    get_symbol() const;

	void    set_color(char _color);
	char    get_color() const;

	void    first_set_move(bool _move);
	bool    first_get_move() const;
};




