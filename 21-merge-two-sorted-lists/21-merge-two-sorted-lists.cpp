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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *dummy1 = new ListNode(0);
        
        ListNode* cur = dummy1;
        
        while(list1 && list2){
            
            ListNode *dummy = new ListNode(0);
            
            if(list1->val > list2->val){
                
                dummy->val = list2->val;
                
                cur->next = dummy;
                
                list2 = list2->next;
            }else{
                dummy->val = list1->val;
                
                cur->next = dummy;
                
                list1 = list1->next;
            }
            
            cur = dummy;
        }
        
        while(list1 != NULL){
            
             ListNode *dummy = new ListNode(0);
            
                dummy->val = list1->val;
                
                cur->next = dummy;
                
                list1 = list1->next;
            
            cur = dummy;
        }
        
        while(list2 != NULL){
            
             ListNode *dummy = new ListNode(0);
            
                dummy->val = list2->val;
                
                cur->next = dummy;
                
                list2 = list2->next;
            cur = dummy;
        }
        
        return dummy1->next;
    }
};