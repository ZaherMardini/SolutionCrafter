#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// just remember to save the next current position at the BEGINNING of the loop
ListNode* reverseList(ListNode* head) {
    if(!head) return nullptr;
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* nxt;
    while(current){
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    return prev;
}


int main(){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    ListNode* current = reverseList(&node1);



    while(current){
        cout << (*current).val;
        if(current->next) cout << "->";
        current = current->next;
    }
    cout << endl;
}