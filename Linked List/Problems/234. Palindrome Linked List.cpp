// TC = O(N) , SpaceComplexity = O(1) ;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return 1 ;
        else if(head->next->next == NULL){
            if(head->val == head->next->val) return 1 ;
            else return 0 ;
        }

        ListNode* slow = head ;
        ListNode* fast = head->next ;
        while(fast != NULL){
            fast = fast->next ;
            if(fast != NULL){
                fast = fast->next ;
                slow = slow->next ;
            }
        }

        ListNode* prev = NULL ;
        ListNode* start = slow->next ;
        while(start != NULL){
            if(start->next == NULL){
                slow->next = start ;
            }
            ListNode* temp = start->next ;
            start->next = prev ;
            prev = start ;
            start = temp ;
        }

        ListNode* secondHalf = slow->next ;
        ListNode* stop = secondHalf ;
        while(head != stop && secondHalf != NULL){
            if(head->val != secondHalf->val) return 0 ;
            head = head->next ;
            secondHalf = secondHalf->next ;
        }

        return 1 ;
    }
};
// ek aur appraoch hai isse solve karne ka linked list ka pura data ek vector me copy kar do then 
// check kar lo ki wo palindrome hai ya nahi 
// but uski time complexity O(N) hogi and space complexity O(N) hogi