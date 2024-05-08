
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//复制到这边好多报错，不管了
//想法挺简单，一个while+多特判跑完全进程，或者把链表数据存到数组再处理，这里用的后者

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int a[100]={0},b[100]={0},ai=0,bi=0,c=0;
    struct ListNode* l3=(struct ListNode*)malloc(sizeof(struct ListNode));
    l3->next=NULL;
    while(l1!=NULL){
        a[ai]=l1->val;
        l1=l1->next;
        ai++;
//        printf("%d",a[ai]);
    }
    while(l2!=NULL){
        b[bi]=l2->val;
        l2=l2->next;
        bi++;
    }
    int cache=0;
    struct ListNode* l3c=l3;//单向链表，另开一个指针修改，保证至少能返回一个头指针作为结果
    l3c->val=(a[c]+b[c]+cache)%10;
    cache=(a[c]+b[c]+cache)/10;
    ai--;
    bi--;
    c++;
    while(cache!=0||ai>0||bi>0){
        l3c->next=(struct ListNode*)malloc(sizeof(struct ListNode));
//        printf("%d",l3c->val);
        l3c=l3c->next;
        l3c->next=NULL;//妈的，所有指针一定要初始化，不然会被报错烦死
        l3c->val=(a[c]+b[c]+cache)%10;
        cache=(a[c]+b[c]+cache)/10;//改运算顺序，让cache延后一个周期起作用实现进位
        ai--;
        bi--;
        c++;
    }
    return l3;
}