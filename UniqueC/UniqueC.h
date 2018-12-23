#include <cstdlib>
#include <iostream>		// I/O Stream Library
#include "stdio.h"
#include <string>
#include <pcrecpp.h>	// PCRE library
#include <sstream>		// std::stringstream
#include <algorithm>    // std::find
#include <iterator>		// std::vector::iterator
#include <vector>		// std::vector

using namespace std;

class UniqueC
{
	public:
		UniqueC();
		string GetList();
		const char* mainRegexp;
};