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
        int twin_sum=0,n=0;
        ListNode *temp=head,*prev=NULL;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        temp=head;
        for(int i=0;i<(n/2);i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        prev=temp;
        temp=temp->next;
        while(temp!=NULL){
            ListNode* t=temp->next;
            temp->next=prev;
            prev=temp;
            temp=t;
        }
        while(head!=NULL){
            twin_sum = max(twin_sum,head->val+prev->val);
            head=head->next;
            prev=prev->next;
        }
        return twin_sum;
    }
};