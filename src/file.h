#ifndef FILE_HANDLING
#define FILE_HANDLING

#include <iostream>
#include <string>
#include <fstream>

class File{

private:
/*
    virtual bool validate();
    virtual std::string parse(std::string text);
*/
public:

    virtual ~File();
};

class Cipherfile: public File{
        
    private:
        std::string cipher;
        std::ifstream cipher_file;
        
    public:
        Cipherfile(std::string location);
        ~Cipherfile();
};

class Outfile: public File{

    private:
        std::string text;
        std::ofstream out_file;
        void write();

    public:
        void add(std::string addendum);
        void overwrite(std::string output);
        Outfile(std::string location);
        ~Outfile();
};

class Configfile: public File{

    private:
        /* data */
    public:
        Configfile(/* args */);
        ~Configfile();
};


#endif