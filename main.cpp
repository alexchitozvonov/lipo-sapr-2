#include <cstdlib>
#include <iostream>		// I/O Stream Library
#include "stdio.h"
#include <pcrecpp.h>	// PCRE library
#include <cstring>		// std::string
#include <ctype.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "UniqueC/UniqueC.h"
#include "UniqueCTest/UniqueCTest.h"

using namespace std;

int main(int argc, char* argv[]) {

	CPPUNIT_TEST_SUITE_REGISTRATION( UniqueCTest );
	
	if ( argc >= 2 )
	{
		if ( strcmp(argv[1], "-t\n") || strcmp(argv[1], "--test\n") ) 
		{
			CppUnit::Test *test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
			CppUnit::TextTestRunner runner;
			runner.addTest(test);
			
			runner.run();
			
			exit(0);
		}
	}
	
	UniqueC uniqueC;
	
	std::cout << uniqueC.GetList() << std::endl;
}