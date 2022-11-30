#include <iostream>
using namespace std;
#include <list>
#include <string>
#include <algorithm>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* header = new ListNode(0);
    ListNode* curr = header;
    int carry = 0;
    while (l1 != nullptr || l2 !=nullptr || carry != 0){
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;

        int sum  = x + y + carry;
        carry = sum/10;

        curr->next = new ListNode(sum%10);
        curr = curr -> next;

        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;

    }
    return header->next;
}

int main()
{
    ListNode* l1 = new ListNode;
    l1->val = 2;
    ListNode* l2 = new ListNode;
    l2->val = 4;
    addTwoNumbers(l1, l2);
}