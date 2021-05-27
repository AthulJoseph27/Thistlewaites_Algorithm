#pragma once

#include <vector>
#include <iostream>

class Cube
{
public:
	std::vector<std::vector<char>> left = {{'B', 'B', 'B'},
										   {'B', 'B', 'B'},
										   {'B', 'B', 'B'}};
	std::vector<std::vector<char>> front = {{'R', 'R', 'R'},
											{'R', 'R', 'R'},
											{'R', 'R', 'R'}};
	std::vector<std::vector<char>> right = {{'G', 'G', 'G'},
											{'G', 'G', 'G'},
											{'G', 'G', 'G'}};
	std::vector<std::vector<char>> back = {{'O', 'O', 'O'},
										   {'O', 'O', 'O'},
										   {'O', 'O', 'O'}};
	std::vector<std::vector<char>> up = {{'Y', 'Y', 'Y'},
										 {'Y', 'Y', 'Y'},
										 {'Y', 'Y', 'Y'}};
	std::vector<std::vector<char>> down = {{'W', 'W', 'W'},
										   {'W', 'W', 'W'},
										   {'W', 'W', 'W'}};
	Cube() {}
	Cube(std::vector<std::vector<char>> l,
		 std::vector<std::vector<char>> f,
		 std::vector<std::vector<char>> r,
		 std::vector<std::vector<char>> b,
		 std::vector<std::vector<char>> u,
		 std::vector<std::vector<char>> d)
	{
		left = l;
		front = f;
		right = r;
		back = b;
		up = u;
		down = d;
	}
	void R()
	{
		char a, b, c;

		a = up[0][2];
		b = up[1][2];
		c = up[2][2];

		up[0][2] = front[0][2];
		up[1][2] = front[1][2];
		up[2][2] = front[2][2];

		front[0][2] = down[0][2];
		front[1][2] = down[1][2];
		front[2][2] = down[2][2];

		down[0][2] = back[2][0];
		down[1][2] = back[1][0];
		down[2][2] = back[0][0];

		back[2][0] = a;
		back[1][0] = b;
		back[0][0] = c;

		a = right[0][1];
		right[0][1] = right[1][0];
		right[1][0] = right[2][1];
		right[2][1] = right[1][2];
		right[1][2] = a;

		a = right[0][0];
		right[0][0] = right[2][0];
		right[2][0] = right[2][2];
		right[2][2] = right[0][2];
		right[0][2] = a;
	}
	void L()
	{
		char a, b, c;

		a = front[0][0];
		b = front[1][0];
		c = front[2][0];

		front[0][0] = up[0][0];
		front[1][0] = up[1][0];
		front[2][0] = up[2][0];

		up[0][0] = back[2][2];
		up[1][0] = back[1][2];
		up[2][0] = back[0][2];

		back[2][2] = down[0][0];
		back[1][2] = down[1][0];
		back[0][2] = down[2][0];

		down[0][0] = a;
		down[1][0] = b;
		down[2][0] = c;

		a = left[0][1];
		left[0][1] = left[1][0];
		left[1][0] = left[2][1];
		left[2][1] = left[1][2];
		left[1][2] = a;

		a = left[0][0];
		left[0][0] = left[2][0];
		left[2][0] = left[2][2];
		left[2][2] = left[0][2];
		left[0][2] = a;
	}
	void U()
	{

		char a, b, c;
		a = left[0][0];
		b = left[0][1];
		c = left[0][2];

		left[0][0] = front[0][0];
		left[0][1] = front[0][1];
		left[0][2] = front[0][2];

		front[0][0] = right[0][0];
		front[0][1] = right[0][1];
		front[0][2] = right[0][2];

		right[0][0] = back[0][0];
		right[0][1] = back[0][1];
		right[0][2] = back[0][2];

		back[0][0] = a;
		back[0][1] = b;
		back[0][2] = c;

		a = up[0][1];
		up[0][1] = up[1][0];
		up[1][0] = up[2][1];
		up[2][1] = up[1][2];
		up[1][2] = a;

		a = up[0][0];
		up[0][0] = up[2][0];
		up[2][0] = up[2][2];
		up[2][2] = up[0][2];
		up[0][2] = a;
	}
	void D()
	{
		char a, b, c;
		a = left[2][0];
		b = left[2][1];
		c = left[2][2];

		left[2][0] = back[2][0];
		left[2][1] = back[2][1];
		left[2][2] = back[2][2];

		back[2][0] = right[2][0];
		back[2][1] = right[2][1];
		back[2][2] = right[2][2];

		right[2][0] = front[2][0];
		right[2][1] = front[2][1];
		right[2][2] = front[2][2];

		front[2][0] = a;
		front[2][1] = b;
		front[2][2] = c;

		a = down[0][1];
		down[0][1] = down[1][0];
		down[1][0] = down[2][1];
		down[2][1] = down[1][2];
		down[1][2] = a;

		a = down[0][0];
		down[0][0] = down[2][0];
		down[2][0] = down[2][2];
		down[2][2] = down[0][2];
		down[0][2] = a;
	}
	void F()
	{
		char a, b, c;

		a = left[0][2];
		b = left[1][2];
		c = left[2][2];

		left[0][2] = down[0][0];
		left[1][2] = down[0][1];
		left[2][2] = down[0][2];

		down[0][0] = right[2][0];
		down[0][1] = right[1][0];
		down[0][2] = right[0][0];

		right[2][0] = up[2][2];
		right[1][0] = up[2][1];
		right[0][0] = up[2][0];

		up[2][2] = a;
		up[2][1] = b;
		up[2][0] = c;

		a = front[0][1];
		front[0][1] = front[1][0];
		front[1][0] = front[2][1];
		front[2][1] = front[1][2];
		front[1][2] = a;

		a = front[0][0];
		front[0][0] = front[2][0];
		front[2][0] = front[2][2];
		front[2][2] = front[0][2];
		front[0][2] = a;
	}
	void B()
	{

		char a, b, c;

		a = left[0][0];
		b = left[1][0];
		c = left[2][0];

		left[0][0] = up[0][2];
		left[1][0] = up[0][1];
		left[2][0] = up[0][0];

		up[0][2] = right[2][2];
		up[0][1] = right[1][2];
		up[0][0] = right[0][2];

		right[2][2] = down[2][0];
		right[1][2] = down[2][1];
		right[0][2] = down[2][2];

		down[2][0] = a;
		down[2][1] = b;
		down[2][2] = c;

		a = back[0][1];
		back[0][1] = back[1][0];
		back[1][0] = back[2][1];
		back[2][1] = back[1][2];
		back[1][2] = a;

		a = back[0][0];
		back[0][0] = back[2][0];
		back[2][0] = back[2][2];
		back[2][2] = back[0][2];
		back[0][2] = a;
	}
	void r()
	{
		char a, b, c;

		a = front[0][2];
		b = front[1][2];
		c = front[2][2];

		front[0][2] = up[0][2];
		front[1][2] = up[1][2];
		front[2][2] = up[2][2];

		up[0][2] = back[2][0];
		up[1][2] = back[1][0];
		up[2][2] = back[0][0];

		back[0][0] = down[2][2];
		back[1][0] = down[1][2];
		back[2][0] = down[0][2];

		down[0][2] = a;
		down[1][2] = b;
		down[2][2] = c;

		a = right[0][1];
		right[0][1] = right[1][2];
		right[1][2] = right[2][1];
		right[2][1] = right[1][0];
		right[1][0] = a;

		a = right[0][0];
		right[0][0] = right[0][2];
		right[0][2] = right[2][2];
		right[2][2] = right[2][0];
		right[2][0] = a;
	}
	void l()
	{
		char a, b, c;

		a = up[0][0];
		b = up[1][0];
		c = up[2][0];

		up[0][0] = front[0][0];
		up[1][0] = front[1][0];
		up[2][0] = front[2][0];

		front[0][0] = down[0][0];
		front[1][0] = down[1][0];
		front[2][0] = down[2][0];

		down[0][0] = back[2][2];
		down[1][0] = back[1][2];
		down[2][0] = back[0][2];

		back[2][2] = a;
		back[1][2] = b;
		back[0][2] = c;

		a = left[0][1];
		left[0][1] = left[1][2];
		left[1][2] = left[2][1];
		left[2][1] = left[1][0];
		left[1][0] = a;

		a = left[0][0];
		left[0][0] = left[0][2];
		left[0][2] = left[2][2];
		left[2][2] = left[2][0];
		left[2][0] = a;
	}
	void u()
	{
		char a, b, c;
		a = left[0][0];
		b = left[0][1];
		c = left[0][2];

		left[0][0] = back[0][0];
		left[0][1] = back[0][1];
		left[0][2] = back[0][2];

		back[0][0] = right[0][0];
		back[0][1] = right[0][1];
		back[0][2] = right[0][2];

		right[0][0] = front[0][0];
		right[0][1] = front[0][1];
		right[0][2] = front[0][2];

		front[0][0] = a;
		front[0][1] = b;
		front[0][2] = c;

		a = up[0][1];
		up[0][1] = up[1][2];
		up[1][2] = up[2][1];
		up[2][1] = up[1][0];
		up[1][0] = a;

		a = up[0][0];
		up[0][0] = up[0][2];
		up[0][2] = up[2][2];
		up[2][2] = up[2][0];
		up[2][0] = a;
	}
	void d()
	{
		char a, b, c;
		a = left[2][0];
		b = left[2][1];
		c = left[2][2];

		left[2][0] = front[2][0];
		left[2][1] = front[2][1];
		left[2][2] = front[2][2];

		front[2][0] = right[2][0];
		front[2][1] = right[2][1];
		front[2][2] = right[2][2];

		right[2][0] = back[2][0];
		right[2][1] = back[2][1];
		right[2][2] = back[2][2];

		back[2][0] = a;
		back[2][1] = b;
		back[2][2] = c;

		a = down[0][1];
		down[0][1] = down[1][2];
		down[1][2] = down[2][1];
		down[2][1] = down[1][0];
		down[1][0] = a;

		a = down[0][0];
		down[0][0] = down[0][2];
		down[0][2] = down[2][2];
		down[2][2] = down[2][0];
		down[2][0] = a;
	}
	void f()
	{
		char a, b, c;

		a = left[0][2];
		b = left[1][2];
		c = left[2][2];

		left[0][2] = up[2][2];
		left[1][2] = up[2][1];
		left[2][2] = up[2][0];

		up[2][2] = right[2][0];
		up[2][1] = right[1][0];
		up[2][0] = right[0][0];

		right[2][0] = down[0][0];
		right[1][0] = down[0][1];
		right[0][0] = down[0][2];

		down[0][0] = a;
		down[0][1] = b;
		down[0][2] = c;

		a = front[0][1];
		front[0][1] = front[1][2];
		front[1][2] = front[2][1];
		front[2][1] = front[1][0];
		front[1][0] = a;

		a = front[0][0];
		front[0][0] = front[0][2];
		front[0][2] = front[2][2];
		front[2][2] = front[2][0];
		front[2][0] = a;
	}
	void b()
	{
		char a, b, c;

		a = left[0][0];
		b = left[1][0];
		c = left[2][0];

		left[0][0] = down[2][0];
		left[1][0] = down[2][1];
		left[2][0] = down[2][2];

		down[2][0] = right[2][2];
		down[2][1] = right[1][2];
		down[2][2] = right[0][2];

		right[2][2] = up[0][2];
		right[1][2] = up[0][1];
		right[0][2] = up[0][0];

		up[0][2] = a;
		up[0][1] = b;
		up[0][0] = c;

		a = back[0][1];
		back[0][1] = back[1][2];
		back[1][2] = back[2][1];
		back[2][1] = back[1][0];
		back[1][0] = a;

		a = back[0][0];
		back[0][0] = back[0][2];
		back[0][2] = back[2][2];
		back[2][2] = back[2][0];
		back[2][0] = a;
	}
	void show()
	{
		for (int i = 0; i < 3; i++)
			std::cout << "  ";
		for (int i = 0; i < 3; i++)
			std::cout << up[0][i] << " ";
		for (int i = 0; i < 3; i++)
			std::cout << "  ";

		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
			std::cout << "  ";
		for (int i = 0; i < 3; i++)
			std::cout << up[1][i] << " ";
		for (int i = 0; i < 3; i++)
			std::cout << "  ";

		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
			std::cout << "  ";
		for (int i = 0; i < 3; i++)
			std::cout << up[2][i] << " ";
		for (int i = 0; i < 3; i++)
			std::cout << "  ";

		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
			std::cout << left[0][i] << " ";
		for (int i = 0; i < 3; i++)
			std::cout << front[0][i] << " ";
		for (int i = 0; i < 3; i++)
			std::cout << right[0][i] << " ";

		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
			std::cout << left[1][i] << " ";
		for (int i = 0; i < 3; i++)
			std::cout << front[1][i] << " ";
		for (int i = 0; i < 3; i++)
			std::cout << right[1][i] << " ";

		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
			std::cout << left[2][i] << " ";
		for (int i = 0; i < 3; i++)
			std::cout << front[2][i] << " ";
		for (int i = 0; i < 3; i++)
			std::cout << right[2][i] << " ";

		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
			std::cout << "  ";
		for (int i = 0; i < 3; i++)
			std::cout << down[0][i] << " ";
		for (int i = 0; i < 3; i++)
			std::cout << "  ";

		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
			std::cout << "  ";
		for (int i = 0; i < 3; i++)
			std::cout << down[1][i] << " ";
		for (int i = 0; i < 3; i++)
			std::cout << "  ";

		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
			std::cout << "  ";
		for (int i = 0; i < 3; i++)
			std::cout << down[2][i] << " ";
		for (int i = 0; i < 3; i++)
			std::cout << "  ";

		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
			std::cout << "  ";
		for (int i = 2; i >= 0; i--)
			std::cout << back[2][i] << " ";
		for (int i = 0; i < 3; i++)
			std::cout << "  ";

		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
			std::cout << "  ";
		for (int i = 2; i >= 0; i--)
			std::cout << back[1][i] << " ";
		for (int i = 0; i < 3; i++)
			std::cout << "  ";

		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
			std::cout << "  ";
		for (int i = 2; i >= 0; i--)
			std::cout << back[0][i] << " ";
		for (int i = 0; i < 3; i++)
			std::cout << "  ";

		std::cout << std::endl;
	}
};