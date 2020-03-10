#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
int main() {
  ifstream f;
  f.open("name_score.txt");
    string cs;
    int n=0;
      while(getline(f,cs)){
        n++;
      }
  f.close();
  f.open("name_score.txt");
    vector<int> sum;
    vector<string> grade;
    vector<string> namev;
    vector<string> cap;
    char name[100];
    string N,g;
    char format[] ="%[^:]: %d %d %d";
    int i=0,a,b,c;
      while(getline(f,cs)){
        const char * text = cs.c_str();
        sscanf(text,format,name,&a,&b,&c);
        N=name;

        namev.push_back(N);
        if((a+b+c)>=80)g="A";
        else if((a+b+c)>=70)g="B";
        else if((a+b+c)>=60)g="C";
        else if((a+b+c)>=50)g="D";
        else g="F";
        grade.push_back(g);
        sum.push_back(a+b+c);
        i++;
      }
    f.close();
    i=0;
    string order;
    cout<<"Please input your command :";
    getline(cin,order);

    for(int i=0;i<order.size();i++){
      order[i]=tolower(order[i]);
    }

    order+=":";
    char pformat[] ="%s %[^:]";
        while(order!="exit:"){
          string sst="Invalid",snd="";
          const char * sorder = order.c_str();
          char st[100],nd[100];
          sscanf(sorder,pformat,st,nd);
          sst=st;
          snd=nd;
          snd[0]=toupper(snd[0]);
          for(int i=1;i<snd.size();i++){
            if(snd[i]==' '){
              snd[i+1]=toupper(snd[i+1]);
              i++;
            }
            else{snd[i]=tolower(snd[i]);}
          }

            if(sst=="name"){
              int check=0;
              for(int i=0;i<n;i++){
                if(snd==namev[i]){
                  cout<<namev[i]<<"'s grade = "<<grade[i]<<endl;
                  check=1;
                  
                }
              }
              if(check==0)cout<<"Cannot found"<<endl;
            }

            else if(sst=="grade"){
              int check=0;
              for(int i=0;i<n;i++){
                if(snd==grade[i]){
                  cout<<namev[i]<<endl;
                  check=1;
                }
              }
              if(check==0) cout<<"Cannot found"<<endl;
            }

            else{
              cout<<"Invalid command"<<endl;
            }
            cout<<"Please input your command :";
            getline(cin,order);
            
            /*cout<<order;*/
            for(int i=0;i<order.size();i++){
              order[i]=tolower(order[i]);
              
            }
            order+=":";
           
        }
 
  return 0;
}
