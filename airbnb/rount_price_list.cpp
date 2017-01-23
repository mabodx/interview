#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

/*
1.2, 3.7, 2.3, 4.8 

链接: https://instant.1point3acres.com/thread/139420
来源: 一亩三分地

*/

class node {
public:
    double orig;
    double val;
    int roundint;
    int id;
    node(double a, double b, int idd){
        id = idd;
        orig = a;
        roundint = b;
        val = a-b;
    }
};

bool cmp(const node& a, const node & b) {
    return a.val > b.val;
}
bool cmpid(const node &a, const node &b) {
    return a.id < b.id;
}

vector<double> output(vector<double> vc) {
    
    double sum = 0;
    double round_sum = 0;
    vector<node> vb;
    int i = 0;
    for (double a : vc) {
        sum += a;
        vb.push_back(node(a, floor(a), i++));
        round_sum += floor(a);
    }
    
    cout << sum   << "  " << round_sum << endl;
    int diff = round(sum) - round_sum;
    sort(vb.begin(), vb.end(), cmp);
    
    for (i = 0; i < diff; i ++) {
        vb[i].roundint+=1;
    }
    sort(vb.begin(), vb.end(), cmpid);
    double ans = 0;
    for (i = 0; i < vb.size(); i ++) {
        ans = ans + abs(vc[i]- (double)vb[i].roundint);
           
    }
    cout << "ans:" << ans << endl;
    
    for (i = 0; i < vb.size(); i ++) {
        cout << vb[i].roundint << "\t";       
    }cout <<endl;
    
    for (i = 0; i < vc.size(); i ++) {
        cout << vc[i] << "\t";       
    }cout <<endl;
    
    return vc;
}

int main() {
    
    //output({1.2, 3.7, 2.3, 4.8 });
    //output({1.2, 3.7, 2.3, 4.8 });
    output({-0.4,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.3,1.3});
    output({1.2, 2.3, 3.4});
    //cout<<"Hello";
    return 0;
}
