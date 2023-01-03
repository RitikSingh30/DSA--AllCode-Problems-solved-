// Time complexity O(N + M) , Space complexity O(max(N,M)) for creating a ans linked list
class Solution
{
    public:
    // reverse the linked list 
    Node* reverse(Node*& cur){
        Node* prev = NULL ;
        while(cur != NULL){
            Node* temp = cur->next ;
            cur->next = prev ;
            prev = cur ;
            if(temp != NULL) cur = temp ;
            else break ;
        }
        return cur ;
    }

    Node* build(Node*& first , Node*& second , int& carry , Node* ans){
        int sum = carry ;
        if(first != NULL) sum += first->data ;
        if(second != NULL) sum += second->data ;
        carry = sum / 10 ;
        sum = sum % 10 ;
        Node* add = new Node(sum) ;
        if(ans == NULL) ans = add ;
        else{
            Node* dum = ans ;
            ans = add ;
            add->next = dum ;
        }
        return ans ;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first,struct Node* second)
    {
        if(first == NULL) return second ;
        else if(second == NULL) return first ;

        // reversing first linked list 
        first = reverse(first) ;
        // reversing second linked list
        second = reverse(second) ;

        int carry = 0 ;
        Node* ans = NULL ;
        while(first != NULL and second != NULL){
            ans = build(first,second,carry,ans) ;
            first = first->next ;
            second = second->next ;
        }

        while(first != NULL){
            Node* send = NULL ;
            ans = build(send,first,carry,ans) ;
            first = first->next ;
        }
        while(second != NULL){
            Node* send = NULL ;
            ans = build(send,second,carry,ans) ;
            second = second->next ;
        }

        if(carry > 0){
            Node* add = new Node(carry) ;
            Node* dum = ans ;
            ans = add ;
            add->next = dum ;
        }

        return ans ;
    }
};
