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
bool hasCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;


    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    return false;

}


int main(){
    ListNode node1(1);
    // ListNode node2(2);
    // ListNode node3(3);
    // ListNode node4(4);
    // ListNode node5(5);

    // node1.next = &node2;
    // node2.next = &node3;
    // node3.next = &node4;
    // node4.next = &node5;
    // node5.next = &node1;

    bool result = hasCycle(&node1);



    // while(current){
    //     cout << (*current).val;
    //     if(current->next) cout << "->";
    //     current = current->next;
    // }
    // cout << endl;
}