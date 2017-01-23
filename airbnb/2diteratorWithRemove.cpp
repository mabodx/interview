/*
给一个2d array，要求写一个顺序访问这个2d array的Iterator，包括hasNext()与next()。注意2d array的每行中元素的个数可能不一样，也可能为空。跪在这最后一面上了。
二面的时候他忘了问culture， 所以加了一面。最后跪在最后一面上了，估计是culture不fit

 [[],[1,2,3],[4,5],[],[],[6],[7,8],[],[9],[10],[]]
 
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

void print(vector<vector<int>> a) {
    for(vector<int> now : a) {
        for (int c : now) {
            cout << c << " ";
        }
        cout << ";" << endl;
    }
    
}

class Vector2D{
public:
    Vector2D(){}
    Vector2D(vector<vector<int>>& c) {
        a =c;
        i = 0, j = 0;
        prei = -1, prej =-1;
    }
    int i,j ;    
    int prei, prej;
    int next() {
        int now = a[i][j];
        prei = i;
        prej = j;
        j++;
        return now;
    }

    bool hasNext() {
        while(i < a.size()) {
            if (j >= a[i].size()) {
                i++;
                j = 0;
            }
            else 
                break;
        }
        if (i < a.size() && j < a[i].size())
            return true;
        return false;
    }
    
    bool remove() {
        if (i == prei && j == prej) {
            return false;
        }
        
        a[prei].erase(a[prei].begin()+prej);
        
        i = prei;
        
        j = prej;
        return true;
        
    }
    vector<vector<int>> a;
    
};

int main() {
    vector<vector<int>> a = { {}, { 1, 2, 3 }, { 4, 5 }, {}, {}, { 6 }, { 7, 8 }, {}, { 9 }, { 10 }, {} };
    
    Vector2D b = Vector2D(a);
    print(b.a);
    cout <<endl;
    while(b.hasNext()) {
        b.hasNext();
        b.hasNext();
        cout << b.next() <<endl;
        
        
        b.hasNext();
        cout << b.next() <<endl;
        b.remove();
    }
    cout <<endl;
    
    print(b.a);
    
    return 0;
}
