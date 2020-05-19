#include <iostream>
#include <string>
#include <fstream>
#include "Simulator.h"
// #include <windows.h>
using namespace std;
int main(int argc,char** argv){ 
    std::string type(argv[1]);
    std::string line(argv[2]);
    std::string s(argv[3]);
    int show = stoi(s);
    Simulator simulator;
    // printf("%s,%s\n",type.c_str(),line.c_str());
    // long t1 = GetTickCount();
    if(type == "basic")
        simulator.Work("./TestCase/" + line + ".basic.nel",line + ".basic.log",show);
    else if(type == "extend")
        simulator.Work("./TestCase/" + line + ".nel", line + ".log",show);
    // long t2 = GetTickCount();
    // printf("运行时间：%l\n",t2-t1);
}