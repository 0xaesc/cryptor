#include "file.h"
#include "caesar.h"

#include <iostream>
#include <string>

void help();

void log(std::string message);
void read_log();

void option_menu(std::string method);

void initialize(std::string method, std::string mode, std::string in_file, std::string parameter, std::string out_file);