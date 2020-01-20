#include "caesar.h"

/*
int getdif(char first_letter, char last_letter){
    if (isupper(first_letter)){ first_letter = tolower(first_letter); }
	if (isupper(last_letter)){ last_letter = tolower(last_letter); }

	int differnce = (int)first_letter - (int)last_letter;
	if(differnce<0){ differnce = differnce * -1; }

	return differnce;
}
*/

int getdif(std::string letters){
	
	char first_letter = letters[0];
	char last_letter = letters[1];

	if (isupper(first_letter)){ first_letter = tolower(first_letter); }
	if (isupper(last_letter)){ last_letter = tolower(last_letter); }

	int differnce = (int)first_letter - (int)last_letter;
	if(differnce<0){ differnce = differnce * -1; }

	return differnce;
}

char move(char letter, int distance){
    
	distance = distance % 26;
	bool capital = false;

	if(isupper(letter)){ capital=true; letter = tolower(letter); }

	int num = (int)letter;

	num = num + distance - 71;
	num = num % 26;
	letter = 'a' + num;

	if(capital==true){letter = toupper(letter);}

	return letter;
}

std::string converse(std::string cipher, int shift){
    
	shift = shift % 26;

	for (long unsigned int i = 0; i < cipher.size(); i++) {
		if (isalpha(cipher[i])) {
			cipher[i] = move(cipher[i], shift);
		}
	}

	return cipher;
}