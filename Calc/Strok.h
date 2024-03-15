#pragma once
#include "iostream"
#include <string>
using namespace std;
class Strok {
	string str;
	string a;
	string b;
	string z;
	bool chitst = false;
public:
	Strok() {
		str = "";
	}

	void add(string str) {
		if (chitst) { 
			this->str = ""; 
			chitst = false;
		}
		if (str == "C") {
			a = "";
			b = "";
			z = "";
			this->str = "";
			return;
		}
		
		if (str != "="//здесь //добавить по аналогии
			and str != "+"
			and str != "-"
			and str != "*"
			and str != "/"
			and str != "%"
			and str != "^"
			and z.empty() ){
			a += str;
			this->str += str;
		}
		else if ((str == "+"//это не трогать отрабатываем первый минус
			or str == "-")
			and a.empty()){
			if (str == "-") {
				a += str;
				this->str += str;
			}

		}
		else if ((str == "+"//добавить по аналогии
			or str == "-"
			or str == "*"
			or str == "%"
			or str == "^"
			or str == "/")
			and b.empty()
			and !a.empty()) {
			if (z.empty()) {
				z = str;
				this->str += str;
			}
			else {
				z = str;
				this->str[this->str.length() - 1] = str[0];
			}
			

		}
		else if (str != "="//добавить по аналогии
			and str != "+"
			and str != "-"
			and str != "*"
			and str != "/"
			and str != "%"
			and str != "^"
			and !z.empty()) {
			b += str;
			this->str += str;

		}
		else if (str == "=") {
			if (b.empty()) {
				this->str = a;
				a = "";
				b = "";
				z = "";
				chitst = true;
			}
			else {
				switch (z[0])//добавить по аналогии->
				{
				case '+':
					this->str = to_string(stof(a) + stof(b));
					break;
				case '-':
					this->str = to_string(stof(a) - stof(b));
					break;
				case '*':
					this->str = to_string(stof(a) * stof(b));
					break;
				case '/':
					if (stof(b) == 0) {
						this->str = "ERROR";
						break;
					}
					this->str = to_string(stof(a)*1.0 / stof(b)*1.0);
					break;
				case '%':
					this->str = to_string(int(stof(a) / stof(b)));
					break;
				case '^':
					this->str = to_string(pow(stof(a), stof(b)));
					break;
				default:
					break;
				}
				a = "";
				b = "";
				z = "";
				chitst = true;
			}
		}

		cout << this->str << endl;
	}
	string getStr() {
		return this->str;
	}
};