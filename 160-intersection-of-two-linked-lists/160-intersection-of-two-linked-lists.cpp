/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map<ListNode*,int>ump;

        while(headA || headB){
            
            if(ump[headA] == 1 ) return headA;
            
            if(headA){
                
                ump[headA] = 1;
            
                headA=headA->next;
            }
            
            
            if(ump[headB] == 1 ) return headB;
            
            
            if(headB){
                
                ump[headB] =1;
            
                headB=headB->next;
            }
            
        }
        
        return NULL;
    }
};