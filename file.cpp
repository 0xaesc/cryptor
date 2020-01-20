#include "file.h"

std::string readfile(std::string cipher_file){
    std::ifstream infile(cipher_file);
	std::string cipher((std::istreambuf_iterator<char>(infile)),
	std::istreambuf_iterator<char>());

	return cipher;
}

void writefile(std::string plain, std::string plain_file){
    std::ofstream output;
	output.open (plain_file);
	output << plain << std::endl;
	output.close();
}