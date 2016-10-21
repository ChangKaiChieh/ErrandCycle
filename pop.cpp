#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<string>
#define CMT //
using namespace std;
queue<string> Q1,Q2,Q3;
void read();
void write();
void pop();
int main(){
    printf("pop v1.0\n\n");
    read();
    pop();write();
    system("pause");
    return 0;
}
void read(){
    //printf("--read file\n");
    FILE *f;
	f=fopen("data.txt","r");
	//clear old
	while(Q1.size())Q1.pop();
	while(Q2.size())Q1.pop();
	while(Q3.size())Q1.pop();
	// read until "END"
	char tmp[100];
	string next;
	while(1){
        fscanf(f,"%s",tmp);
        next=tmp;
        if(next=="END")break;
        else Q1.push(next);
	}
    while(1){
        fscanf(f,"%s",tmp);
        next=tmp;
        if(next=="END")break;
        else Q2.push(next);
	}
	while(1){
        fscanf(f,"%s",tmp);
        next=tmp;
        if(next=="END")break;
        else Q3.push(next);
	}
    fclose(f);
    return;
}
void write(){
    //printf("--write file\n");

    FILE *f;
	f=fopen("data.txt","w");

    while(Q1.size()){
        fprintf(f,"%s\n",Q1.front().c_str());
        Q1.pop();
    }
    fprintf(f,"END\n\n");
    while(Q2.size()){
        fprintf(f,"%s\n",Q2.front().c_str());
        Q2.pop();
    }
    fprintf(f,"END\n\n");
    while(Q3.size()){
        fprintf(f,"%s\n",Q3.front().c_str());
        Q3.pop();
    }
    fprintf(f,"END\n\n");
    fclose(f);
    read();
}

void pop(){
    // this will not delete an errand but will sent it back into the queue
    string next=Q1.front();Q1.pop();Q1.push(next);
    if(next=="++"){
        next=Q2.front();Q2.pop();Q2.push(next);
        if(next=="++"){
            next=Q3.front();
            Q3.pop();
            Q3.push(next);
        }
    }
    cout<<next<<endl;
}

