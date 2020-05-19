#pragma once
#include <string>
class Instruction{
public:
    std::string Op;
    std::string Dst;
    std::string Src1;
    std::string Src2;
    // 记录指令运行时间
    int ExecTime;
    int TimeLeft;
    int Status;
    int Issue;
    int ExecComp;
    int WriteResult;
    int Count;
    int fill;
    explicit Instruction(std::string instr);
    void issue();
    void exec();
    void update();
    void done();
    void writeback();
    void finish();
};
