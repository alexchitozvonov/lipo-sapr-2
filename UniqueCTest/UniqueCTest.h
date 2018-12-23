#include <pcrecpp.h>	// PCRE library
#include <iostream>		// ifstream/ofstream/fstream
#include <cstdlib>
#include "stdio.h"
#include <string>
#include <pcrecpp.h>	// PCRE library
#include <sstream>		// std::stringstream
#include <algorithm>    // std::find
#include <iterator>		// std::vector::iterator
#include <vector>		// std::vector
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace std;

class UniqueCTest : public CppUnit::TestCase
{
	public:
		void TestConstructor();
		void TestGetList();
		
		CPPUNIT_TEST_SUITE( UniqueCTest );
		CPPUNIT_TEST( TestConstructor );
		CPPUNIT_TEST( TestGetList );
		CPPUNIT_TEST_SUITE_END();
};