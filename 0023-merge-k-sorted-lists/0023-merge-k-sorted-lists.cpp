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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n=lists.size();
        
        ListNode* dummy = new ListNode();
        int i=0;
        
        for( i=0;i<n;++i){
            if(lists[i] == NULL) continue;
            dummy->next = lists[i];
            break;
        }
        
        
        for( i=i+1;i<n;++i){
            
            if(lists[i] == NULL ) continue;
            
            ListNode *l1= dummy->next,*l2,*prev = NULL,*temp=NULL;
            
            l2=lists[i];
            
            if(l1->val > l2->val) swap(l1,l2);
            
            temp = l1;
            
            while(l2 != NULL){
                
                while(l1 != NULL && l1->val <= l2->val ){
                    prev = l1;
                    l1 = l1->next;
                }
                
                prev->next = l2;
                swap(l1,l2);
            }
            dummy->next = temp;
        }
        return dummy->next;
    }
};