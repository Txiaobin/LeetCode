/*
对链表进行插入排序。
插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

示例 1：
输入: 4->2->1->3
输出: 1->2->3->4

示例 2：
输入: -1->5->3->4->0
输出: -1->0->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insertion-sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
对链表进行插入排序和对顺序表进行插入排序思路相同，仅仅在插入的实现上不相同。
链表的插入：为了方便起见，建立一空的头结点作为查找的起始位置。从头结点开始往后一次判断下一个节点是否大于待插入节点，若为真，则插入当前节点后。
*/

#include<stddef.h>
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
ListNode* insertionSortList(ListNode* head) {
    ListNode dummyHead(0);
    dummyHead.next = head;
    auto pre = &dummyHead;
    auto q = pre->next;
    while(q){
        auto begin = &dummyHead;
        while(begin->next->val < q->val && begin->next != q){
            begin = begin->next;
        }
        if(begin->next == q){
            pre = pre->next;
            q = q->next;
        }
        else{
            pre->next = q->next;
            q->next = begin->next;
            begin->next = q;
            q = pre->next;
        }    
    }
    return dummyHead.next;
}