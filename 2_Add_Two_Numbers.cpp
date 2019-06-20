/*
给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int flag = 0;
    int num = 0;
    ListNode *l = new ListNode(0);
    ListNode *r = l, *p = l1, *q = l2;
    while(p != NULL || q != NULL ){
        int x = (p!=NULL)?p->val:0;
        int y = (q!=NULL)?q->val:0;
        num = x + y + flag;
        flag = num / 10;
        num = num % 10;
        r->next = new ListNode(num);
        r = r->next;
        if(p!=NULL)
            p = p->next;
        if(q!=NULL)
            q = q->next;
    }
    if(flag > 0){
        r->next = new ListNode(flag);
    }
    return l->next;
}