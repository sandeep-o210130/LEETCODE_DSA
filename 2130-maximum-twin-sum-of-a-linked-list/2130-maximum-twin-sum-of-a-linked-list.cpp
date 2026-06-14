/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nodes;
        int twin_sum=0,n=0;
        while(head!=NULL){
            nodes.push_back(head->val);
            head=head->next;
            n++;
        }
        for(int i=0;i<(n/2);i++) twin_sum=max(twin_sum,(nodes[i]+nodes[n-1-i]));
        return twin_sum;
    }
};