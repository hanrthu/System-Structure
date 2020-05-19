#include "Simulator.h"
#include "Instruction.h"
#include<algorithm>
#include <fstream>
#include <vector>
rs::rs(){
    Busy = "No";
    Op = "";
    Vj = "";
    Vk = "";
    Qj = "";
    Qk = "";
    Instr = -1;
    Allocate = -1;
    Status = 0;
    TimeLeft = 0;
}
void rs::issue(){
    Status = 1;
    TimeLeft = ExecTime;
}
void rs::exec(){
    if(Status == 1)
        Status = 2;
    else
        printf("Cannot Exec Not Issued Instruction!\n");
}
void rs::update(){
    if(Status == 2)
        TimeLeft--;
}
void rs::done(){
    if(Status == 2)
        Status = 3;
    else
        printf("Cannot Done Not Executing Instruction!\n");
}
void rs::writeback(){
    if(Status == 3)
        Status = 4;
    else
        printf("Cannot WriteBack Not Done Instruction!\n");   
}
void RStation::Print(){
    printf("Reserved Station Status\n");
    printf("    \tBusy\tOp\tVj\tVk\tQj\tQk\n");
    printf("Ars1\t%s\t%s\t%s\t%s\t%s\t%s\n",Ars[0].Busy.c_str(),Ars[0].Op.c_str(),Ars[0].Vj.substr(0,5).c_str(),Ars[0].Vk.substr(0,5).c_str(),Ars[0].Qj.c_str(),Ars[0].Qk.c_str());
    printf("Ars2\t%s\t%s\t%s\t%s\t%s\t%s\n",Ars[1].Busy.c_str(),Ars[1].Op.c_str(),Ars[1].Vj.substr(0,5).c_str(),Ars[1].Vk.substr(0,5).c_str(),Ars[1].Qj.c_str(),Ars[1].Qk.c_str());
    printf("Ars3\t%s\t%s\t%s\t%s\t%s\t%s\n",Ars[2].Busy.c_str(),Ars[2].Op.c_str(),Ars[2].Vj.substr(0,5).c_str(),Ars[2].Vk.substr(0,5).c_str(),Ars[2].Qj.c_str(),Ars[2].Qk.c_str());
    printf("Ars4\t%s\t%s\t%s\t%s\t%s\t%s\n",Ars[3].Busy.c_str(),Ars[3].Op.c_str(),Ars[3].Vj.substr(0,5).c_str(),Ars[3].Vk.substr(0,5).c_str(),Ars[3].Qj.c_str(),Ars[3].Qk.c_str());
    printf("Ars5\t%s\t%s\t%s\t%s\t%s\t%s\n",Ars[4].Busy.c_str(),Ars[4].Op.c_str(),Ars[4].Vj.substr(0,5).c_str(),Ars[4].Vk.substr(0,5).c_str(),Ars[4].Qj.c_str(),Ars[4].Qk.c_str());
    printf("Ars6\t%s\t%s\t%s\t%s\t%s\t%s\n",Ars[5].Busy.c_str(),Ars[5].Op.c_str(),Ars[5].Vj.substr(0,5).c_str(),Ars[5].Vk.substr(0,5).c_str(),Ars[5].Qj.c_str(),Ars[5].Qk.c_str());
    printf("Mrs1\t%s\t%s\t%s\t%s\t%s\t%s\n",Mrs[0].Busy.c_str(),Mrs[0].Op.c_str(),Mrs[0].Vj.substr(0,5).c_str(),Mrs[0].Vk.substr(0,5).c_str(),Mrs[0].Qj.c_str(),Mrs[0].Qk.c_str());
    printf("Mrs2\t%s\t%s\t%s\t%s\t%s\t%s\n",Mrs[1].Busy.c_str(),Mrs[1].Op.c_str(),Mrs[1].Vj.substr(0,5).c_str(),Mrs[1].Vk.substr(0,5).c_str(),Mrs[1].Qj.c_str(),Mrs[1].Qk.c_str());
    printf("Mrs3\t%s\t%s\t%s\t%s\t%s\t%s\n",Mrs[2].Busy.c_str(),Mrs[2].Op.c_str(),Mrs[2].Vj.substr(0,5).c_str(),Mrs[2].Vk.substr(0,5).c_str(),Mrs[2].Qj.c_str(),Mrs[2].Qk.c_str());
    printf("\n");
}
void LoadBuffer::Print(){
    printf("Load Buffer Status\n");
    printf("    \tBusy\tAddress\n");
    printf("LB1 \t%s\t%s\n",LB[0].Busy.c_str(),LB[0].Address.c_str());
    printf("LB2 \t%s\t%s\n",LB[1].Busy.c_str(),LB[1].Address.c_str());
    printf("LB3 \t%s\t%s\n",LB[2].Busy.c_str(),LB[2].Address.c_str());
    printf("\n");
}
void Register::Print(){
    printf("Register status\n");
    printf("    \tR0   \tR1   \tR2   \tR3   \tR4   \tR5   \tR6   \tR7\n");
    printf("State\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",R[0].substr(0,5).c_str(),R[1].substr(0,5).c_str(),R[2].substr(0,5).c_str(),R[3].substr(0,5).c_str(),R[4].substr(0,5).c_str(),R[5].substr(0,5).c_str(),R[6].substr(0,5).c_str(),R[7].substr(0,5).c_str());
    printf("    \tR8   \tR9   \tR10  \tR11  \tR12  \tR13  \tR14  \tR15\n");
    printf("State\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",R[8].substr(0,5).c_str(),R[9].substr(0,5).c_str(),R[10].substr(0,5).c_str(),R[11].substr(0,5).c_str(),R[12].substr(0,5).c_str(),R[13].substr(0,5).c_str(),R[14].substr(0,5).c_str(),R[15].substr(0,5).c_str());
    printf("    \tR16  \tR17  \tR18  \tR19  \tR20  \tR21  \tR22  \tR23\n");
    printf("State\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",R[16].substr(0,5).c_str(),R[17].substr(0,5).c_str(),R[18].substr(0,5).c_str(),R[19].substr(0,5).c_str(),R[20].substr(0,5).c_str(),R[21].substr(0,5).c_str(),R[22].substr(0,5).c_str(),R[23].substr(0,5).c_str());
    printf("    \tR24  \tR25  \tR26  \tR27  \tR28  \tR29  \tR30  \tR31\n");
    printf("State\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",R[24].substr(0,5).c_str(),R[25].substr(0,5).c_str(),R[26].substr(0,5).c_str(),R[27].substr(0,5).c_str(),R[28].substr(0,5).c_str(),R[29].substr(0,5).c_str(),R[30].substr(0,5).c_str(),R[31].substr(0,5).c_str());
    printf("\n");
}
Register::Register(){
    for(int i = 0; i < 32; i++){
        R[i] = "0";
    }
}
lb::lb(){
    Busy = "No";
    Address = "";
    Instr = -1;
    Allocate = -1;
    Status = 0;
    TimeLeft = 0;
}
void lb::issue(){
    Status = 1;
    TimeLeft = ExecTime;
}
void lb::exec(){
    if(Status == 1)
        Status = 2;
    else
        printf("Cannot Exec Not Issued Instruction!\n");
}
void lb::update(){
    if(Status == 2)
        TimeLeft--;
}
void lb::done(){
    if(Status == 2)
        Status = 3;
    else
        printf("Cannot Done Not Executing Instruction!\n");
}
void lb::writeback(){
    if(Status == 3)
        Status = 4;
    else
        printf("Cannot WriteBack Not Done Instruction!\n");   
}
FU::FU(){
    ld[0] = 0;
    ld[1] = 0;
    add[0] = 0;
    add[1] = 0;
    add[2] = 0;
    mul[0] = 0;
    mul[1] = 0;
}
int Simulator::IsVacant(std::string op,int pointer){
    int n;
    if(op == "ADD" || op == "SUB" || op == "JUMP")
        n= RS.Ars[pointer].Instr;
    else if(op == "MUL" || op == "DIV")
        n = RS.Mrs[pointer].Instr;
    else if(op == "LD")
        n = L.LB[pointer].Instr;
    // std::string op = Instructions[n].Op;
    if(op == "ADD" || op == "SUB" || op == "JUMP"){
        for(int i = 0;i < 3;i++){
            if(resource.add[i] == 0){
                resource.add[i] = 1;
                RS.Ars[Instructions[n].fill].Allocate = i;
                return i;
            }
        }
    }else if(op == "MUL" || op == "DIV"){
        // printf("Resource:%d %d\n",resource.mul[0],resource.mul[1]);
        for(int i = 0;i < 2;i++){
            if(resource.mul[i] == 0){
                resource.mul[i] = 1;
                RS.Mrs[Instructions[n].fill].Allocate = i;
                return i;
            }
        }
    }else if(op == "LD"){
        for(int i = 0;i < 2;i++){
            if(resource.ld[i] == 0){
                L.LB[Instructions[n].fill].Allocate = i;
                resource.ld[i] = 1;
                return i;
            }
        }
    }
    // printf("HAHAHA\n");
    return -1;
}
Simulator::Simulator(){
    IssuePointer = 0;
    LogicPointer = 0;
    CanIssue = 1;
    Cycle = 1;
}

