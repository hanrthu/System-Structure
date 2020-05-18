#include <iostream>
#include <string>
#include <fstream>
#include "Simulator.h"
using namespace std;
int main(int argc,char** argv){ 
    std::string type(argv[1]);
    std::string line(argv[2]);
    Simulator simulator;
    // printf("%s,%s\n",type.c_str(),line.c_str());
    if(type == "basic")
        simulator.Work("./TestCase/" + line + ".basic.nel",line + ".basic.log");
    else if(type == "extend")
        simulator.Work("./TestCase/" + line + ".nel", line + ".log");
}