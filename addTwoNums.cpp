struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *nxt) : val(x), next(nxt) {}
};
class Solution {
    public:
        ListNode* addTwoNums(ListNode* li, ListNode* l2){
            ListNode* dummyHead = new ListNode(0);
            ListNode* curr = dummyHead;
            int carry = 0;/*since we can only have one digit we carry the overflow*/
            
        }
        
};