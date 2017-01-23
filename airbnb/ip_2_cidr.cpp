#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <cmath>
using namespace std;


long long ip_2_num(string ip) {
    int a[4];
    int i = 0;
    long long res = 0;
    char ch;
    
    stringstream in(ip);
    in>>a[0] >> ch>>a[1] >> ch >> a[2] >>ch >> a[3];
    for (int i =0 ; i < 4;i ++) 
    {
        res = res *256+ a[i];
        //cout << a[i] <<endl;
    }
    return res;
}

string num_2_ip(long long x) {
    string res; 
    for (int i =0 ; i < 4; i++) {
        int num = x % 256;
        x /= 256;
        string s = to_string(num);
        res = s + res; 
        if (i < 3)
            res='.'+ res;
    }
    return res;
}

vector<string> ip_2_cidr(string start_ip, string end_ip) {
    vector<string > res;
    vector<long long> vc = {
        0x00000000,
        0x80000000,0xC0000000,0xE0000000,0xF0000000,
        0xF8000000,0xFC000000,0xFE000000,0xFF000000,
        0xFF800000,0xFFC00000,0xFFE00000,0xFFF00000,
        0xFFF80000,0xFFFC0000,0xFFFE0000,0xFFFF0000,
        0xFFFF8000,0xFFFFC000,0xFFFFE000,0xFFFFF000,
        0xFFFFF800,0xFFFFFC00,0xFFFFFE00,0xFFFFFF00,
        0xFFFFFF80,0xFFFFFFC0,0xFFFFFFE0,0xFFFFFFF0,
        0xFFFFFFF8,0xFFFFFFFC,0xFFFFFFFE,0xFFFFFFFF
    };
    long long start = ip_2_num(start_ip);
    long long end = ip_2_num(end_ip);
    
    while(start <= end ) {
       // cout << start << " " << end << endl;
        int now_bit = 32;
        while(now_bit > 0) {
            if ((start & vc[now_bit-1]) != start) {
                break;
            }
            now_bit --;
        }
        
        //cout << now_bit <<endl;
        
        
        int need_bit = (int)log2(end - start +  1);
        int same_bit = 32 - need_bit;
        int ans = max(same_bit, now_bit);
        
        string s = num_2_ip(start)+ '/' + to_string(ans);
        res.push_back(s);
        
    
        start = start + (long long)pow(2, 32- ans);
       
    }
    
    
    for (string a : res) {
        cout << a <<endl;
    }
    cout <<endl;
    return res;
}


int main() {
    
    
    ip_2_cidr("128.0.0.4", "128.0.0.7");
     
    ip_2_cidr("255.0.0.7", "255.0.0.19");

    ip_2_cidr("1.1.1.0", "1.1.1.0");


    ip_2_cidr("255.255.255.255", "255.255.255.255");
        
    cout<<"Hello";
    return 0;
}
