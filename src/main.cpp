#include "file.h"
#include "caesar.h"

#include <iostream>
#include <string>
#include "ctype.h"
#include <fstream>
#include <streambuf>

int main(int argc, char const *argv[]) {

	// check parameters

	if (argc > 4) {
		std::cout << "Too many arguments." << std::endl;
	}

	std::string mode = argv[1];

	int shift=99;

	if(mode.compare("-h")==0 || mode.compare("help")==0 || mode.compare("--help")==0){
		std::cout << "This is a basic caesar cipher tool" << '\n';
		std::cout << "it will crate an output file in it's current directory and show the solution in the CLI." << '\n';
		std::cout << "Usage:" << '\n';
		std::cout << "./caesar [mode] [input] [shift]" << '\n';
		std::cout << "[mode]    specifies mode: encrypt, decrypt or match" << '\n';
		std::cout << "[input]   specifies input file" << '\n';
		std::cout << "[match]   specifies either shift or matching letters" << '\n' << '\n';
		std::cout << "Examples:" << '\n';
		std::cout << "./caesar encrypt mytext.txt 5 :: this will encrypt the mytext file by a shift of 5" << '\n';
		std::cout << "./caesar decrypt secret.txt 7 :: this will decrypt the secret file by a shift of 7" << '\n';
		std::cout << "NOTE: encrypt and decrypt only differ in the direction of shift. Thus encrypting by x = decrypting by -x" << '\n';
		std::cout << "./caesar match mystery.txt  Av :: this will output a match to mystery file assuming the shift from A to v" << std::endl;
		exit(0);
	}

	if(mode.compare("match")==0){
		shift=getdif(argv[3]);
	}

	if(mode.compare("encrypt")==0){
		shift = std::stoi(argv[3]);
	}

	if(mode.compare("decrypt")==0){
		shift = std::stoi(argv[3]) * (-1);
	}

	std::string cipher = readfile(argv[2]);

	std::cout << '\n' << "cipher text:" << '\n' << cipher << std::endl;
	std::cout << "shift: " << shift << std::endl;;

	cipher=converse(cipher, shift);

	std::cout << '\n' << "clear text:" << '\n' << cipher << std::endl;

	writefile(cipher, "out.txt");

	return 0;
}
