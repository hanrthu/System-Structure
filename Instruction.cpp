#include "Instruction.h"
Instruction::Instruction(std::string instr){
    int begin = 0;
    int end = 0;
    int count = 0;
    for(int i = 0;i < instr.size();i++){
        if(instr[i] == ','){
            end = i;
            // printf("Begin:%d,End:%d\n",begin,end);
            if(count == 0)
                Op = instr.substr(begin,end-begin);
            else if(count == 1)
                Dst = instr.substr(begin,end-begin);
            else if(count == 2)
                Src1 = instr.substr(begin,end-begin);
            else if(count == 3)
                Src2 = instr.substr(begin,end-begin);
            end++;
            begin = end;
            count++;
        }
    }
    if(count == 0)
        Op = instr.substr(begin,instr.size()-begin);
    else if(count == 1)
        Dst = instr.substr(begin,instr.size()-begin);
    else if(count == 2)
        Src1 = instr.substr(begin,instr.size()-begin);
    else if(count == 3)
        Src2 = instr.substr(begin,instr.size()-begin);
    if(Op == "LD")
        ExecTime = 3;
    else if(Op == "JUMP")
        ExecTime = 1;
    else if(Op == "ADD" || Op == "SUB")
        ExecTime = 3;
    else if(Op == "MUL" || Op == "DIV")
        ExecTime = 4;
    Status = 0;
    TimeLeft = ExecTime;
    Issue = -1;
    ExecComp = -1;
    fill = -1;
    Count = 0;
    WriteResult = -1;
    // printf("Instruction is: %s,Op:%s,Dst:%s,Src1:%s,Src2:%s,ExecTime:%d,Status:%d\n",instr.c_str(),Op.c_str(),Dst.c_str(),Src1.c_str(),Src2.c_str(),ExecTime,Status);
}

void Instruction::issue(){
    Status = 1;
    TimeLeft = ExecTime;
}
void Instruction::exec(){
    if(Status == 1)
        Status = 2;
    else
        printf("Cannot Exec Not Issued Instruction!\n");
}
void Instruction::update(){
    if(Status == 2)
        TimeLeft--;
}
void Instruction::done(){
    if(Status == 2)
        Status = 3;
    else
        printf("Cannot Done Not Executing Instruction!\n");
}
void Instruction::writeback(){
    if(Status == 3)
        Status = 4;
    else
        printf("Cannot WriteBack Not Done Instruction!\n");   
}
void Instruction::finish(){
    if(Status == 4)
        Status = 5;
    else
        printf("Cannot Finish Not WriteBack Instruction!\n");
}