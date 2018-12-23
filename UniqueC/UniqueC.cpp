#include "UniqueC.h"

UniqueC::UniqueC()
{
	mainRegexp = "^(.*\\s)?(\\w[\\w\\d_-]*\\.c)\\s.*$";
}

string UniqueC::GetList()
{
	string input;
	string errorPartString;
	string nullArg;
	string output;
	pcrecpp::RE_Options mainPartternOptions;
	mainPartternOptions.set_caseless(true);
	pcrecpp::RE mainPattern( mainRegexp, mainPartternOptions );
	
	vector<string>array;
	vector<string>::iterator arrayIterator;
	
	output = "";
	
	while ( !cin.eof() )
	{
		input += cin.get();
		if ( input.find("\n") != -1 )
		{
			pcrecpp::StringPiece piece(input);
				
			if ( mainPattern.Consume(&piece, &nullArg, &errorPartString) )
			{
				if ( std::find(array.begin(), array.end(), errorPartString) == array.end() ) 
				{
					array.push_back(errorPartString);
					output += errorPartString + "\n";
				}
			}
			input = "";
			errorPartString = "";
			std::cin.clear();
		}
	}
	
	return output;
}