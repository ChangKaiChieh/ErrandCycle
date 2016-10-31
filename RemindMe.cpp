#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
queue<string> Q1,Q2,Q3;
void read();
void write();
void show_instru();
void pop();
void listQ();
void del();
void push();

int main(){
    printf("RemindMe v1.1\tby Johnny Chang 2016.10.31\n\n");
    read();
    show_instru();
    string s;
    while(cin>>s){
        if(s=="pop"||s=="1")pop(),write();
        else if(s=="push"||s=="2")push(),write();
        else if(s=="del"||s=="3")del(),write();
        else if(s=="list"||s=="4")listQ();
        else if(s=="exit"||s=="5")break;
        else if(s=="track"||s=="6")system("explorer .");
        else printf("can't find such command, please check input\n");
        show_instru();
    }

    return 0;
}
void read(){
    //printf("--read file\n");
    FILE *f;
	f=fopen("data.txt","r");
	//clear old
	while(Q1.size())Q1.pop();
	while(Q2.size())Q2.pop();
	while(Q3.size())Q3.pop();
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
    //puts("Instructions:");
    puts("[1]pop \t\t-> pop an errand");
    puts("[2]push X <string> -> put errand into Box[X]");
    puts("[3]del X Y \t-> delete errand Y from Box[X]");
    puts("[4]list \t-> list all errands");
    puts("[5]exit \t-> end this program");
    puts("[6]track dir\t-> open explorer to the directory of this program");
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
void push(){
    int X;
    string input;
    cin>>X>>input;
    cout<<"put <"<<input<<"> into Box "<<X<<endl;
    if(X==1)Q1.push(input);
    else if(X==2)Q2.push(input);
    else if(X==3)Q3.push(input);
    else puts("parameter error");
}
void del(){
    int X,Y,cnt=0;
    cin>>X>>Y;
    queue<string> tmp;
    if(X==1){
        while(Q1.size()){
            if(Q1.front()=="++"){tmp.push(Q1.front()),Q1.pop();continue;}
            if(cnt==Y){
                cout<<"comfirm to delete "<<Q1.front()<<" ?"<<endl;
                cout<<"Y/N?"<<endl;
                string input;
                cin>>input;
                if(input=="Y"){
                    cout<<"delete "<<Q1.front()<<endl;
                    Q1.pop();
                }
                else cout<<"canceled"<<endl;
            }
            if(Q1.size())tmp.push(Q1.front()),Q1.pop();
            cnt++;
        }
        while(tmp.size()){
            Q1.push(tmp.front());
            tmp.pop();
        }
    }
    else if(X==2){
        while(Q2.size()){
            if(Q2.front()=="++"){tmp.push(Q2.front()),Q2.pop();continue;}
            if(cnt==Y){
                cout<<"comfirm to delete "<<Q2.front()<<" ?"<<endl;
                cout<<"Y/N?"<<endl;
                string input;
                cin>>input;
                if(input=="Y"){
                    cout<<"delete "<<Q2.front()<<endl;
                    Q2.pop();
                }
                else cout<<"canceled"<<endl;
            }
            if(Q2.size())tmp.push(Q2.front()),Q2.pop();
            cnt++;
        }
        while(tmp.size()){
            Q2.push(tmp.front());
            tmp.pop();
        }
    }
    else if(X==3){
        while(Q3.size()){
            if(Q3.front()=="++"){tmp.push(Q3.front()),Q3.pop();continue;}
            if(cnt==Y){
                cout<<"comfirm to delete "<<Q3.front()<<" ?"<<endl;
                cout<<"Y/N?"<<endl;
                string input;
                cin>>input;
                if(input=="Y"){
                    cout<<"delete "<<Q3.front()<<endl;
                    Q3.pop();
                }
                else cout<<"canceled"<<endl;
            }
            if(Q3.size())tmp.push(Q3.front()),Q3.pop();
            cnt++;
        }
        while(tmp.size()){
            Q3.push(tmp.front());
            tmp.pop();
        }
    }
}
void listQ(){
    read();
    int cnt=0;
    cout<<"Box 1"<<endl;
    while(Q1.size()){
        if(Q1.front()=="++"){Q1.pop();continue;}
        cout<<'['<<cnt<<']'<<Q1.front()<<endl;
        Q1.pop();
        cnt++;
    }
    cnt=0;
    cout<<"\nBox 2"<<endl;
    while(Q2.size()){
        if(Q2.front()=="++"){Q2.pop();continue;}
        cout<<'['<<cnt<<']'<<Q2.front()<<endl;
        Q2.pop();
        cnt++;
    }
    cnt=0;
    cout<<"\nBox 3"<<endl;
    while(Q3.size()){
        cout<<'['<<cnt<<']'<<Q3.front()<<endl;
        Q3.pop();
        cnt++;
    }
    read();
}
