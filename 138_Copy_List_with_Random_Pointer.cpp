/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
要求返回这个链表的深拷贝。 

示例：
输入：
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

解释：
节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
 
提示：
你必须返回给定头的拷贝作为对克隆列表的引用。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
解法一：
本题实际为链表的复制，重点在该链表的节点中包含有随机指针。在链表的复制中，从前到后的一次复制时，随机指针可能指向并未复制的节点，那么这时当前节点的随机指针的指向变出现了错误。
为了解决这个问题，在节点的复制时，若当前节点的随机指针指向的节点未创建，创建新节点，并让当前节点的随机指针指向；若当前节点随机指针指向的节点已创建，直接指向即可。

解法二：
通过扭曲原来的链表，并将每个拷贝节点都放在原来对应节点的旁边。这种旧节点和新节点交错的方法让我们可以在不需要额外空间的情况下解决这个问题。
遍历原来的链表并拷贝每一个节点，将拷贝节点放在原来节点的旁边，创造出一个旧节点和新节点交错的链表。原节点 next 指向的都是新创造出来的节点。
迭代这个新旧节点交错的链表，并用旧节点的 random 指针去更新对应新节点的 random 指针。比方说， B 的 random 指针指向 A ，意味着 B' 的 random 指针指向 A' 。
现在 random 指针已经被赋值给正确的节点，只需将 next 指针正确赋值，以便将新的节点正确链接同时将旧节点重新正确链接。
 */

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

Node* copyRandomList(Node* head) {
    Node *p = head;
    while (p != nullptr){
        Node *new_node = new Node(p->val,p->next,nullptr);
        p->next = new_node;
        p = new_node->next;
    }
    p = head;
    while (p != nullptr){
        Node *q = p->next;
        if(p->random)
            q->random = p->random->next;
        p = q->next;
    }
    p = head;
    Node *copy_head = nullptr, *q = nullptr;
    if(p!=nullptr){
        copy_head = q = p->next;
        p->next = q->next;
        p = p->next;
    }
    while(p != nullptr){
        q->next = p->next;
        q = p->next;
        p->next = q->next;
        p = q->next;
    }
    return copy_head;
}