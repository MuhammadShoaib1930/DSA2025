#include <iostream>
#include <vector>

#include "list_node.cpp"
#include "_15.cpp"
using namespace std;

void _print(vector<int> res) {
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
}
vector<int> _input(int n) {
    vector<int> values = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    return values;
}
ListNode* inputList(int n) {
    ListNode* head = nullptr;

    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        ListNode* node = new ListNode(value);
        if (head == nullptr) {
            head = node;
        } else {
            ListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = node;
        }
    }
    return head;
}
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    return 0;
}
