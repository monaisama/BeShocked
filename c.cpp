#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Data
{
	unsigned int BlueTimes;
	unsigned int RedTimes;
	unsigned int BlueBlueTimes;
	unsigned int BlueRedTimes;
	unsigned int RedRedTimes;
	unsigned int RedBlueTimes;

	Data& operator+=(const Data& rhs)
	{
		BlueTimes += rhs.BlueTimes;
		RedTimes += rhs.RedTimes;
		BlueBlueTimes += rhs.BlueBlueTimes;
		BlueRedTimes += rhs.BlueRedTimes;
		RedRedTimes += rhs.RedRedTimes;
		RedBlueTimes += rhs.RedBlueTimes;

		return *this;
	}

	friend ostream& operator<<(ostream& out, Data& data)
	{
		out << "BlueTimes : " << data.BlueTimes << endl;
		out << "RedTimes : " << data.RedTimes << endl;
		out << "BlueBlueTimes : " << data.BlueBlueTimes << endl;
		out << "BlueRedTimes : " << data.BlueRedTimes << endl;
		out << "RedRedTimes : " << data.RedRedTimes << endl;
		out << "RedBlueTimes : " << data.RedBlueTimes << endl;
		
		out << "First is blue, Second is blue too. -> (BlueBlueTimes / (BlueBlueTimes + BlueRedTimes)) = " <<
			(float)data.BlueBlueTimes / (data.BlueBlueTimes + data.BlueRedTimes) << endl;
		
		return out;
	}
};

enum class Color : char
{
	BLUE,
	RED
};

class Ball
{
protected:
	Color color;
public:
	Ball(Color _color) : color(_color) {}
	Color GetColor() const { return color; }
};

enum class ContainerType : char
{
	NONE,
	BLUE_BLUE,
	BLUE_RED,
	RED_RED
};

class Container
{
private:
	Ball a, b;
public:
	Container(Ball _a, Ball _b) :a(_a), b(_b) {}

	const Ball& Random() const
	{
		return rand() % 2 ? a : b;
	}

	ContainerType GetType() const
	{
		switch (a.GetColor())
		{
		case Color::BLUE:
			return b.GetColor() == Color::BLUE ? ContainerType::BLUE_BLUE :
				ContainerType::BLUE_RED;
		case Color::RED:
			return b.GetColor() == Color::BLUE ? ContainerType::BLUE_RED :
				ContainerType::RED_RED;
		}
		return ContainerType::NONE;
	}
};

class Referee
{
protected:
	Container a, b, c;

	void Calc(Data& data, const Container& c, const Ball& ball)
	{
		switch (c.GetType())
		{
		case ContainerType::BLUE_BLUE:
			data.BlueTimes++;
			data.BlueBlueTimes++;
			break;
		case ContainerType::BLUE_RED:
			if (ball.GetColor() == Color::BLUE)
			{
				data.BlueTimes++;
				data.BlueRedTimes++;
			}
			else
			{
				data.RedTimes++;
				data.RedBlueTimes++;
			}
			break;
		case ContainerType::RED_RED:
			data.RedTimes++;
			data.RedRedTimes++;
			break;
		}
	}
public:
	Referee(): a(Ball(Color::RED), Ball(Color::RED)),
		b(Ball(Color::RED), Ball(Color::BLUE)),
		c(Ball(Color::BLUE), Ball(Color::BLUE))
	{
	}

	const Container& Random() const
	{
		int randi = rand() % 3;
		return (randi == 0 ? a : (randi == 1 ? b : c));
	}

	Data Round()
	{
		Data res = {0};
		const Container& c = Random();
		const Ball& b = c.Random();

		Calc(res, c, b);
		return res;
	}
};

int main()
{
	const int MAX_TIMES = 100000;
	Data data = {0};
	Referee referee;

	srand(time(NULL));
	for (int i = 0; i < MAX_TIMES; ++i)
	{
		data += referee.Round();
	}

	cout << data << endl;
	return 0;
}