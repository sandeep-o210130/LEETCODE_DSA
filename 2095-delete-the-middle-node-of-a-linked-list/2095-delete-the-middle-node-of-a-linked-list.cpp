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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp=head,*prev=NULL;
        int c=0,c1=0;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
        c=c/2;
        temp=head;
        if(c==0) return prev;
        while(temp!=NULL && c1<c){
            prev=temp;
            temp=temp->next;
            c1++;
        }
        prev->next=temp->next;
        return head;
    }
};