bool Simulator::CheckNumber(std::string s){
    int size = s.size();
    bool isNumber = true;
    for(int i = 0;i< size;i++){
        if((s[i]<'0'||s[i] > '9') && s[i] != '.' && s[i] != '-')
            isNumber = false;
    }
    if(size >= 2){
        if(s[0] == '0' && s[1] == 'x')
            isNumber = true;
    }
    return isNumber;
}
bool Simulator::FindPlace(int pointer){
    int fill = -1;
    if(pointer == -1)
        return false;
    std::string op = Instructions[pointer].Op;
    if(op == "ADD" || op == "SUB"||op == "JUMP"){
        for(int i = 0;i < 6;i++){
            if(RS.Ars[i].Busy == "No"){
                fill = i;
                RS.Ars[i].Instr = pointer;
                break;
            }
        }
        if(fill == -1)
            return false;
        else{
            Instructions[pointer].fill = fill;
            stofill = "Ars" + std::to_string(fill + 1);
            RS.Ars[fill].Busy = "Yes";
            RS.Ars[fill].Op = op;
            RS.Ars[fill].LogicPoiner = LogicPointer;
            if(op == "ADD" || op == "SUB")
                RS.Ars[fill].ExecTime = 3;
            else if(op == "JUMP")
                RS.Ars[fill].ExecTime = 1;
            //填写第一个源
            if(Instructions[pointer].Src1[0] != 'R'){
                RS.Ars[fill].Vj = Instructions[pointer].Src1;
            }else if(CheckNumber(R.R[std::stoi(Instructions[pointer].Src1.substr(1))]) == true){
                RS.Ars[fill].Vj = R.R[std::stoi(Instructions[pointer].Src1.substr(1))];
            }else{
                RS.Ars[fill].Qj = R.R[std::stoi(Instructions[pointer].Src1.substr(1))];
            }
            //填写第二个源
            if(Instructions[pointer].Src2[0] != 'R'){
                RS.Ars[fill].Vk = Instructions[pointer].Src2;
            }else if(CheckNumber(R.R[std::stoi(Instructions[pointer].Src2.substr(1))])==true){
                RS.Ars[fill].Vk = R.R[std::stoi(Instructions[pointer].Src2.substr(1))];
            }else{
                RS.Ars[fill].Qk = R.R[std::stoi(Instructions[pointer].Src2.substr(1))];
            }
        }
    }else if(op == "MUL" || op == "DIV"){
        for(int i = 0;i < 3;i++){
            if(RS.Mrs[i].Busy == "No"){
                fill = i;
                RS.Mrs[i].Instr = pointer;
                break;
            }
        }
        if(fill == -1)
            return false;
        else{

            Instructions[pointer].fill = fill;
            stofill = "Mrs" + std::to_string(fill + 1);
            RS.Mrs[fill].Busy = "Yes";
            RS.Mrs[fill].Op = op;
            RS.Mrs[fill].LogicPoiner = LogicPointer;
            RS.Mrs[fill].ExecTime = 4;
            // printf("%s\n",Instructions[pointer].Src1.substr(1).c_str());
            if(Instructions[pointer].Src1[0] != 'R'){
                RS.Mrs[fill].Vj = Instructions[pointer].Src1;
            }else if(CheckNumber(R.R[std::stoi(Instructions[pointer].Src1.substr(1))])==true){
                RS.Mrs[fill].Vj = R.R[std::stoi(Instructions[pointer].Src1.substr(1))];
            }else{
                RS.Mrs[fill].Qj = R.R[std::stoi(Instructions[pointer].Src1.substr(1))];
            }

            if(Instructions[pointer].Src2[0] != 'R'){
                RS.Mrs[fill].Vk = Instructions[pointer].Src2;
            }else if(CheckNumber(R.R[std::stoi(Instructions[pointer].Src2.substr(1))])==true){
                RS.Mrs[fill].Vk = R.R[std::stoi(Instructions[pointer].Src2.substr(1))];
            }else{
                RS.Mrs[fill].Qk = R.R[std::stoi(Instructions[pointer].Src2.substr(1))];
            }
        }
    }else if(op == "LD"){
        for(int i = 0;i < 3;i++){
            if(L.LB[i].Busy == "No"){
                fill = i;
                L.LB[i].Instr = pointer;
                break;
            }
        }
        if(fill == -1)
            return false;
        else{
            Instructions[pointer].fill = fill;
            stofill = "Load" + std::to_string(fill + 1);
            L.LB[fill].Busy = "Yes";
            L.LB[fill].LogicPointer = LogicPointer;
            L.LB[fill].ExecTime = 3;
            // printf("%s\n",Instructions[pointer].Src1.c_str());
            L.LB[fill].Address = std::to_string(int(stol(Instructions[pointer].Src1,NULL,16)));
        }
    }

    return true;
}

