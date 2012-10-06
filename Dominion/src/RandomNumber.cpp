#include "RandomNumber.h"

#include <ctime>

using namespace std;

MTRand_int32 RandomNumber::random((unsigned long)time(0));

RandomNumber::RandomNumber()
{

}
RandomNumber::~RandomNumber()
{

}
