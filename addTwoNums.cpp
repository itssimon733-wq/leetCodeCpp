#include <iostream>
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *nxt) : val(x), next(nxt) {}
};
ListNode* build(std::vector<int> digits){
    ListNode head;
    ListNode* tail = &head;
    for(int d : digits){
        tail->next = new ListNode(d);
        tail = tail->next;
    }
    return head.next;
}
void print(ListNode* head){
    for(; head != nullptr; head =head->next){
        std::cout <<head->val<<" ";
    }std::cout<<'\n';
}
class Solution {
    public:
        ListNode* addTwoNums(ListNode* l1, ListNode* l2){
            ListNode* dummyHead = new ListNode(0);
            ListNode* curr = dummyHead;
            int carry = 0;/*since we can only have one digit we carry the overflow*/
            while(l1 != 0 || l2 != 0 || carry != 0){
                int sum = carry;
                if(l1 != nullptr){
                    sum += l1->val;
                    l1 = l1->next;
                }
                if(l2 != nullptr){
                    sum += l2->val;
                    l2 = l2->next;
                }
                carry = sum / 10;
                curr->next = new ListNode(sum % 10);
                curr = curr->next;
            }
            ListNode* result = dummyHead->next;
            delete dummyHead;
            return result;
        }
        
};
int main(){
    ListNode* l1 = build({2,4,3});
    ListNode* l2 = build({5,6,4});
    Solution sln;
    print(sln.addTwoNums(l1,l2));
    return 0;
}