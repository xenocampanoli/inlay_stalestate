
#include "resin.hpp"
#include "mold.hpp"
#include <sstream>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

void printUsage() {
    std::cout << "USAGE:  ./resinate <boleCfg> <soilCfg>" << std::endl;
}
int main(int argc, char **argv) {
    
    if ( argc != 3 ) {
        printUsage();
        exit(9);
    }
    std::string fn1 = argv[1];
    std::string fn2 = argv[2];
    Resin ro(fn1,fn2);
    ro.DumpBoleSap();
}
