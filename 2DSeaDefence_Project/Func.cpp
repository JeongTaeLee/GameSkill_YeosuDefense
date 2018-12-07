#include "DXUT.h"
#include "Func.h"
#include <random>

int GetRandomNumber(int min, int max)
{
	random_device rn;
	mt19937_64 rnd(rn());

	uniform_int_distribution<int> range(min, max);

	return range(rnd);
}
