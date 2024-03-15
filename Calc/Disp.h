#pragma once

#include "Strok.h";
#include <SFML/Graphics.hpp>
using namespace sf;
class Disp {
	RectangleShape rekt;
	Strok str;
	Text txt;
	Font font;
public:
	Disp() {
		font.loadFromFile("BankGothic Md BT Medium.otf");
		txt.setFont(font);
		txt.setString(str.getStr());
		rekt.setFillColor(Color::Black);
		rekt.setPosition(5, 5);
		rekt.setSize(Vector2f(590, 190));
		rekt.setOutlineColor(Color::White);
		rekt.setOutlineThickness(5);
	}
	Strok& getStrok() {
		return str;
	}
	void printDisp(RenderWindow& win) {
		txt.setString(str.getStr());
		win.draw(rekt);
		win.draw(txt);
	}
};