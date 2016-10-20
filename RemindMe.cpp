#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#define CMT //
using namespace std;
queue<string> Q1,Q2,Q3;
int N12,N23;
void read();
void write();
void show_instru();
void pop();
void listQ(){
    int cnt=0;
    cout<<"Queue 1"<<endl;
    while(Q1.size()){
        cout<<'['<<cnt<<']'<<Q1.front()<<endl;
        Q1.pop();
        cnt++;
    }
    cnt=0;
    cout<<"\nQueue 2"<<endl;
    while(Q2.size()){
        cout<<'['<<cnt<<']'<<Q2.front()<<endl;
        Q2.pop();
        cnt++;
    }
    cnt=0;
    cout<<"\nQueue 3"<<endl;
    while(Q3.size()){
        cout<<'['<<cnt<<']'<<Q3.front()<<endl;
        Q3.pop();
        cnt++;
    }
    read();
}
int main(){
    printf("RemindMe v0.6\n\n");
    read();
    show_instru();
    string s;
    while(cin>>s){
            if(s=="pop"){
                //printf("--input = pop\n");
                pop();write();
            }
            else if(s=="changeN"){
                //printf("--input = changeN\n");
            }
            else if(s=="push"){
                //printf("--input = push\n");
            }
            else if(s=="delete"){
                //printf("--input = delete\n");
            }
            else if(s=="list"){
                //printf("--input = list\n");
                listQ();
            }
            else if(s=="exit"){
                break;
            }
            else{
                printf("can't find such command, please check input\n");
            }
        }

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
void show_instru(){

    puts("------------------------------------------------------------------");
    printf("Instructions:\n");
    printf("pop \t\t-> pop an errand\n");
    printf("changeN X Y \t-> change QueueX order to Y (X = 2 or 3)\n");
    printf("push X <string> -> push errand to QueueX\n");
    printf("delete X Y \t-> delete errand Y in QueueX\n");
    printf("list \t\t-> list all errands\n");
    printf("exit \t\t-> end this program\n");
    puts("------------------------------------------------------------------");
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
