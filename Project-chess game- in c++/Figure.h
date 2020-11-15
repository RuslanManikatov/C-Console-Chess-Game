#pragma once
#include <iostream>
#include <string>
using namespace std;

class Figure
{
protected:
  string name;
	char symbol;
	char color;
	bool first_move;
	int  king_row_position;
	int  king_col_position;

public:
	

	Figure();
	Figure(char _color);

	virtual void    set_name(string name);
	virtual string  get_name() const;

	virtual void    set_symbol(char symbol);
	virtual char    get_symbol() const;

	virtual void    set_color(char color);
	virtual char    get_color() const;

	virtual void    set_first_move(bool move);
	virtual bool    get_first_move() const;

	virtual int     get_king_row_position() const;
	virtual void    set_king_row_position(int new_position);
	virtual int     get_king_col_position() const;
	virtual void    set_king_col_position(int new_position);
};

