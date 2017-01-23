/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger> st;
        NestedInteger a;
        st.push(a);
        int j;
        for (int i = 0 ; i < s.size(); i++) {
            if (s[i]== '[') {
                st.push(NestedInteger());
            } else if(s[i] == ']'){
                NestedInteger b = st.top();
                st.pop();
                
                st.top().getList().push_back(b);
            } else if (s[i] == ',') {
                continue;
            } else {
                string now;
                for (j = i; j < s.size(); j ++) {
                    if (!isdigit(s[j]) && s[j]!='-' && s[j]!='+') {
                        break;
                    }
                    now += s[j];
                }
                stringstream in(now);
                int n = 0;
                in>>n;
                st.top().getList().push_back(NestedInteger(n));
                i = j-1;
            
            }
        }
        return st.top().getList()[0];
    }
};
