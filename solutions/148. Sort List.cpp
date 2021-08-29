/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode * getMid(ListNode * head)
    {
        ListNode* midPrev = NULL;
        while (head && head->next) {
            midPrev = (midPrev == NULL) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = NULL;
        return mid;
    }
    
    ListNode * merge ( ListNode * list1, ListNode* list2)
    {
        ListNode * dummy  = new ListNode(0);
        ListNode * mergehead = dummy;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                dummy->next = list1;
                list1 = list1->next;
            }
            else{
                dummy->next = list2;
                list2 = list2->next;                
            }
            dummy = dummy->next;
        }
        if(list1) 
            dummy->next = list1;
        else 
            dummy->next = list2;
        return mergehead->next;
            
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
      ListNode *mid = getMid(head);
      ListNode * left = sortList(head);
      ListNode * right = sortList(mid);
      return merge(left,right);
    }
};
