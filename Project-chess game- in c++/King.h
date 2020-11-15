#pragma once


#include "Figure.h"


class King : public Figure
{
private:




public:
	King();
	//we pass only the color of the figure, and according to the result, the letter will be 'k' or 'K'
	King(char _color);

	string  get_name() const;

	void    set_symbol(char _symbol);
	char    get_symbol() const;

	void    set_color(char _color);
	char    get_color() const;

	void    first_set_move(bool _move);
	bool    first_get_move() const;

	int     get_king_row_position() const;
	void    set_king_row_position(int new_position);
	int     get_king_col_position() const;
	void    set_king_col_position(int new_position);
};





