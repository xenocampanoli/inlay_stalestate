#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

main() {
    std::ifstream t("file.txt");
    std::string str((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());

    std::cout << "Here:  " << str << std::endl;
/*
    */
}
