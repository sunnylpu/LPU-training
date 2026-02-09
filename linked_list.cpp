#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val, Node *next = nullptr)
    {
        this->val = val;
        this->next = next;
    }
};

Node *make_list(int size)
{
    if (size <= 0)
        return nullptr;

    // FIX: Allocate the first node on the HEAP, not the stack.
    // 'Node start' would die when this function returns.
    Node *head = new Node(0);
    Node *tail = head;

    for (int i = 1; i < size; i++)
    {
        Node *now = new Node(i * i);
        tail->next = now;
        tail = tail->next;
    }
    return head;
}

Node *reverse_recursive(Node *head)
{
    // Base case
    if (head == NULL || head->next == NULL)
        return head;

    // FIX: You need to keep track of the new head (the end of the original list)
    Node *newHead = reverse_recursive(head->next);

    // FIX: The current 'head' should become the child of its current 'next'
    head->next->next = head;
    head->next = NULL; // Crucial to prevent cycles

    return newHead;
}

// Function to prevent memory leaks
void delete_list(Node *head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // 1. Create list
    Node *head = make_list(5);

    // // 2. Print original
    cout << "Original: ";
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    // // 3. Reverse
    // head = reverse_recursive(head);

    // // 4. Print reversed
    // cout << "Reversed: ";
    // curr = head;
    // while (curr != NULL)
    // {
    //     cout << curr->val << " ";
    //     curr = curr->next;
    // }
    // cout << endl;

    // // 5. Cleanup
    // delete_list(head);

    Node *currptr = head, *nextptr = head;
    Node *prev = NULL;
    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prev;
        prev = currptr;
        currptr = nextptr;
    }
    cout << "Reversed: ";
    curr = prev;
    while (curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }

    return 0;
}
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return helper(l1, l2, 0);
    }
    ListNode *helper(ListNode *l1, ListNode *l2, int carry)
    {
        if (!l1 && !l2)
        {
            ListNode *res = NULL;
            auto curr = new ListNode(carry);
            if (carry > 0)
                res = curr;
            return res;
        }
        auto temp = new ListNode(0);
        if (!l1)
            l1 = temp;
        if (!l2)
            l2 = temp;
        int sum = (l1->val + l2->val + carry);
        auto curr = new ListNode(sum % 10);
        curr->next = helper(l1->next, l2->next, sum / 10);
        return curr;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
};
// merge k sorted lists
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        if (n == 0)
            return NULL;
        return mergeHelper(lists, 0, n - 1);
    }
    ListNode *mergeHelper(vector<ListNode *> &lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        int mid = l + (r - l) / 2;
        auto left = mergeHelper(lists, l, mid);
        auto right = mergeHelper(lists, mid + 1, r);
        return mergeTwoLists(left, right);
    }
};
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;
        if (head->next == head)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};