

#include <type_traits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include<set>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
vector<T> inputVector()
{
    string line;
    getline(cin, line);

    stringstream ss(line);

    vector<T> result;
    T value;

    while (ss >> value)
    {
        result.push_back(value);
    }

    return result;
}
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};
ListNode* inputListNode(vector<int> input) {
    ListNode* head = NULL;
    for (auto&& i : input)
    {
        if (head == NULL) {
            head = new ListNode(i);
        }
        else {
            ListNode* t = head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = new ListNode(i);
        }
    }
    return head;
}
