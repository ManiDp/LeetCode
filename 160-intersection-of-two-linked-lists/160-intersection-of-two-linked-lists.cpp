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
        int l1 =0,l2=0;
        ListNode *cur=headA;
        
        while(cur){
            l1++;
            cur = cur->next;
        }
        
        cur=headB;
        
        while(cur){
            l2++;
            cur = cur->next;
        }
        
        int k=abs(l1-l2);
        
        ListNode *list1=headA,*list2=headB;
        
        if(l1>l2){
            for(int i=0;i<k;++i){
                list1=list1->next;
            }
        }else{
            for(int i=0;i<k;++i){
                list2=list2->next;
            }
        }
        
        while(list1 != list2){
            list1=list1->next;
            list2=list2->next;
        }
        
        return list1;
    }
};