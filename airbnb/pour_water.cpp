// Finding Lakes

// [5,4,2,1,2,3,2,1,0,1,2,4]
// values = altitude of the terrain
// indices = position of the terrain

// +           
// ++         +
// ++   +     +
// +++ +++   ++
// ++++++++ +++
// ++++++++++++

// dump_water(terrain, water_amount, dump_location)

// terrain = [5,4,2,1,2,3,2,1,0,1,2,4]
// water_amount = 8
// dump_location = 1

// +
// ++         +
// ++WWW+     +
// +++W+++WWW++
// ++++++++W+++
// ++++++++++++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;

// To execute C++, please define "int main()"

void print_array(vector<int> vc, vector<int> ans) {
  int maxx =0 ;
  for (int hi : vc) {
    maxx = max(maxx, hi);
  }
  
  for (int i = maxx; i > -1; i--) {
    for (int j = 0; j < (int)vc.size(); j++) {
      if(i > ans[j]) {
        cout << ' '; 
      } else if (i > vc[j]) {
        cout << 'W';
      } else {
        cout << '+';
      }
    }
    cout <<endl;
  }
}


void dump_water(vector<int> vc, int num, int x) {
  int n = vc.size();
  int maxx =0 ;
  vector<int> ans = vc;
  for (int hi : vc) {
    maxx = max(maxx, hi);
  }
  
  if (x < 0 || x > n)
    return;
  
  int l_pre = x, r_pre = x;
  
  while (num--) {
    int l = l_pre, r= r_pre;
    
    while(l-1 >= 0) {
      if (ans[l-1] > ans[l]) {
        break;
      }
      l --;
    }
    
    while(r+1 < n) {
      if(ans[r+1] > ans[r]) {
        break;
      }
      r ++;
    }
    
    int id = x;
    if (ans[l] < ans[r]) {
      id = l;
      r_pre = r;
      l_pre = x;
    } else {
      id = r;
      l_pre = l;
      r_pre = x;
    }
    
    ans[id]++;
    
    
    
    if (ans[id] > maxx)
      break;
  }
  
  print_array(vc, ans);
}

int main() {
  
  vector<int> vc = {5,4,2,1,2,3,2,1,0,1,2,4};
  //print_array(vc);
  dump_water(vc, 8, 5);
  cout <<endl;
  dump_water(vc, 8, 1);
  cout <<endl;
  
  dump_water(vc, 100, 1);
  cout <<endl;
  
  dump_water(vc, 1, 5);
  
  return 0;
}

