#include "ui.h"

void help(){
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
		return;
}

void option_menu(std::string method){
    std::cout << "how " << method <<" works" << std::endl;
}

void initialize(std::string method, std::string mode, std::string in_file, std::string parameter, std::string out_file){
    std::string cipher = readfile(in_file);
    std::string plain = caesar(mode, cipher, parameter);
    writefile(plain, out_file);
    return;
}