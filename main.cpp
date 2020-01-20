#include "file.h"

#include <iostream>
#include <string>
#include "ctype.h"
#include <fstream>
#include <streambuf>

int getdif(std::string letters){

	char first_letter = letters[0];
	char last_letter = letters[1];

	if (isupper(first_letter)){ first_letter = tolower(first_letter); }
	if (isupper(last_letter)){ last_letter = tolower(last_letter); }

	int dif = (int)first_letter - (int)last_letter;
	if(dif<0){ dif = dif * -1; }

	return dif;
}

char move(int dist, char letter){

	dist = dist % 26;
	bool cap = false;

	if(isupper(letter)){ cap=true; letter = tolower(letter); }

	int num = (int)letter;

	num = num + dist - 71;
	num = num % 26;
	letter = 'a' + num;

	if(cap==true){letter = toupper(letter);}

	return letter;
}

std::string converse(std::string cipher, int shift){
	shift = shift % 26;

	//std::cout << "cipher conversion:" << std::endl;

	for (long unsigned int i = 0; i < cipher.size(); i++) {
		if (isalpha(cipher[i])) {
			//std::cout << cipher[i] << " ·· " << shift << " ··> ";
			cipher[i] = move(shift, cipher[i]);
			//std::cout << cipher[i] << std::endl;
		}
	}

	return cipher;
}

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
