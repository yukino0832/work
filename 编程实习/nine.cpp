#include <iostream>
struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *createList()
{
    int data;
    std::cout << "输入数据(整数),输入-1结束:" << std::endl;
    ListNode *head = new ListNode;
    head->next = nullptr;
    ListNode *tail = head;
    while (std::cin >> data && data != -1)
    {
        ListNode *newNode = new ListNode;
        newNode->data = data;
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

int count(ListNode *head, int data)
{
    ListNode *node = head->next;
    int num = 0;
    while(node != nullptr)
    {
        if(node->data == data)
            num += 1;
        node = node->next;
    }
    return num;
}
int main()
{
    ListNode *head = createList();
    std::cout << "请输入要计算的num值:" << std::endl;
    int num;
    std::cin >> num;
    std::cout << "个数为:" << count(head, num) << std::endl;
    return 0;
}
