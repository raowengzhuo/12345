//插入排序（随机数字）
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *);
int main(int argc, char *argv[]) 
{
     struct node a; // 准备一个空的头节点，可简化代码
     struct node *p;
     int i, len = 10;
     p = &a;
     srand(time(NULL)); // 随机数种子
     for (i = 0; i < len; i++) 
    {
         p->next = (struct node *)malloc(sizeof(struct node));
         p = p->next;
         p->data = rand() % 100; // 0-100间的随机数
        
    }
     p->next = NULL;
     display((&a)->next);
     struct node b = {0, NULL};
     struct node *q, *temp;
         // 待排序链表中每次取出一个节点，
         // 插入进已排好序链表的合适位置
         p = (&a)->next;
     while (p != NULL) 
    {
         temp = p->next; // 临时保存下一个节点
         q = &b;
         while (q->next != NULL) // 遍历已排好序的链表，寻找合适的位置插入
            
        {
             if (p->data < q->next->data) break;
             q = q->next;
            
        }
         // 已找到合适位置插入
          p->next = q->next;
         q->next = p;
         p = temp;
        
    }
      display((&b)->next);
     //display((&a)->next);
       return 0;
    
}
 void display(struct node *head)
{
    struct node *p = head;
    while (p != NULL) 
    {
         printf("%d ", p->data);
         p = p->next;
        
    }
     printf("\n");
    
}