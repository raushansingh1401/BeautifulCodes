
class Solution {
public:

    ListNode* reverseList(ListNode* head){

        if(!head || !head->next) return head;

        ListNode *curr(head), *prev(NULL);

        while(curr){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode *initPos(head), *lastPos(head), *prevPos(NULL), *nextPos(NULL);

        while(left>1){
            prevPos = initPos;
            initPos= initPos->next;
            left--;
        }

        while(right>1){
            lastPos = lastPos->next;
            right--;
        }

        nextPos = lastPos->next;
        lastPos->next = NULL;

        ListNode* reversedHead = reverseList(initPos);
        initPos->next = nextPos;

        if(prevPos) {
            prevPos->next = reversedHead;
            return head;
        }else{
            return reversedHead;
        }
    }
};