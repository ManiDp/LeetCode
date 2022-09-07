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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        
        ListNode *temp=head;
        
        while(temp){
            count++ ;
            temp = temp->next;
        } 
        
        if(count == 1) return NULL;
        
        count = count - n;
        
        if(count == 0) return head->next;
        
        temp = head;
        
        for(int i=0;i<count-1;++i){
            temp = temp->next;
        } 
        
        temp->next = temp->next->next;
        
        return head;
    }
};