/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class cmp{
public:
    bool operator () (const ListNode* a, const ListNode* b)  const{
    return a->val > b->val;
    }
};


// int ListNode::operator<(const ListNode& other)
// //bool operator< ( const node& other ) const
// { return val < other.val }

class Solution {
public:
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        cout<<lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        // priority_queue<ListNode*> q;
        
        for (ListNode* now : lists) {
        
            if (now!=NULL) {
                q.push(now);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(!q.empty()) {
            ListNode* now = q.top(); 
            q.pop();
            cur ->next = now;
            if (now->next!=NULL) {
                q.push(now->next);
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};



