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
    ListNode *reverse(ListNode *head){
        ListNode *prev=NULL,*cur=head,*right=NULL;
        
        while(cur != NULL){
            
            right = cur->next;
            
            cur->next = prev;
            
            prev = cur;
            
            cur = right;
            
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head,*fast = head;
        
        if(head == NULL || head->next == NULL) return true;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        
        slow = slow->next;
        
        ListNode *temp =head;
        
        while(slow != NULL){
            
            if(slow->val != temp->val) return false;
            
            slow = slow->next;
            
            temp=temp->next;
        }
            
          return true; 
    }
};