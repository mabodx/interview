
/*
string/ CSV parse-O
题⺫⽬目是关于如何Parse csv file：举个例⼦子，给定⼀一个CSV⽂文件，格式是 “some_name|
some_address|some_phone|some_job”，要求输出Json format “{name:some_name,
address:some_addres,phone:some_phone, job:some_job}”
特殊情为两个引号之间的分号，不可作为分割字符 http://itjob.io/post/349
John, Smith, john.smith@gmail.com, Los
Angeles, 1
Jane, Roberts, janer@msn.com, "San
Francisco, CA", 0
"Alexandra ""Alex""", Menendez, alex.menendez@gmail.com,
Miami, 1
"""Alexandra Alex"""
John| Smith | john.smith@gmail.com | Los
Angeles | 1
Jane| Roberts| janer@msn.com| San
Francisco, CA| 0
Alexandra "Alex"| Menendez| alex.menendez@gmail.com|
Miami| 1
"Alexandra Alex"
要考虑 quote, escape \得情况
    
*/


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

class node{
    
};

string get(string s, int flag) {
    int i = 0;
    
    string a;
    int b = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i]=='\"') {
            b++;
            if (b == 1 || b == flag) {
                continue;
            }
            
        }
        a+=s[i];
    }
   
    s = a;
    a = "";
    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && s[i-1]=='\"' && s[i] == '\"') {
            continue;
        }
        a+=s[i];
    }
    return a;
}

void parse(string s){
    stringstream in(s);
    string now;
    int i = 0, j = 0;
    int flag =0 ;
    int print = 0;
    for (i = 0 ; i < s.size();) {
        string a;
        flag = 0;
        for (j = i; j < s.size(); j++) {
            if (s[j] == '\"') {
                flag ++;
            }
            if (flag % 2==0) {
                if (s[j] == ',')
                    break;
            }
            a+=s[j];
        }
        i = j + 1;
        
        a = get(a, flag);
        if (print > 0) {
            cout << "|";
        }
        print ++;
        cout << a;
    }
    cout << endl;
}




int main() {

    string s = "dyJohn,dydydydydydySmith,dydydydyjohn.smith@gmail.com,dydyLos Angeles,dydydydy1";
    
    parse(s);
    cout << endl;
    s = "Jane,Roberts,janer@msn.com,\"San Francisco, CA\",0";
    parse(s);
    cout << endl;
    
    
    s = "\"Alexandra \"\"Alex\"\"\",Menendez,alex.menendez@gmail.com,Miami,1";
    parse(s);
    cout << endl;
    
    s = "\"\"\"Alex a \"\"\"";
    
    parse(s);    
    //cout<<"Hello";
    return 0;
}
