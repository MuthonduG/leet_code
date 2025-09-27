
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        bool isEmpty(ListNode* head) {
            return head == nullptr;
        }

        ListNode* removeNthFromEnd(ListNode* head, int n) {
            // check if list is empty
            if(isEmpty(head)) return head;

            // create a dummy node to handle edge cases
            ListNode* dummy = new ListNode();

            // point dummy's next to head
            dummy->next = head;

            // initialize two pointers
            ListNode* first = dummy;
            ListNode* second = dummy;

            // move first pointer n+1 steps ahead
            for(int i = 0; i <= n; i++) {
                first = first->next;
            }

            // move both pointers until first reaches the end
            while(first != nullptr) {
                first = first->next;
                second = second->next;
            }

            ListNode* nodeToDelete = second->next;
            second->next = second->next->next;
            delete nodeToDelete;
            ListNode* newHead = dummy->next;
            delete dummy;
            return newHead;
        }
    
};