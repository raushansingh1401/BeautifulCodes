
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(!head || !head->next) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }
};