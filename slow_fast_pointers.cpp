// lets understand the slow and fast pointers
// they are very much similar to the doubly linked list where we have a next and previous pointer

// first lets try to find the middle of the list with the help of slow and fast pointers
class ListNode {
    public:
        ListNode* next;
        int val;
};

// lets start with defining a method which takes in head which is the start of the list
ListNode* middleOfList(ListNode* head) {
    // we will initialize the slow and fast pointers to head
    ListNode *slow = head, *fast = head;
    // now we iterate through the list till and the node next to fast exist
    while (fast && fast->next) {
        // now we increment the slow and fast pointers
        slow = slow->next;
        fast = fast->next->next;
    }
    // since we are incrementing fast 2 times then it is quite obvious that 
    // the middle has to be at the location of slow pointer 
    return slow;
}

// now lets check if the list ha a cycle or not
// this can be determined if the slow and the fast pointer converge
bool hasCycle(ListNode* head) {
    // lets initialize both the pointers to head
    ListNode *slow = head, *fast = head;

    // now we keep iterating till the fast and the node next to fast is not null
    while (fast && fast->next) {
        // now we will increment the slow and fast pointers
        slow = slow->next;
        fast = fast->next->next;
        // if the slow and fast pointers are at the same location then we return true
        if (slow == fast) {
            return true;
        }
    }
    // otherwise false
    return false;
}

// now lets see how we can find the head of the cycle in the list
// the slow and fast pointer can help us in finding if the list has a cycle or not
// but for determining the head we need another slow pointer
ListNode* checkHead(ListNode* head) {
    // initialize the slow and fast pointer to head
    ListNode *slow = head, *fast = head;

    // now we iterate through the loop till the fast and the node next to fast pointer exist
    while (fast && fast->next) {
        // now we increment the slow and fast pointer
        slow = slow->next;
        fast = fast->next->next;
        // if both the pointers converge then we break out of the loop
        if (slow == fast) {
            break;
        }
    }

    // the fast and the node next to fast does not exist then it is basically null
    if (!fast || !fast->next) {
        return nullptr;
    }

    // now we define another slow pointer
    // the idea here is that if both the slow pointers converge after 
    // slow original slow pointer converges with fast pointer then the point of convergence is the 
    // head of the cycle
    // we will initialize the second slow pointer to the head of the list
    ListNode *slow2 = head;
    // and we keep on incrementing till both of them don't converge
    while (slow != slow2) {
        slow = slow->next;
        slow2 = slow2->next;
    }
    // and we just return the value
    return slow;
}