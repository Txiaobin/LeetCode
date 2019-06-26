/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:
给定链表 1->2->3->4, 重新排列为 1->4->2->3.

示例 2:
给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
1：将链表划分为前后两个链表L1，L2；
2：将L2链表进行翻转；
3：将翻转后的链表L2和L1进行拼接。
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *findMid(ListNode *head){
    auto *slow = head, *fast = head->next;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
ListNode *reverse(ListNode *head){
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

void reorderList(ListNode* head){
    if(!head || !head->next)
        return;
    auto *p=head;
    auto mid = findMid(head);
    auto q = mid->next;
    mid->next = nullptr;
    q = reverse(q);
    while(q&&p){
        auto r = p->next;
        p->next = q;
        q = q->next;
        p->next->next = r;
        p = r;
    }
}