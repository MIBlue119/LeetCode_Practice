# 2. Add Two Numbers (Ｍedium)

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.



## The Result at C++

<pre><code>
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
        ListNode  *Dummyhead = new ListNode;
        ListNode*   l_sum = Dummyhead;
        int Carry = 0 ;
        int sum = 0;
        
        while(  ( l1 != NULL )  ||  ( l2 !=NULL )  )
        {   
            int x = ( l1 != NULL) ? l1->val : 0; 
            int y = ( l2 != NULL) ? l2->val : 0;
            int sum = x + y + Carry; 
            Carry = sum/10;
            l_sum ->next = new ListNode(sum % 10);
            l_sum = l_sum->next;
            if( l1 != NULL) l1 = l1->next;
            if( l2 != NULL) l2 = l2->next;
            
            /*
            if( ( l1 != NULL )  &&  ( l2 !=NULL )  )
            {
                sum = l1->val + l2->val + Carry;
                l_sum->val = sum %10;
                 Carry = sum / 10;
            }
            else if(  l1 != NULL  )
            {
                sum = l1->val + Carry;
                l_sum->val = sum % 10;
                 Carry = sum / 10;
            }
            else if( l2 != NULL )
            {
                sum = l2->val + Carry;
                l_sum->val = sum % 10;
                Carry = sum / 10;
            }
            else
            {
                l_sum->val = Carry;
                Carry = 0;
            }    
            sum = 0;
            if( l1->next != NULL || l2->next != NULL || Carry!=0 )
            {
                l_sum->next = newNode();
            }
           */ 
        }
        if( Carry > 0 ) 
        {
            l_sum->next = new ListNode(Carry);
        }
        return  Dummyhead->next;  
    }
    

};

</code></pre>

