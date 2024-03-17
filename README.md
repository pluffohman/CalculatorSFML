# SFML Calculator

In this project I used SFML/Graphics library to male a window application Calculator.

I have realised such buttons as digits [0;9], symbols of mathematical operations {+,-,%,*,/} and additional buttons.

## Let's run this project:

<p align="center">
  <img width="300" height="400" src="https://github.com/pluffohman/CalculatorSFML/assets/144831566/35e4a30c-046b-4f0c-8bdb-00db86cd5eff">
</p>

So, we can see our buttons and our output field. Here are also buttons FF, which are not connected to anything, and can be edited.
I used this font: [BankGothicMdBT](https://fonts-online.ru/fonts/bankgothic-md-bt)

## Mechanics and algorithms

I was making this project while studying object oriented programming, so I had to realise different methods which are used in classes. 
The main idea was in using $inheritance$. For example:

```c++
class Button2 : public Butt {
	Texture textButt;
public:
	Button2() {
		textButt.loadFromFile("but.jpg");
		butt.setTexture(&textButt);
	}
	void printButton2(RenderWindow& win){
		printButt(win);
	}
};
```
So, i do not need to rewrite my functions again. It's practically useful thing.

## Conclusion

In my opinion, this project is quite an ineresting and it really helped me to learn more about SFML and object oriented programming.