bool Simulator::NotFull(){
    for(int i = Instructions.size() - 1; i > 0;i--){
        if(Instructions[i].Issue == -1)
            return true;
        if(Instructions[i].ExecComp == -1)
            return true;
        if(Instructions[i].WriteResult == -1)
            return true;
    }
    return false;
}


void Simulator::TryIssue(int pointer){
    if(CanIssue == 1){
        std::string op = Instructions[pointer].Op;
        if(FindPlace(pointer)){
            Instructions[pointer].Count++;
            IssuePointer++;
            LogicPointer++;
            IS = Instructions[pointer].Op + ',' + Instructions[pointer].Dst + ',' + Instructions[pointer].Src1;
            if(Instructions[pointer].Op!="LD")
                IS += ',' + Instructions[pointer].Src2;
            if(IssuePointer >= Instructions.size())
                CanIssue = 0;
            if(Instructions[pointer].Op == "ADD" || Instructions[pointer].Op == "SUB" || Instructions[pointer].Op == "JUMP")
                RS.Ars[Instructions[pointer].fill].issue();
            else if(Instructions[pointer].Op == "MUL" || Instructions[pointer].Op == "DIV")
                RS.Mrs[Instructions[pointer].fill].issue();
            else if(Instructions[pointer].Op == "LD")
                L.LB[Instructions[pointer].fill].issue();
            if( Instructions[pointer].Count == 1)
                Instructions[pointer].Issue = Cycle;
            if(Instructions[pointer].Op != "JUMP")
                R.R[std::stoi(Instructions[pointer].Dst.substr(1))] = stofill;
            if(Instructions[pointer].Op == "JUMP")
                CanIssue = 0;
        }else{
            IS = "";
        }
    }else{
        IS = "";
    }
}
bool Simulator::CheckComplete(rs instr){
    if(instr.Status == 3)
        return true;
    else 
        return false;
}
bool Simulator::CheckLoadComplete(lb instr){
    if(instr.Status == 3)
        return true;
    else
        return false;
}
void Simulator::Clean(std::string op,int fill){
    if(op == "ADD" || op == "SUB"|| op == "JUMP"){
        RS.Ars[fill].Busy = "No";
        RS.Ars[fill].Op = "";
        RS.Ars[fill].Vj = "";
        RS.Ars[fill].Vk = "";
        RS.Ars[fill].Qj = "";
        RS.Ars[fill].Qk = "";
        resource.add[RS.Ars[fill].Allocate] = 0;
        RS.Ars[fill].Instr = -1;
        RS.Ars[fill].Allocate = -1;
        if(op == "JUMP"){
            CanIssue = 1;
        }
    }else if(op == "MUL" || op == "DIV"){
        RS.Mrs[fill].Busy = "No";
        RS.Mrs[fill].Op = "";
        RS.Mrs[fill].Vj = "";
        RS.Mrs[fill].Vk = "";
        RS.Mrs[fill].Qj = "";
        RS.Mrs[fill].Qk = "";
        resource.mul[RS.Mrs[fill].Allocate] = 0;
        RS.Mrs[fill].Instr = -1;
        RS.Mrs[fill].Allocate = -1;
    }else if(op == "LD"){
        L.LB[fill].Busy = "No";
        L.LB[fill].Address = "";
        resource.ld[L.LB[fill].Allocate] = 0;
        L.LB[fill].Instr = -1;
        L.LB[fill].Allocate = -1;
    }
}
double Simulator::WriteBack(){
    WB = "";
    std::string name;
    std::string result;
    for(int j = 0;j < 6;j++){
        int i = RS.Ars[j].Instr;
        if(i >= 0 && CheckComplete(RS.Ars[j])){
            if(Instructions[i].Op == "ADD" ||Instructions[i].Op == "SUB"||Instructions[i].Op == "JUMP"){
                name = "Ars" + std::to_string(j + 1);
            }else if(Instructions[i].Op == "MUL" || Instructions[i].Op == "DIV"){
                name = "Mrs" + std::to_string(j + 1);
            }else if(Instructions[i].Op == "LD"){
                name = "Load" + std::to_string(j + 1);
            }
            if(Instructions[i].Op == "ADD"){
                int s = std::stoi(RS.Ars[j].Vj) + std::stoi(RS.Ars[j].Vk);
                result = std::to_string(s);
                if(R.R[std::stoi(Instructions[i].Dst.substr(1))] == name)
                    R.R[std::stoi(Instructions[i].Dst.substr(1))] = result;
            }
            else if(Instructions[i].Op == "SUB"){
                int s = std::stoi(RS.Ars[j].Vj) - std::stoi(RS.Ars[j].Vk);
                result = std::to_string(s);
                if(R.R[std::stoi(Instructions[i].Dst.substr(1))] == name)
                    R.R[std::stoi(Instructions[i].Dst.substr(1))] = result;
            }else if(Instructions[i].Op == "JUMP"){
                // printf("I am Jumping!\n");
                // printf("IssuePointer:%d\n",IssuePointer);
                if(int(std::stol(Instructions[i].Dst,NULL,16)) == int(std::stol(RS.Ars[j].Vj))){
                    result = std::to_string((std::stol(RS.Ars[j].Vk,NULL,16)));
                    IssuePointer += ( -1 + int(std::stol(RS.Ars[j].Vk,NULL,16)));
                    // printf("IssuePointer:%d %d\n",IssuePointer,int(std::stol(RS.Ars[j].Vk,NULL,16)));
                }
            }else if(Instructions[i].Op == "MUL"){
                int s = std::stoi(RS.Mrs[j].Vj) * std::stoi(RS.Mrs[j].Vk);
                result = std::to_string(s);
                if(R.R[std::stoi(Instructions[i].Dst.substr(1))] == name)
                    R.R[std::stoi(Instructions[i].Dst.substr(1))] = result;
            }else if(Instructions[i].Op == "DIV"){
                int s;
                if(std::stoi(RS.Mrs[j].Vk) == 0)
                    s = std::stoi(RS.Mrs[j].Vj);
                else
                    s = std::stoi(RS.Mrs[j].Vj) / std::stoi(RS.Mrs[j].Vk);
                result = std::to_string(s);
                if(R.R[std::stoi(Instructions[i].Dst.substr(1))] == name)
                    R.R[std::stoi(Instructions[i].Dst.substr(1))] = result;

            }else if(Instructions[i].Op == "LD"){
                if(R.R[std::stoi(Instructions[i].Dst.substr(1))] == name){
                    R.R[std::stoi(Instructions[i].Dst.substr(1))] = L.LB[j].Address;
                }
                result = L.LB[j].Address;
            }else{
                printf("Unknown Operation!\n");
            }
            RS.Ars[j].writeback();
            if(Instructions[i].Count == 1)
                Instructions[i].WriteResult = Cycle;
            for(int k = 0;k < 6;k++){
                if(RS.Ars[k].Qj == name){
                    RS.Ars[k].Qj = "";
                    RS.Ars[k].Vj = result;
                }
                if(RS.Ars[k].Qk == name){
                    RS.Ars[k].Qk = "";
                    RS.Ars[k].Vk = result;
                }
            }
            for(int k = 0;k < 3; k++){
                if(RS.Mrs[k].Qj == name){
                    RS.Mrs[k].Qj = "";
                    RS.Mrs[k].Vj = result;
                }
                if(RS.Mrs[k].Qk == name){
                    RS.Mrs[k].Qk = "";
                    RS.Mrs[k].Vk = result;
                }
            }
            if(WB.size() > 0)
                WB += ";";
            WB += Instructions[i].Op + "," + Instructions[i].Dst + "," + Instructions[i].Src1;
            if(Instructions[i].Op != "LD"){
                WB += "," + Instructions[i].Src2;
            }
            Clean(Instructions[i].Op,j);
        }
    }
    for(int j = 0; j < 3; j++ ){
        int i = RS.Mrs[j].Instr;
        name = "Mrs" + std::to_string(j + 1);
        if(i >= 0 && CheckComplete(RS.Mrs[j])){
            if(Instructions[i].Op == "MUL"){
                int s = std::stoi(RS.Mrs[j].Vj) * std::stoi(RS.Mrs[j].Vk);
                result = std::to_string(s);
                if(R.R[std::stoi(Instructions[i].Dst.substr(1))] == name)
                    R.R[std::stoi(Instructions[i].Dst.substr(1))] = result;
            }else if(Instructions[i].Op == "DIV"){
                int s;
                if(std::stoi(RS.Mrs[j].Vk) == 0)
                    s = std::stoi(RS.Mrs[j].Vj);
                else
                    s = std::stoi(RS.Mrs[j].Vj) / std::stoi(RS.Mrs[j].Vk);
                result = std::to_string(s);
                if(R.R[std::stoi(Instructions[i].Dst.substr(1))] == name)
                    R.R[std::stoi(Instructions[i].Dst.substr(1))] = result;
            }
            RS.Mrs[j].writeback();
            if(Instructions[i].Count == 1)
                Instructions[i].WriteResult = Cycle;
            for(int k = 0;k < 6;k++){
                if(RS.Ars[k].Qj == name){
                    RS.Ars[k].Qj = "";
                    RS.Ars[k].Vj = result;
                }
                if(RS.Ars[k].Qk == name){
                    RS.Ars[k].Qk = "";
                    RS.Ars[k].Vk = result;
                }
            }
            for(int k = 0;k < 3; k++){
                if(RS.Mrs[k].Qj == name){
                    RS.Mrs[k].Qj = "";
                    RS.Mrs[k].Vj = result;
                }
                if(RS.Mrs[k].Qk == name){
                    RS.Mrs[k].Qk = "";
                    RS.Mrs[k].Vk = result;
                }
            }
            if(WB.size() > 0)
                WB += ";";
            WB += Instructions[i].Op + "," + Instructions[i].Dst + "," + Instructions[i].Src1;
            if(Instructions[i].Op != "LD"){
                WB += "," + Instructions[i].Src2;
            }
            Clean(Instructions[i].Op,j);
        }
    }
    for(int j = 0; j < 3; j++ ){
        int i = L.LB[j].Instr;
        name = "Load" + std::to_string(j + 1);
        if(i >= 0 && CheckLoadComplete(L.LB[j])){
            if(R.R[std::stoi(Instructions[i].Dst.substr(1))] == name){
                R.R[std::stoi(Instructions[i].Dst.substr(1))] = L.LB[j].Address;
            }
            result = L.LB[j].Address;
            L.LB[j].writeback();
            if(Instructions[i].Count == 1)
                Instructions[i].WriteResult = Cycle;
            // printf("Hello World!\n");
            for(int k = 0;k < 6;k++){
                if(RS.Ars[k].Qj == name){
                    RS.Ars[k].Qj = "";
                    RS.Ars[k].Vj = result;
                }
                if(RS.Ars[k].Qk == name){
                    RS.Ars[k].Qk = "";
                    RS.Ars[k].Vk = result;
                }
            }
            for(int k = 0;k < 3; k++){
                if(RS.Mrs[k].Qj == name){
                    RS.Mrs[k].Qj = "";
                    RS.Mrs[k].Vj = result;
                }
                if(RS.Mrs[k].Qk == name){
                    RS.Mrs[k].Qk = "";
                    RS.Mrs[k].Vk = result;
                }
            }
            if(WB.size() > 0)
                WB += ";";
            WB += Instructions[i].Op + "," + Instructions[i].Dst + "," + Instructions[i].Src1;
            if(Instructions[i].Op != "LD"){
                WB += "," + Instructions[i].Src2;
            }
            Clean(Instructions[i].Op,j);
        }
    }
    return 1.0;
}
// bool Simulator::ACompare(int a,int b){
//     return RS.Ars[a].LogicPoiner < RS.Ars[b].LogicPoiner;
// }
// bool Simulator::MCompare(int a,int b){
//     return RS.Mrs[a].LogicPoiner < RS.Mrs[b].LogicPoiner;
// }
// bool Simulator::LCompare(int a,int b){
//      return L.LB[a].LogicPointer < L.LB[b].LogicPointer;
// }
int Simulator::FindEarliest(std::vector<int> READY,std::string op){
    int min = 100000000;
    int index = -1;
    for(int i = 0; i < READY.size();i++){
        if(READY[i] != -1){
            if(op == "ADD"){
                if(RS.Ars[READY[i]].LogicPoiner < min){
                    min = RS.Ars[READY[i]].LogicPoiner;
                    index = i;
                }
            }else if(op == "MUL"){
                if(RS.Mrs[READY[i]].LogicPoiner < min){
                    min = RS.Mrs[READY[i]].LogicPoiner;
                    index = i;
                }
            }else if(op == "LD"){
                if(L.LB[READY[i]].LogicPointer < min){
                    min = L.LB[READY[i]].LogicPointer;
                    index = i;
                }
            }
        }
    }
    return index;
}
void Simulator::TryExec(){
    std::vector<int> ADDReady;
    std::vector<int> MULReady;
    std::vector<int> LDReady;
    Ready = "";
    // for(int i = 0;i < Instructions.size();i++){
    //     if(Instructions[i].Op == "ADD" ||Instructions[i].Op == "SUB"){
    //         if(RS.Ars[Instructions[i].fill].Vj != "" && RS.Ars[Instructions[i].fill].Vk != "" && Instructions[i].Status == 1)
    //             ADDReady.push_back(i);
    //     }else if(Instructions[i].Op == "MUL" ||Instructions[i].Op == "DIV"){
    //         if(RS.Mrs[Instructions[i].fill].Vj != "" && RS.Mrs[Instructions[i].fill].Vk != "" && Instructions[i].Status == 1)
    //             MULReady.push_back(i);
    //     }else if(Instructions[i].Op == "LD"){
    //         if(Instructions[i].Issue != -1 && Instructions[i].Status == 1){
    //             LDReady.push_back(i);
    //         }
    //     }
    // }
    for(int j = 0; j < 6;j++){
        int i = RS.Ars[j].Instr;
        // printf("Ars I is :%d\n",i);
        int contain = 0;
        if(i >= 0 && RS.Ars[j].Vj != "" && RS.Ars[j].Vk !="" && RS.Ars[j].Status == 1){
            for(int k = 0; k < ADDReady.size();k++)
                if(ADDReady[k] == j)
                    contain = 1;
            if(contain == 0)
                ADDReady.push_back(j);
        }
    }
    for(int j = 0; j < 3;j++){
        int i = RS.Mrs[j].Instr;
        int contain = 0;
        // printf("Mrs I is :%d\n",i);
        if(i >= 0 && RS.Mrs[j].Vj != "" && RS.Mrs[j].Vk !="" && RS.Mrs[j].Status == 1){
            for(int k = 0; k < MULReady.size();k++)
                if(MULReady[k] == j)
                    contain = 1;
            if(contain == 0)
                MULReady.push_back(j);
        }
    }
    for(int j = 0; j < 3;j++){
        int i = L.LB[j].Instr;
        int contain = 0;
        // printf("LD I is :%d\n",i);
        if(i >= 0 && L.LB[j].Status == 1){
            for(int k = 0; k < LDReady.size();k++)
                if(LDReady[k] == j)
                    contain = 1;
            if(contain == 0)
                LDReady.push_back(j);
        }
    }
    std::sort(ADDReady.begin(), ADDReady.end());
    std::sort(MULReady.begin(),MULReady.end());
    std::sort(LDReady.begin(),LDReady.end());
    for(int i = 0; i < ADDReady.size();i++){
        int earliest = FindEarliest(ADDReady,"ADD");
        if(IsVacant(RS.Ars[ADDReady[earliest]].Op,ADDReady[earliest])!= -1){
            RS.Ars[ADDReady[earliest]].exec();
            if(Ready.size() > 0)
                Ready += ";";
            int n = RS.Ars[ADDReady[earliest]].Instr;
            Ready += Instructions[n].Op + "," + Instructions[n].Dst + "," + Instructions[n].Src1 + "," + Instructions[n].Src2;
        }
        ADDReady[earliest] = -1;
    }
    for(int j = 0; j < MULReady.size();j++){
        // printf("MULREADY:%d\n",MULReady.size());
        int earliest = FindEarliest(MULReady,"MUL");
        if(IsVacant(RS.Mrs[MULReady[earliest]].Op,MULReady[earliest]) != -1){
            RS.Mrs[MULReady[earliest]].exec();
            if(Ready.size() > 0)
                Ready += ";";
            int n = RS.Mrs[MULReady[earliest]].Instr;
            Ready += Instructions[n].Op + "," + Instructions[n].Dst + "," + Instructions[n].Src1 + "," + Instructions[n].Src2;
        }
        MULReady[earliest] = -1;
    }
    for(int k = 0; k < LDReady.size();k++){
        int earliest = FindEarliest(LDReady,"LD");
        if(IsVacant("LD",LDReady[earliest]) != -1){
            L.LB[LDReady[earliest]].exec();
            // Instructions[LDReady[k]].exec();
            if(Ready.size() > 0)
                Ready += ";";
            int n = L.LB[LDReady[earliest]].Instr;
            Ready += Instructions[n].Op + "," + Instructions[n].Dst + "," + Instructions[n].Src1;
        }
        LDReady[earliest] = -1;
    }
}
void Simulator::Exec(){
    Done = "";
    for(int j = 0; j < 6;j++){
        int i = RS.Ars[j].Instr;
        RS.Ars[j].update();
        if(i >= 0 && RS.Ars[j].TimeLeft == 0 && RS.Ars[j].Status == 2){
            if(Instructions[i].Count == 1)
                Instructions[i].ExecComp = Cycle;
            RS.Ars[j].done();
            if(Done.size() > 0)
                Done += ";";
            Done += Instructions[i].Op + "," + Instructions[i].Dst + "," + Instructions[i].Src1;
            if(Instructions[i].Op != "LD"){
                Done += "," + Instructions[i].Src2;
            }
        }
    }
    for(int j = 0; j < 3;j++){
        int i = RS.Mrs[j].Instr;
        RS.Mrs[j].update();
        if(i >= 0 && RS.Mrs[j].Status == 2 && RS.Mrs[j].Op == "DIV"&& std::stoi(RS.Mrs[j].Vk) == 0)
            RS.Mrs[j].TimeLeft = 0;
        if(i >= 0 && RS.Mrs[j].TimeLeft == 0 && RS.Mrs[j].Status == 2){
            if(Instructions[i].Count == 1)
                Instructions[i].ExecComp = Cycle;
            RS.Mrs[j].done();
            if(Done.size() > 0)
                Done += ";";
            Done += Instructions[i].Op + "," + Instructions[i].Dst + "," + Instructions[i].Src1;
            if(Instructions[i].Op != "LD"){
                Done += "," + Instructions[i].Src2;
            }
        }
    }
    for(int j = 0; j < 3;j++){
        int i = L.LB[j].Instr;
        L.LB[j].update();
        if(i >=0 && L.LB[j].TimeLeft == 0 && L.LB[j].Status == 2){
            if(Instructions[i].Count == 1)
                Instructions[i].ExecComp = Cycle;
            L.LB[j].done();
            if(Done.size() > 0)
                Done += ";";
            Done += Instructions[i].Op + "," + Instructions[i].Dst + "," + Instructions[i].Src1;
            if(Instructions[i].Op != "LD"){
                Done += "," + Instructions[i].Src2;
            }
        }
    }
}

