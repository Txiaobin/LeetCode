/*
反转一个单链表。

示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
反转链表两种方法：头插法和指针法。
头插法：建立一个头结点，每次取出链表中的第一个节点插入头结点后，当链表中节点都取出完时，新建立头结点后面的链表即为反转后的链表；
指针法：使用三个指针分别指向当前节点，当前节点前序节点，当前节点后序节点，每次将当前节点的指针指向前序节点，遍历整个链表后完成反转。
反转链表的两种方法分别包含迭代法和递归法。  
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseList_1(ListNode *head){
    ListNode *dummyhead = new ListNode(0);
    dummyhead->next = nullptr;
    auto q = head;
    auto p = head;
    while(q){
        q = q->next;
        p->next = dummyhead->next;
        dummyhead->next = p;
        p = q;
    }
    return dummyhead->next;
}

ListNode *reverseList_2(ListNode *head) {
    ListNode *pre = nullptr, *cur = head, *r = nullptr;
    while (cur != nullptr) {
        r = cur->next;
        cur->next = pre;
        pre = cur;
        cur = r;
    }
    return pre;
}