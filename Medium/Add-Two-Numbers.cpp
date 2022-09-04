/**
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* reversed_list_node = sum_lists( l1, l2 );
        ListNode* return_node = reverse_list( reversed_list_node );

        return return_node;
    }

    ListNode* sum_lists( ListNode* left, ListNode* right )
    {
        ListNode* last_node = nullptr;
        bool overflow = false;

        while (true)
        {
            ListNode* new_node = nullptr;

            if ( left == nullptr and right == nullptr )
            {

                if ( overflow )
                {
                    new_node = new ListNode;
                    new_node->next = last_node;
                    new_node->val = 1;
                    last_node = new_node;
                }

                break;
            }

            int value = 0;
            if ( overflow )
            {
                ++value;
                overflow = false;
            }

            left  ? value += left->val : value += 0;
            right ? value += right->val : value += 0;

            value > 9 ? overflow = true : overflow = false;

            new_node = new ListNode;
            new_node->next = last_node;
            new_node->val = value % 10;

            left ? left = left->next : left = nullptr;
            right ? right = right->next : right = nullptr;
            last_node = new_node;
        }

        return last_node;
    }

    ListNode* reverse_list( ListNode* source_node )
    {
        ListNode* dest_node = nullptr;

        while ( source_node != nullptr )
        {
            ListNode* new_node = new ListNode;
            new_node->val = source_node->val;
            new_node->next = dest_node;

            dest_node = new_node;

            ListNode* tmp = source_node;
            source_node = source_node->next;

            delete tmp;
        }

        return dest_node;
    }
};

int main()
{
    return 0;
}
