#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
    ListNode* newHead = new ListNode(-1);
    ListNode* newHead2 = new ListNode(-1);
    ListNode* curr = newHead;
    ListNode* curr2 = newHead2;
    int cache = 0, val, even = 1;
    while (head != nullptr){
        val = head->val;
        if (even == 1){
            even--;
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        else{
            even++;
            curr2->next = new ListNode(val);
            curr2 = curr2 ->next;
        }
        head = head -> next;

        
    }
    curr->next = curr2;
    return newHead->next;
}

int main(){

}
