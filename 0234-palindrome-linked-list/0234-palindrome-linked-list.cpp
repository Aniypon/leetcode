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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head; 
        ListNode* fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        } 

        ListNode* prev = nullptr;

        while (slow){
            ListNode* tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }

        ListNode* l= head;
        ListNode* r = prev;
        while(r){
            if (l->val != r->val){
                return false;
            }
            l = l->next;
            r = r->next;
        }
        return true;

    }
};