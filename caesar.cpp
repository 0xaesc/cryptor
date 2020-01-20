#include "caesar.h"

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