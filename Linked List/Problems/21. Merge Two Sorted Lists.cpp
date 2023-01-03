// Making use of Merge sort algorithm only we are not dividing the array into two part just 
// merging the two linked list using merge function 
//Time complexity O(N) Space complexity O(N) -> (stack->space) 
// iss code ki space complexity hum reduce kar sakte hai bas recursive call ki jagah while loop 
// so solve karna hoga 
class Solution {
public:
    ListNode* merge(ListNode*& firstPartHead , ListNode*& SecondPartHead){
    ListNode* newHead = NULL ;
    // base case if one of the node is NULL 
    if(firstPartHead == NULL) return SecondPartHead ;
    else if(SecondPartHead == NULL) return firstPartHead ;

    // set the first node as head and recursive call for the next node
    if(firstPartHead->val <= SecondPartHead->val){
        newHead = firstPartHead ;
        newHead->next = merge(firstPartHead->next,SecondPartHead) ;
    }
    // set the second node as head and recursive call for the next node
    else{
         newHead = SecondPartHead ;
        newHead->next = merge(firstPartHead,SecondPartHead->next) ;
    }
    // return the new head 
    return newHead ;
}
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1,list2) ;
    }
};