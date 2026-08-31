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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int c=1;
        ListNode *prev = head;
        head=head->next;
        int minn=INT_MAX,start=-1,end=-1;
        while(head->next!=NULL){
            if((head->val>prev->val && head->val>head->next->val)||(head->val<prev->val && head->val<head->next->val)){
                if(start==-1) start=c+1;
                else if(end==-1){
                    end=c+1;
                    minn=min(minn,end-start);
                }
                else{
                    minn = min(minn,c+1-end);
                    end=c+1;
                }
            }
            c++;
            prev=head;
            head=head->next;
        }
        if(start==-1 || end==-1) return {-1,-1};
        return {minn,end-start};
    }
};