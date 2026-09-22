#include <stdio.h>
#include <stdlib.h>


//定义单向节点
typedef struct  _node{
        int data;
        struct  _node *next;
    } node , *LinkList;


int main(){
 /* 声明头指针，节点0
为了体现答题的顺序性，在不使用函数的前提下，就写成了这样 */
    node node0 = {0,NULL};
    node *Head = &node0;
return 0;
}


//定义储存数据的节点的函数
node* create_node(int number){
//动态内存分配
    node *p = (node*)malloc(sizeof(node));
     if(!p){
        printf("错误!");
        return NULL; 
    }
    p -> data = number;
    p -> next = NULL;
    return p;
}


//添加元素
//头插法：
void Head_in(LinkList Head,int n){
//定义一个新的节点 A
    LinkList A = (node*)malloc(sizeof(node));
    if(!A){
        printf("错误！");
        return;
    }
    A -> data = n;
//A指向头节点0
    A -> next = Head -> next;
//头指针指向A
    Head ->next = A;
return;
}
//尾插法：
void Tail_in(LinkList Head,int n){
//如法炮制
    LinkList A = (node*)malloc(sizeof(node));
    if(!A){
        printf("错误！");
        return;
    }
    A -> data = n;
    A -> next = NULL;
    LinkList p = Head;
//设置尾指针p
    while(p -> next != NULL){
        p = p -> next;
    }
//尾指针p指向A
    p -> next = A;
return;
}


//查找元素
//遍历链表函数
void all_data(LinkList Head){
//设置工具指针p
    LinkList p = Head;
    if(p -> next){
    while(p -> next != NULL){
//考虑到一般情况下，链表第一个节点为零节点，第二个节点为首元节点
        p = p -> next;
        printf("%d",p -> data);
        }
    }else {
        printf("空链表。");
    }
return;
}
//查找节点的函数
int data_search(LinkList Head,int n){
//设置工具指针p，计数器count
    LinkList p = Head -> next;
    int count = 1;
        for(;p && p -> data != n;count++){
             p = p -> next;
        } 
    if(p){
        return count;
    }else {
        return 0;//返回0表示False
    }
}


//删除和更改
int delete_node(LinkList Head,int n){
    /*这是我第一次写的，通过遍历得到总节点数
    LinkList p1 = Head -> next;
    if(!p1) return 0;
    int i = 1;
    while(p1 -> next){
        i++;
        p1 = p1 -> next;
    }
    if(i<n) return 0; */
    if(n < 1 || Head -> next == NULL) return 0;
// 双指针：p 在前 q 在后
//设置工具指针P,指称目标节点
    LinkList p = Head;
    LinkList q = p -> next;
    int count = 1;
    while(q && count < n){
        p = q;
        q = q -> next;
        if(!q) return 0;//节点总数小于n
        count++;
    }
    p -> next = q -> next;
    free(q);
    return 1;
}


//反转函数
//单链表反转
void up_side_down(LinkList Head){
     if (Head->next == NULL || Head->next->next == NULL) {
        return;
    }
    LinkList p = Head -> next;
    LinkList q = p -> next;
    while(q){
        p -> next = q -> next;
        q -> next = p;
        Head -> next = q;
        q = p -> next;        
    }
    return;
}