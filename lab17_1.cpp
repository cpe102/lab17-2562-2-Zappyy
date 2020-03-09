#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstring>
using namespace std;

int main(){
    ifstream s("name_score.txt");
    string ltxt;
    int i=0;
    char format[] = "%[^:]: %d %d %d";
    vector<string> name;
    vector<string> grade;
    vector<int> score;
    int t1,t2,t3;
    char n[100]={};
    while(getline(s,ltxt)){

        sscanf(ltxt.c_str(),format,n,&t1,&t2,&t3);
        name.push_back(n);
        score.push_back(t1+t2+t3);
        if(score.at(i)>=80)grade.push_back("A");
        else if(score.at(i)>=70)grade.push_back("B");
        else if(score.at(i)>=60)grade.push_back("C");
        else if(score.at(i)>=50)grade.push_back("D");
        else grade.push_back("F");
        i++;

    }
    char typ[10]={},doftyp[10]={};
    
    do{
        cout<<"Please input your command : ";
        cin >>typ;
        for(int j=0;j<strlen(typ);j++){typ[j]=toupper(typ[j]);}
        if(strcmp(typ,"EXIT")==0)break;
        
        if(strcmp(typ,"GRADE")==0){
            cin >> doftyp;
            for(int j=0;j<strlen(doftyp);j++){
                doftyp[j]=toupper(doftyp[j]);
            }
            int c=0;
            for(int j=0;j<i;j++){
                if(grade.at(j)==doftyp){
                    cout<<name.at(j)<<endl;
                    c=1;
                }
            }
            if(c==0)cout<<"not found\n";
        }else if(strcmp(typ,"NAME")==0){
            cin >> doftyp;
            for(int j=0;j<strlen(doftyp);j++){
                doftyp[j]=toupper(doftyp[j]);
            }
            int c=0;
            for(int j=0;j<i;j++){
                string ntmp=name.at(j);
                for(int k=0;k<ntmp.size();k++){
                    ntmp[k]=toupper(ntmp[k]);
                }
               
                if(strcmp(ntmp.c_str(),doftyp)==0){
                    cout<<name.at(j)<< " grade = "<<grade.at(j)<<endl;
                    c=1;
                }
            }
            if(c==0)cout<<"not found\n";
        }else cout<<"Invalid command\n";
    }while(true);
}