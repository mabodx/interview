#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
using namespace std;



void get(vector<int> vc, int x, int num) {
    
    int l = x, r=x;
    int n = vc.size();
    vector<int> ans =vc;
    
    while(num--) {
        
        l = x;
        while(l-1>=0) {
            if(ans[l-1] > ans[l]) {
                break;
            }
            
            l--;
        }
        
        if (ans[l] < ans[x]) {
            ans[l]++;
            continue;
        } else {
            r = x;
            while(r+1 < n) {
                if(ans[r+1] > ans[r]) {
                    break;
                }
                r++;
            }
            
            if (ans[r] < ans[x]) {
                ans[r]++;
                continue;
            }
        }
        ans[x]++;    
    }    
    
    int maxx = 0;
    for (int a : ans) {
        maxx = max(maxx, a);
    }
    
    for (int j = 0 ; j <= maxx; j++) {
        for (int i = 0; i < n; i++) {
            if (j<=vc[i])
                cout << '+';
            else if(j <= ans[i])
                cout << 'w';
            else 
                cout << ' ';
        }
        cout <<endl;
    }
    cout <<endl;
}

int main() {
    vector<int> vc= {5,4,2,1,2,3,2,1,0,1,2,4};
    for (int i = 9; i< 15; i++) 
        get(vc, 5, i);
    
    //cout<<"Hello";
    return 0;
}
