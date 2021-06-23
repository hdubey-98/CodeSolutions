class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if(head == NULL or head->next == NULL or right == left)
            return head;
        
        
        ListNode* fake = new ListNode(-1), *tail = fake;
        ListNode* reverseListTail = NULL;
        
        int pos = 1;
        
        while(head)
        {
            if(pos == left)
            {
                //start reversing
                ListNode* t1 = head, *t2 = t1->next;
                t1->next = NULL;
                reverseListTail = head;
                
                while(pos < right)
                {
                    ListNode* t3 = t2->next;
                    t2->next = t1;
                    t1 = t2;
                    t2 = t3;
                    
                    pos++;
                }
                
                reverseListTail->next = t2;
                tail->next = t1;
                break;
            }
            else
            {
                tail->next = head;
                head = head->next;
                tail = tail->next;
                tail->next = NULL;
                pos++;
            }
        }
        
        return fake->next;
        
    }
};
