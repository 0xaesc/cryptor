#include "file.h"
#include "ui.h"
#include "caesar.h"


int main(int argc, char const *argv[]) {

	//input checks

	if(argc>4 || argv[1]=="help"){help();}

	std::string method = std::to_string(*argv[1]);
	std::string mode = std::to_string(*argv[2]);
	std::string parameter = std::to_string(*argv[3]);
	/*
	define defaults
	in_file = ../testfiles/alpha.txt
	outfile = ../testfiles/out.txt
	*/
	std::string in_file = std::to_string(*argv[4]);
	std::string out_file = std::to_string(*argv[5]);
	
	initialize(method, mode, in_file, parameter, out_file);

	return 0;
}
