#include <iostream>
#include <vector>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

/*
 * getNode function - Scratch Version (Manual logic)
 * 1. Count length (First Pass)
 * 2. Calculate target index
 * 3. Traverse to target (Second Pass)
 */
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    SinglyLinkedListNode* temp = llist;
    int length = 0;

    // Step 1: Count total nodes
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }

    // Step 2: Determine target position from Head
    int target = (length - 1) - positionFromTail;

    // Step 3: Traverse again to the target node
    temp = llist;
    for (int i = 0; i < target; i++) {
        temp = temp->next;
    }

    return temp->data;
}

int main()
{
    int tests;
    cout << "Enter number of tests: ";
    if (!(cin >> tests)) return 0;

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist = new SinglyLinkedList();

        int llist_count;
        cout << "Enter list size: ";
        cin >> llist_count;

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            llist->insert_node(llist_item);
        }

        int position;
        cout << "Position from tail: ";
        cin >> position;

        int result = getNode(llist->head, position);

        cout << "Result: " << result << endl;

        free_singly_linked_list(llist->head);
    }

    return 0;
}