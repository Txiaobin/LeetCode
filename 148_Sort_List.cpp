/*
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:
输入: 4->2->1->3
输出: 1->2->3->4

示例 2:
输入: -1->5->3->4->0
输出: -1->0->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题方法：
O(nlogn)时间复杂度的排序算法：希尔排序，快速排序，归并排序，堆排序。
而常数级空间复杂度的只有归并排序。
本题考察链表的归并排序实现。
假头节点是一个很方便很实用的链表操作的技巧。
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* cut(ListNode* head, int size){
    auto p = head;
    while(--size && p!=nullptr){
        p = p->next;
    }
    if(!p)
        return nullptr;
    auto q = p->next;
    p->next = nullptr;
    return q;
}
    
ListNode* merge(ListNode* first, ListNode* second){
    ListNode Head(0);
    auto p = &Head;
    while(first && second){
        if(first->val < second->val){
            p->next = first;
            p = first;
            first = first->next;
        }
        else{
            p->next = second;
            p = second;
            second = second->next;
        }
    }
    if(first)
        p->next = first;
    if(second)
        p->next = second;
    return Head.next;
}
    
ListNode* sortList(ListNode* head) {
    ListNode dummyHead(0);
    dummyHead.next = head;
    int length = 0;
    auto p = head;
    while(p){
        ++ length;
        p =  p->next;
    }
    for(int size = 1; size < length; size <<=1){
        auto cur = dummyHead.next;
        auto trail = &dummyHead;
        while(cur){
            auto first = cur;
            auto second = cut(cur,size);
            cur = cut(second,size);
            trail->next = merge(first, second);
            while(trail->next)
                trail = trail->next;
        }
    }
    return dummyHead.next;
}