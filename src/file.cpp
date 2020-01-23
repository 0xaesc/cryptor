#include "file.h"

File::~File(){}



// reading from cipher file

Cipherfile::Cipherfile(std::string location){
    try{
        std::ifstream cipher_file;
        
        if (cipher_file.is_open())
        {
            throw "file already open";
        }else{
            cipher_file.open(location);
        }
        
        if (!cipher_file.good()){
            throw "file not good";
        }else{
            cipher_file >> cipher;
        }
    }

    catch(const std::string error){
        std::cout << "Error while reading cipher file:"  << '\t';
        std::cout << error << std::endl;
        exit(1);
    }
}

Cipherfile::~Cipherfile(){
    if(cipher_file.is_open()){
        cipher_file.close();
    }
}



// writing to output file

void Outfile::write(){
    out_file << text;
}

void Outfile::add(std::string addendum){
    text = text + addendum;
}

void Outfile::overwrite(std::string output){
    text = output;
    write();
}

Outfile::Outfile(std::string location){
    try{
        std::ofstream out_file;
        
        if (out_file.is_open())
        {
            throw "file already open";
        }else{
            // todo:  check if file already exists and set exists
            out_file.open (location);
        }
        
        out_file.close();
    }
    catch(std::string error){
        std::cout << "Error while writing to output file:" << '\t';
        std::cout << error << std::endl;
    }
}

Outfile::~Outfile()
{
}


Configfile::Configfile(/* args */)
{
}

Configfile::~Configfile()
{
}