// Time complexity O(n) space complexity O(1) ;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head ;
        ListNode* prev = NULL ;
        while(cur != NULL){
            if(cur->next != NULL && cur->val == cur->next->val){
                cur = cur->next ;
                ListNode* temp = cur ;
                if(cur->next != NULL and cur->val != cur->next->val) cur = cur->next ;
                else if(cur->next == NULL){
                    cur = cur->next ;
                }
                if(prev == NULL) head = cur ;
                if(prev != NULL and temp->next == NULL){
                    prev->next = cur ;
                }
                continue;
            }
            if(prev != NULL) prev->next = cur ;
            prev = cur ;
            cur = cur->next ;
        }
        return head ;
    }
};

// Time complexity O(n) space complexity O(1) ;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head ;
        ListNode* prev = NULL ;
        while(cur != NULL){
            if(cur->next != NULL && cur->val == cur->next->val){
                if(cur->next->next != NULL && cur->val == cur->next->next->val){
                    if(prev != NULL){
                        prev->next = cur->next ;
                        cur->next = NULL ;
                        cur = prev->next ;
                    }
                    else{
                        ListNode* temp = cur->next ;
                        head = temp ;
                        cur = temp ; 
                    }
                }
                else{
                    if(prev != NULL){
                        prev->next = cur->next->next ;
                        cur->next->next = NULL ;
                        cur->next = NULL ;
                        cur = prev->next ;
                    }
                    else{
                        ListNode* temp = cur->next->next ;
                        cur->next->next = NULL ;
                        cur->next = NULL ;
                        head = temp ;
                        cur = temp ; 
                    }
                }
                continue;
            }
            prev = cur ;
            cur = cur->next ;
        }
        return head ;
    }
};

// Time complexity O(nlogn) space complexity O(N) ;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head ;
        map<int,int> mp ;
        while(cur != NULL){
            mp[cur->val]++ ;
            cur = cur->next ;
        }
        cur = head ;
        ListNode* prev = NULL ;
        int cnt = 1 ;
        while(cur != NULL){
            if(mp[cur->val] > 1){
                if(prev != NULL){
                    prev->next = cur->next ;
                    cur->next = NULL ;
                    cur = prev->next ;
                    continue;
                }
                else{
                    ListNode* temp = cur->next ;
                    cur->next = NULL ;
                    cur = temp ;
                    head = cur ;
                    continue;
                }
            }
            prev = cur ;
            cur = cur->next ;
        }
        return head ;
    }
};
