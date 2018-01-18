// TestRandomEx.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <random> // for std::random_device and std::mt19937
#include <iostream>

int getRandomNumber(int min, int max)
{
	static std::random_device rd;
	static std::mt19937 mersenne{ rd() };
	static const double fraction = 1.0 / (static_cast<double>(mersenne.max()) + 1.0);
	return min + static_cast<int>((max - min + 1) * (mersenne() * fraction));
}

int main()
{

	int rdm;
	int sum = 0;
	double ave = 0;
	double avesum = 0;
	for (int j = 0; j < 100; ++j)
	{
		for (int i = 0; i < 10000; ++i)
		{
			rdm = getRandomNumber(1, 9999);
			if (rdm <= 3333)
				sum += 0;
			if (rdm > 3333 && rdm <= 6666)
				sum += 1;
			if (rdm > 6666)
				sum += 2;
		}
		ave = static_cast<double>(sum) / 10000;
		sum = 0;
		avesum += ave;
	}
	avesum = avesum / 100;
	std::cout << "sum is " << avesum << "\n";
    return 0;
}

