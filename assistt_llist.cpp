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
 * getNode function - AI Optimized Version
 * Technique: Two Pointers / Gap Strategy
 * Logic: Move runner N steps ahead, then move both until runner hits tail.
 */
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* runner = llist;

    // Step 1: Create the gap
    for (int i = 0; i < positionFromTail; i++) {
        runner = runner->next;
    }

    // Step 2: Move together
    while (runner->next != nullptr) {
        current = current->next;
        runner = runner->next;
    }

    return current->data;
}

int main() {
    int tests;
    cout << "Enter number of tests: ";
    cin >> tests;

    while (tests--) {
        SinglyLinkedList* llist = new SinglyLinkedList();
        int llist_count;
        
        cout << "Enter list size: ";
        cin >> llist_count;

        cout << "Enter elements: " << endl;
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