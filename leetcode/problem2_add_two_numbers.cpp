/* 自己的第一次相当之粗糙啊，拿来示众 */

/*
 * 给定两个链表分别代表两个非负整数，链表的每个结点分别存储整数的每位数字，且是逆序存储，即：数字最低位存储在链表表头，数字最高位存储在链表表尾。求解这两个整数的和并以相同的链表形式返回计算的结果。

 *  例如：   输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)   输出：7 -> 0 -> 8
 * */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int addNode(ListNode **current, int num) {
        ListNode *node;
        int left;

        if (num >= 10) {
            node = new ListNode(num-10);
            left = 1;
        } else {
            node = new ListNode(num);
            left = 0;
        }
        if (*current == NULL) {
            *current = node;
        } else {
            (*current)->next = node;
            *current = node;
        }
        return left;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result;
        ListNode *p, *q, *current;
        int tmp;
        int left;

        left = 0;
        current = NULL;
        result = NULL;
        for (p = l1, q = l2; p && q; p = p->next, q = q->next) {
            tmp = p->val + q->val + left;
            left = addNode(&current, tmp);
            if (result == NULL)
                result = current;
        }
        if (left == 1 || p || q) {
            ListNode *remain = p ? p : (q ? q : NULL); /* the longer list wins */
            /* first, check the remain. */
            if (remain){
                ListNode *r;
                for (r = remain; r; r = r->next){
                    tmp = r->val + left;
                    left = addNode(&current, tmp);
                }
            }
            /* all done, something left? */
            if (left == 1) {
                if (current == NULL) {
                    current = new ListNode(1);
                    result = current;
                } else
                    current->next = new ListNode(1);
            }
        }
        return result;
    }
};
