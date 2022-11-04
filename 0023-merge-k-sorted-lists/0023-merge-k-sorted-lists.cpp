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
    ListNode* merge2lists(ListNode* l1,ListNode* l2){
        
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val > l2->val) swap(l1,l2);
        
        ListNode* prev = NULL,*temp = l1;
        
        while(l2 != NULL){
            
            while( l1 != NULL && l1->val <= l2->val){
                
                prev = l1;
                l1 = l1->next;
            }
            
            prev->next = l2;
            swap(l1,l2);
        }
        return temp;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0) return NULL;
        
        ListNode *head = lists[0];
        
        int n= lists.size();
        
        for(int i=1;i<n;++i){
            head = merge2lists(head,lists[i]);
        }
        return head;
    }
};