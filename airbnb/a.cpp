#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <string>
using namespace std;



set<string> st;
class User{
public: 
    string user;
    vector<string> citys;
    string orig;
    int rank;
    User(){}
    User(string a, vector<string> b, string c) {
        user = a;
        citys = b;
        orig = c;
        rank  = 0;
    }
};


bool operator <(const User & a, const User& b) {
    return a.rank > b.rank;
}
User parsestring(string org) {
    int i;
    string s = org;
    string user;
    vector<string>vc;
    string city;
    for (i = 0; i < s.size(); i++) {
        if (s[i] == ',')
            break;
        user+=s[i];
    }

    i++;
    for (; i <= s.size(); i++) {
        if (i==s.size() || s[i] == ',') {
            vc.push_back(city);

            city = "";
            continue;
        }
        city+=s[i];
    }
    
    User ans = User(user, vc, s);
    return ans;
}


void parsewl(vector<string> wl) {
    int i, j;
    User me = parsestring(wl[0]);
    for (i = 0; i < me.citys.size(); i ++) {
        st.insert(me.citys[i]);
    } 
    int countme = me.citys.size();

    vector<User> ans;
    for (i = 1; i < wl.size(); i++) {
        User other = parsestring(wl[i]);
        int count = 0;
        for (j = 0; j < other.citys.size(); j++) {
            string now = other.citys[j];
            if (st.find(now)!=st.end()) {
                count ++;
            }
        }
        if (count*2 >= countme) {
            other.rank = count;
            ans.push_back(other);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0 ; i < ans.size(); i ++) {
        cout << ans[i].orig <<endl;
    }
}


void solutions(vector<string> wl) {
    if (wl.size() == 0) {
        // do something
    }
    parsewl(wl);
}

int main() {
    vector<string> a = {
    "Me,Amsterdam,Barcelona,London,Prague", 
    "U1,Amsterdam,Barcelona,London,Prague", 
    "U2,Shanghai,Hong Kong,Moscow,Sydney,Melbourne",
    "U3,London,Boston,Amsterdam,Madrid",
    "U4,Barcelona,Prague,London,Sydney,Moscow"};
    solutions(a);  
    return 0;     
}
/* 
Your previous Python content is preserved below:

'''
Let’s say Airbnb launches a new feature called "Travel Buddies". As part of this feature, users create wishlists of cities they want to visit. For the purpose of this question, let these wishlists be provided as a file with the following format:

<user name>,<city 1>,<city 2>...
<user name>,<city 1>,<city 2>...

There is one and only one line in the file for each user.

User A is a travel buddy of user B if A has 50% or more of the cities in his/her wishlist in common with B.


Now, given your wishlist as input, write a solution to print out your travel buddies sorted by rank. The rank of a travel buddy is the number of cities they share in common with your wishlist.

Sample input:

U1,Amsterdam,Barcelona,London,Prague
U2,Shanghai,Hong Kong,Moscow,Sydney,Melbourne
U3,London,Boston,Amsterdam,Madrid
U4,Barcelona,Prague,London,Sydney,Moscow

Me,Amsterdam,Barcelona,London,Prague

Expected Result:

Travel buddies:

U1
U4
U3


'''


 */