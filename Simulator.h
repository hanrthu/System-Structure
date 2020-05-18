#pragma once
#include<string>
#include<vector>
#include "Instruction.h"
class rs{
public:
    explicit rs();
    std::string Busy;
    std::string Op;
    std::string Vj;
    std::string Vk;
    std::string Qj;
    std::string Qk;
    int Instr;
    int Allocate;
};
class lb{
public:
    explicit lb();
    std::string Busy;
    std::string Address;
    int Instr;
    int Allocate;
};

class RStation{
public:
    rs Ars[6];
    rs Mrs[3];
    void Print();
};
class LoadBuffer{
public:
    lb LB[3];
    void Print();
};

class Register{
public:
    explicit Register();
    std::string R[32]; 
    void Print();
};

class FU{
public:
    explicit FU();
    int ld[2];
    int add[3];
    int mul[2];    
};

class Simulator{
private:
    std::string IS;
    std::string Ready;
    std::string Done;
    std::string WB;
    RStation RS;
    LoadBuffer L;
    Register R;
    std::vector<Instruction> Instructions;
    FU resource;
public:
    int Cycle;
    std::string filename;
    std::string stofill;
    int IssuePointer;
    explicit Simulator();
    bool CheckNumber(std::string s);
    bool CheckComplete(Instruction instr);
    void Work(std::string file,std::string log);
    void TryIssue(int pointer);
    void Exec();
    void TryExec();
    int IsVacant(int pointer);
    bool FindPlace(int pointer);
    bool NotFull();
    void Tomasolu();
    void Print();
    void PrintLog();
    void Clean(std::string op,int fill);
    double WriteBack();
    void ShowInstrStatus();
};