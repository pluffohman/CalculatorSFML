#pragma once
#include <SFML\Graphics.hpp>
#include "Strok.h"
#include <iostream>
using namespace std;
using namespace sf;


class Butt {
protected:
	Font font;
	RectangleShape butt;
	Text txt;
	Color color1;
	Color color2 = Color::Blue;
	Color color3 = Color::Green;
public:
	Butt(int x, int y, int width, int height, Color color, String text){
		butt.setPosition(x, y);
		butt.setSize(Vector2f(width, height));
		color1 = color;
		butt.setFillColor(color1);
		txt.setString(text);
		txt.setPosition(x+25, y+15);
		txt.setFillColor(Color::White);
		txt.setCharacterSize(20);
		font.loadFromFile("BankGothic Md BT Medium.otf");
		txt.setFont(font);
	}
	Butt() :Butt(0, 0, 50, 30, Color::Cyan, "FF") {}

	void resize(float widht, float hieght, int row, int column, int i, int j, float ots) { 
		float widBot = widht / column;
		float hiBot = (hieght - ots) / row;
		float gap = 10;
		float x = widBot * j + gap;
		float y = hiBot * i + gap + ots;
		butt.setPosition(x, y);
		butt.setSize(Vector2f(widBot - (2 * gap), hiBot - (2 * gap)));
		Vector2f centerButt = Vector2f(x + widBot / 2, y + hiBot / 2);
		txt.setPosition(centerButt.x - txt.getGlobalBounds().width*2, centerButt.y - txt.getGlobalBounds().height*4);
		txt.setCharacterSize(60);
	}

	void rename(String text) {

		txt.setString(text);

	}

	void printButt(RenderWindow& win) {
		win.draw(butt);
		win.draw(txt);
	}
	void mousePresBut(RenderWindow& win, Event& event, Strok& strok) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.key.code == Mouse::Left) {
				if (butt.getGlobalBounds().contains(Mouse::getPosition(win).x, Mouse::getPosition(win).y))
				{
					butt.setFillColor(color3);
					strok.add(txt.getString());
				}

			}
		}
		else {
			if (butt.getGlobalBounds().contains(Mouse::getPosition(win).x, Mouse::getPosition(win).y))
			{
				butt.setFillColor(color2);
			}
			else {
				butt.setFillColor(color1);
			}
		}
	}
};
