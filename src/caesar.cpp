#include "caesar.h"

Caesar::Caesar(std::string config, std::string cipher, std::string out){
	// need to check validity
	// should happen in a seperate class
	config_file.open(config);
	cipher_file.open(cipher);
	out_file.open(out);
	initialize();
}
Caesar::~Caesar(void){
	config_file.close();
	cipher_file.close();
	out_file.close();
}

void Caesar::initialize(){
	// parsing keyword values
	// should happen in a seperate class
}

int Caesar::getdif(char first_letter, char last_letter){
	
	int difference = 0;
	
	for ( int i = 0; i < alpha_size; i++)
	{
		if ( alpha[i] == first_letter ){
			difference += i;
		}
		if ( alpha[i] == last_letter ){
			difference -= i;
		}
	}
	
	return abs(difference);
}

std::string Caesar::encode(int shift){

	std::string beta;
	for (int i = 0; i < alpha_size; i++)
	{
		shift += i;
		shift %= alpha_size;

		beta[i] = alpha[shift];
	}
	
	return beta;
}

std::string Caesar::decode(int shift){

	std::string beta;
	for (int i = 0; i < alpha_size; i++)
	{
		shift = i - shift;
		shift %= alpha_size;

		if (shift<0)
		{
			beta[i] = alpha[alpha_size - shift];	
		} else
		{
			beta[i] = alpha[shift];
		}	
	}

	return beta;	
}

std::string Caesar::match(char first_letter, char last_letter){

	int shift = getdif(first_letter, last_letter);
	std::string text = encode(shift);
	
	return text;
}