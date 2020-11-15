#pragma once
#include "Figure.h"

class Square
{
private:
	bool   busy;
	char   color;	
	char   symbol;
	string name;
	


public:

	Figure* current_figure;

	Square();
	void set_busy(bool _busy);
	bool get_busy() const;

	void set_color(char _color);
	char get_color() const;

	void set_figure(Figure figure);
    

	void set_symbol(char _symbol);
	char get_symbol() const ; 
	
	void set_name(string name);
	string get_name() const;

	void put_new_figure(Figure &figure);
	void remove_figure();


};