void Simulator::Tomasolu(){
    while(NotFull()){
        WriteBack();
        if(!NotFull()){
            if(Show == 1)
                Print();
            break;
        }
        TryIssue(IssuePointer);
        Exec();
        TryExec();
        if(Show == 1)
            Print();
        Cycle += 1;
    }
    // for(int i = 0; i < 70; i ++){
    //     WriteBack();
    //     TryIssue(IssuePointer);
    //     Exec();
    //     TryExec();
    //     Print();
    //     Cycle += 1;
    // }
}
void Simulator::Work(std::string file,std::string log,int show){
    filename = log;
    std::string line;
    int count = 0;
    std::ifstream in(file);
    while(getline(in,line)){
        Instruction I(line);
        Instructions.push_back(I);
        count += 1;
    }
    Show = show;
    Tomasolu();
    PrintLog();
    Cycle += 1;
}
void Simulator::ShowInstrStatus(){
    printf("Instruction\tdst\tj\tk\tIssue\tExec Comp\tWrite Result\n");
    for(int i = 0; i < Instructions.size();i++){
        printf("%s\t\t%s\t%s\t%s\t%d\t%d\t\t%d\n",Instructions[i].Op.c_str(),Instructions[i].Dst.c_str(),Instructions[i].Src1.c_str(),Instructions[i].Src2.c_str(),Instructions[i].Issue,Instructions[i].ExecComp,Instructions[i].WriteResult);
    }
    // for(int i = 0; i < 6;i++)
    //     printf("%d  %d %d\n",RS.Ars[i].TimeLeft,RS.Ars[i].Status,Instructions[i].Count);
    // for(int j = 0; j < 3;j++)
    //     printf("%d  %d %d\n",RS.Mrs[j].TimeLeft,RS.Mrs[j].Status,Instructions[j].Count);
    printf("\n");

}
void Simulator::Print(){
    printf("Cycle %d\n",Cycle);
    printf("本周期发射的指令:%s\n",IS.c_str());
    printf("本周期就绪的指令:%s\n",Ready.c_str());
    printf("本周期执行结束的指令:%s\n",Done.c_str());
    printf("本周期写回结果的指令:%s\n\n",WB.c_str());
    ShowInstrStatus();
    RS.Print();
    L.Print();
    R.Print();
}
void Simulator::PrintLog(){
    std::ofstream out("./Log/2016010189_" +  filename);
    for(int i = 0; i < Instructions.size();i++){
        out << Instructions[i].Issue << " " << Instructions[i].ExecComp << " " << Instructions[i].WriteResult << std::endl;
    }
}