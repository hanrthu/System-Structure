#include <iostream>
#include <string>
#include <fstream>
#include "Simulator.h"
// #include <windows.h>
#include <time.h>
using namespace std;
int main(int argc,char** argv){ 
    std::string type(argv[1]);
    std::string line(argv[2]);
    std::string s(argv[3]);
    int show = stoi(s);
    Simulator simulator;
    // printf("%s,%s\n",type.c_str(),line.c_str());
    // long t1 = GetTickCount();
    clock_t start = clock();
    if(type == "basic")
        simulator.Work("./TestCase/" + line + ".basic.nel",line + ".basic.log",show);
    else if(type == "extend")
        simulator.Work("./TestCase/" + line + ".nel", line + ".log",show);
    clock_t end = clock();
    cout <<"Running Time : "<<(double)(end - start)/ CLOCKS_PER_SEC << endl;
    // long t2 = GetTickCount();
    // printf("运行时间：%l\n",t2-t1);
}
