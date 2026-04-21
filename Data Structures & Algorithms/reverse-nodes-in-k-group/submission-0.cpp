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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* curr = head;
        int n = 0;
        while(curr != NULL && n < k){
            curr = curr->next;
            n++;
        }

        ListNode* prev = head;
        if(n == k){
            // reverse k nodes
            prev = reverseKGroup(curr,k);
            curr = head;
            while(n-- && curr != NULL){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
        }

        return prev;
    }
};
