class Solution {
public:
    // recursive solution time complexity O(N) space complexity O(N)
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return head ;
    
        ListNode* prev = NULL ;
        ListNode* cur = head ;
        ListNode* last = head ;

        ListNode* temp = head ;
        int cnt ;
        for(cnt = 0 ; temp != NULL ; cnt++) temp = temp->next ;

        if(cnt < k) return head ;

        for(int i = 0 ; i < k && cur != NULL ; i++){
            ListNode* node = cur->next ;
            cur->next = prev ;
            prev = cur ;
            cur = node ;
        }

        head->next = reverseKGroup(cur,k) ;

        return prev ;   
    }
};

class Solution {
public:
    // iterative solution time complexity O(N) and space complexity O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* prev = head ;

    bool fang = true ;

    while(prev != NULL){

        int cnt = 1 ;

        ListNode* add1 = prev ;
        ListNode* add2 = NULL ;
        ListNode* add3 = NULL ;
        ListNode* temp = prev ;
        ListNode* prev1 = NULL ;

        while(temp != NULL && cnt <= k){
            ListNode* node1 = temp->next ;
            temp->next = prev1 ;
            prev1 = temp ;
            if(cnt == k) add2 = temp ; 
            cnt++ ;
            temp = node1 ;
        }

        add3 = temp ;
        if(fang){
            head = add2 ;
            fang = false ;
        }

        ListNode* temp1 = temp ;
        cnt = 1 ;
        while(temp != NULL && temp1->next != NULL && cnt < k){
            temp1 = temp1->next ;
            cnt++ ;
        }

         if(cnt < k){
            add1->next = temp ;
            break ;
        }
        add1->next = temp1 ;
        prev = temp ;
    }
    return head ;
    }
};