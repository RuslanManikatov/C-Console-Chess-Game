#pragma once
#include "Figure.h"

class Pown : public Figure
{
private:
	 
	
	

public:
	Pown();
	//we pass only the color of the figure, and according to the result, the letter will be 'p' or 'P'
	Pown( char _color);
	
	string  get_name() const;
	void    set_name(string _name);

	void    set_symbol(char _symbol);
	char    get_symbol() const;

	void    set_color(char _color);
	char    get_color() const;

	void    first_set_move(bool _move);
	bool    first_get_move() const;
};

