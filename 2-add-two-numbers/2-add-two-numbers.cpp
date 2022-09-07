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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy1 = new ListNode();
        
        ListNode *cur = dummy1;
        
        int carry = 0,value=0;
        
        while(l1 || l2){
            
            ListNode *dummy = new ListNode();
            
            value = 0;
            
            if(l1) value +=l1->val , l1 = l1->next;
            
            if(l2 != NULL)  value +=l2->val ,  l2 = l2->next;
            
            value += carry;
            
            cur->next = dummy;
            
            dummy->val = value % 10;
            
            carry = value / 10;
            
            cur = dummy;
            
        }
        
        if(carry){
            ListNode *dummy = new ListNode();
            
            cur->next = dummy;
            
             dummy->val = carry;
        }
        return dummy1->next;
    }
};