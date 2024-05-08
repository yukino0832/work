/*
设计思想：
先使用快慢指针(两倍)找到链表的中间节点，然后遍历后半段链表并将每个指针反转，使得后半段链表翻转，再从头和中间指针开始交替连接两个链表
*/
#include <iostream>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

LinkList createList(int L[], int n)   // 创建链表
{
    if (n == 0)
        return nullptr;
    LinkList head = (LinkList)malloc(sizeof(LNode));
    head->data = L[0];
    head->next = nullptr;
    LinkList now = head;
    for (int i = 1; i < n; i++)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        p->data = L[i];
        p->next = nullptr;
        now->next = p;
        now = p;
    }
    return head;
}

LinkList reverse(LinkList head)  // 翻转链表
{
    if (head == nullptr || head->next == nullptr)
        return head;
    LinkList pre = nullptr, now = head, next;
    while (now != nullptr)
    {
        next = now->next;
        now->next = pre;
        pre = now;
        now = next;
    }
    return pre;
}

void concat(LinkList link1, LinkList link2) // 交替合并两个链表
{
    LinkList next1, next2;
    while (link1 != nullptr && link2 != nullptr)
    {
        next1 = link1->next;
        next2 = link2->next;
        link1->next = link2;
        link2->next = next1;
        link1 = next1;
        link2 = next2;
    }
}

void print(LinkList head)  // 打印链表
{
    LinkList p = head;
    LinkList newp = p->next;
    while (newp != nullptr)
    {
        std::cout << p->data << " ";
        free(p);
        p = newp;
        newp = newp->next;
    }
    std::cout << p->data << std::endl;
    free(p);
    free(newp);
}

int main(){
    int L[1000];
    int n;    // n为L的长度
    std::cin >> n;
    for(int i=0; i<n; i++)
    {
        std::cin >> L[i];
    }
    LinkList head = createList(L, n);
    if (head == nullptr || head->next == nullptr)
    {
        std::cout << "链表太短，失败" << std::endl;
    }
    else
    {
        LinkList fast = head, slow = head, pre;
        while(fast != nullptr && fast->next != nullptr)// 寻找中间节点
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        LinkList head2 = reverse(slow);  // 翻转后半段
        concat(head, head2);
    }
    print(head);
    return 0;
}

/*
算法中找出中间节点时间复杂度为O(n),翻转链表与合并链表时间复杂度为O(n/2)，因此时间复杂度为O(n)。
*/
