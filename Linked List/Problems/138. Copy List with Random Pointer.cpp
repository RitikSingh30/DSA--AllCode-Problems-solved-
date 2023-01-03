// Time complexity O(N) , space complexity O(1) 
// iss problem ko solve karne ke liye humne star patter banaya hai 
//          * * * * * <- original linked list 
//          | | | | |
//          * * * * * <- clone linked list 
// original linked list ka next point clone linked list ko laya hai and clone linked list ka next pointer original linked list next element 
// ko lagaya hai 
// iska ek map ka bhi solution hai uska time complexity O(n) hai and space complexity O(N) hai 
class Solution {
public:
   
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL ;
        Node* create = new Node(head->val) ;
        Node* auxi = create ;
        Node* orgfront = head ;

        // creating a clone linked list without adding the random pointer position 
        bool fang = false ;
        while(orgfront != NULL){
            Node* cur = new Node(orgfront->val) ;
            if(fang){
                auxi->next = cur ;
                auxi = cur ;
            }
            else fang = true ;
            orgfront = orgfront->next ;
        }

        // creating a start pattern in original and clone linked list 
        Node* temp = create ;
        orgfront = head ;
        while(temp != NULL && orgfront != NULL){
            Node* cur = orgfront->next ;
            orgfront->next = temp ;
            Node* cur1 = temp->next ;
            temp->next = cur ;
            orgfront = cur ;
            temp = cur1 ;
        }

        // setting the random pointer of clone linked list 
        temp = head ;
        while(true){
            Node* point = NULL ;
            Node* point2 = NULL ;
            if(temp->random != NULL){
                point = temp->random ;
                point2 = point->next ;
            }

            temp->next->random = point2 ;
            temp = temp->next ;
            if(temp->next == NULL) break ;
            temp = temp->next ;
        }

        // removing the start pattern from the original and clone linked list 
        temp = create ;
        orgfront = head ;
         while(temp != NULL){
            Node* cur = temp->next ;
            if(cur != NULL) temp->next = cur->next ;
            orgfront->next = cur ;
            temp = temp->next ;
            orgfront = orgfront->next ;
        }

        return create ;
    }
};
