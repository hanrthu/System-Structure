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
    int TimeLeft;
    int LogicPoiner;
    int ExecTime;
    int Status;
    void issue();
    void exec();
    void update();
    void done();
    void writeback();
};
class lb{
public:
    explicit lb();
    std::string Busy;
    std::string Address;
    int Instr;
    int Allocate;
    int ExecTime;
    int TimeLeft;
    int Status;
    int LogicPointer;
    void issue();
    void exec();
    void update();
    void done();
    void writeback();
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
    int CanIssue;
    int Show;
    std::string filename;
    std::string stofill;
    int IssuePointer;
    int LogicPointer;
    explicit Simulator();
    bool CheckNumber(std::string s);
    bool CheckComplete(rs instr);
    bool CheckLoadComplete(lb instr);
    void Work(std::string file,std::string log,int show);
    void TryIssue(int pointer);
    int FindEarliest(std::vector<int> READY,std::string op);
    void Exec();
    void TryExec();
    int IsVacant(std::string op,int pointer);
    bool FindPlace(int pointer);
    bool NotFull();
    // static bool ACompare(int i,int j);
    // static bool MCompare(int i,int j);
    // static bool LCompare(int i,int j);
    void Tomasolu();
    void Print();
    void PrintLog();
    void Clean(std::string op,int fill);
    double WriteBack();
    void ShowInstrStatus();
};