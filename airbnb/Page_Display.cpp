/* 
给出⼀一个list：每个元素是［host_id, list_id, score, city］ 按score排好序，进⾏行
分⻚页。每个⻚页⾯面不能重复有重复的host-id.使⽤用LinkedHashMap，如果有相同id则放在下⼀一
⻚页
保存⼀一个最后能⽤用的⻚页⾯面， 每当⼀一个⻚页⾯面满了，更新哈希表
*/
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <unordered_map>

using namespace std;


class node{
public:
    int host;
    int listid;
    double score;
    string city;
    string org;
    node (){}
    node (int a, int b, double c, string d, string e){
        host = a;
        listid = b;
        score = c;
        d = city;
        org = e;
    }
};


vector<node> readd(vector<string> ins) {
    vector<node> ans;
    char ch;
    for (string now : ins) {
        
        stringstream in(now);
        int a; int b; double c; string d;
        
        in>>a >> ch;
        in>>b >> ch;
        in>>c >> ch;
        getline(in, d, ',');
        
        ans.push_back(node(a,b,c,d,now));
        
    }
    cout << "====================" <<endl;
    return ans;
}

int main() {

    int maxx = 12;
    vector<string> in={
      "1,28,300.1,SanFrancisco",
      "4,5,209.1,SanFrancisco",
      "20,7,208.1,SanFrancisco",
      "23,8,207.1,SanFrancisco",
      "16,10,206.1,Oakland",
      "1,16,205.1,SanFrancisco",
      "6,29,204.1,SanFrancisco",
      "7,20,203.1,SanFrancisco",
      "8,21,202.1,SanFrancisco",
      "2,18,201.1,SanFrancisco",
      "2,30,200.1,SanFrancisco",
      "15,27,109.1,Oakland",
      "10,13,108.1,Oakland",
      "11,26,107.1,Oakland",
      "12,9,106.1,Oakland",
      "13,1,105.1,Oakland",
      "22,17,104.1,Oakland",
      "1,2,103.1,Oakland",
      "28,24,102.1,Oakland",
      "18,14,11.1,SanJose",
      "6,25,10.1,Oakland",
      "19,15,9.1,SanJose",
      "3,19,8.1,SanJose",
      "3,11,7.1,Oakland",
      "27,12,6.1,Oakland",
      "1,3,5.1,Oakland",
      "25,4,4.1,SanJose",
      "5,6,3.1,SanJose",
      "29,22,2.1,SanJose",
      "30,23,1.1,SanJose"};
    
    vector<node> vc;
    vc = readd(in);
    
    
    vector<vector<node>>a;
    int cur = 0;
    unordered_map<int, int >mp;
    for (node now : vc) {
        int curid;
        if (mp.find(now.host) != mp.end()) {
            if (mp[now.host] < cur) {
                mp[now.host] = cur;
            } else {
                mp[now.host] =  mp[now.host]+1;
            }
        } else {
            mp[now.host] = cur;
        }
        
        if (a.size() <= mp[now.host]) {
            vector<node> c = vector<node>();
            a.push_back(c);
        }
       
        
        a[mp[now.host]].push_back(now);
        if(a[mp[now.host]].size()==maxx) {
            cur += 1;
        }
    }
    for (int i = 0; i < a.size(); i ++) {
        cout << "page " << i <<endl;        
        for (int j = 0; j < a[i].size(); j ++) 
            cout << a[i][j].org << endl;
        cout <<endl;
    }
    
    cout<<"Hello";
    return 0;
}
