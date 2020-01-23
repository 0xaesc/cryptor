#ifndef CAESAR
#define CAESAR

#include <fstream>
#include <string>
#include <stdlib.h>

class Caesar{

    private:

        std::ifstream config_file;
        std::ifstream cipher_file;
        std::ofstream out_file;

        std::string cipher;
        std::string alpha;

        void set_cipher();
        void set_alpha();

        int alpha_size = alpha.size();

        int getdif(char first_letter, char last_letter);

    public:

        void initialize();
        std::string encode(int shift);
        std::string decode(int shift);
        std::string match(char first_letter, char last_letter);

        Caesar(std::string config_input, std::string cipher_file_input, std::string out_file_input);
        ~Caesar(void);

};

#endif