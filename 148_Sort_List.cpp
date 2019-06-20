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
 */
#include<stddef.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* cut(ListNode* head, int size){
    auto p = head;
    while(--size && p!=NULL){
        p = p->next;
    }
    if(!p)
        return NULL;
    auto q = p->next;
    p->next = NULL;
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