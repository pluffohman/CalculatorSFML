#pragma once
#include "Button2.h"
#include <cmath>
class KeyPad {
	Button2 **button;
	int row;
	int column;
public:
	KeyPad(int row, int column, int width, int hieght) :row{ row }, column{column} {
		button = new Button2*[row];
		for (size_t i = 0; i < row; i++)
		{
			button[i] = new Button2[column];
			for (size_t j = 0; j < column; j++)
			{
				button[i][j].resize(width, hieght, row, column, i, j, 400);
			}
		}
		nump();

	}

	void print(RenderWindow& win) {
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < column; j++) {
				button[i][j].printButton2(win);
			}
		}
	}
	void mousePresKeyPad(RenderWindow& win, Event& event, Strok& strok) {
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < column; j++) {
				button[i][j].mousePresBut(win, event, strok);
			}
		}
	}

	void nump() {
		int k = 1;
		for (size_t i = 0; i < 3; i++)
		{
			for(size_t j = 0; j < 3; j++) {
				button[i][j].rename(to_string(k));
				k++;
			}
		}
		button[3][0].rename("0");//вот так объ€вл€ем отдельные кнопки...
		button[1][3].rename("+");
		button[2][3].rename("-");
		button[3][3].rename("=");
		button[0][3].rename("C");
		button[3][1].rename("*");
		button[3][2].rename("/");
		button[4][0].rename("%");
		button[4][1].rename("^");
		//переходим в Strok
	}

	~KeyPad(){
		for (size_t i = 0; i < row; i++)
		{
			delete[] button[i];
		}
		delete[] button;
	}
};