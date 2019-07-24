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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result;
        ListNode *p, *q, *current;
        int left;
		int tmp;

        left = 0;
        current = NULL;
        result = NULL;
		if (l1 && l2) {
			tmp = l1->val + l2->val;
			left = tmp - 10 < 0 ? 0 : 1;
			current = new ListNode(tmp - 10 < 0 ? tmp : (tmp - 10));
			result = current;
		}
        for (p = l1->next, q = l2->next; p && q; p = p->next, q = q->next) {
			tmp = p->val + q->val + left;
			left = tmp - 10 < 0 ? 0 : 1;
            
			current->next = new ListNode(tmp - 10 < 0 ? tmp : (tmp - 10));
			current = current->next;
        }
        if (left || p || q) {
			/* the longer list wins */
            ListNode *remain = p ? p : q; 
            /* first, check the remain. */
            if (remain){
                for (; remain; remain = remain->next){
					tmp = remain->val + left;
					left = tmp - 10 < 0 ? 0 : 1;
                    
					current->next = new ListNode(tmp - 10 < 0 ? tmp : (tmp - 10));
					current = current->next;
                }
            }
            /* all done, something left? */
            if (left) {
				current->next = new ListNode(1);
            }
        }
        return result;
    }
};
