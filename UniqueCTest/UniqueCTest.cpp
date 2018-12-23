#include "UniqueCTest.h"
#include "../UniqueC/UniqueC.h"

void UniqueCTest::TestConstructor() 
{
	UniqueC uniqueC;
	
	const char* errorMessage2 = "UniqueCTest: regular expression isn't defined in constructor";
	CPPUNIT_ASSERT_MESSAGE(errorMessage2, uniqueC.mainRegexp != "");
}

void UniqueCTest::TestGetList() 
{
	const char* errorMessage = "TestGetList: Unique C files list must not be empty";
	
	UniqueC uniqueC;
	string list = uniqueC.GetList();
	
	CPPUNIT_ASSERT_MESSAGE(errorMessage, list != "");
};