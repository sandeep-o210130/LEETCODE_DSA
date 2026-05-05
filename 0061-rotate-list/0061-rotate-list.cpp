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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode* temp = head,*prev=head,*temp1 = head;
        int c=0,c1=0;
        while(temp!=NULL){
            c++;
            prev=temp;
            temp=temp->next;
        }
        k = k%c;
        if(k==0) return head;
        while(temp1!=NULL){
            c1++;
            if(c1>=(c-k)) break;
            temp1=temp1->next;
        }
        ListNode* t = temp1->next;
        temp1->next=NULL;
        prev->next=head;
        head = t;
        return head;
    }
};