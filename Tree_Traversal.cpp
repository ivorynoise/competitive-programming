#include <iostream>
#include <vector>
#include <list>

using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

TreeNode *getRightMostNode(TreeNode *node, TreeNode *curr)
{
    while (node->right != nullptr && node->right != curr)
    {
        node = node->right;
    }

    return node;
}

 
class BSTIterator
{
private:
    list<TreeNode *> st;

public:
    BSTIterator(TreeNode *root)
    {
        insertAllLeft(root);
    }

private:
    void insertAllLeft(TreeNode *node)
    {
        while (node != nullptr)
        {
            st.push_front(node);
            node = node->left;
        }
    }

public:
    int next()
    {
        TreeNode *rn = st.front();
        st.pop_front();
        insertAllLeft(rn->right);
        return rn->val;
    }

    bool hasNext()
    {
        return st.size() != 0;
    }
};

TreeNode *cdll(TreeNode *root)
{
    TreeNode *dummy = new TreeNode(-1);
    TreeNode *curr = root, *prev = dummy;
    while (curr != nullptr)
    {
        TreeNode *left = curr->left;
        if (left == nullptr)
        {
            prev->right = curr;
            curr->left = prev;
            prev = prev->right;

            curr = curr->right;
        }
        else
        {
            TreeNode *rightMostNode = getRightMostNode(left, curr);
            if (rightMostNode->right == nullptr)
            {
                rightMostNode->right = curr;
                curr = curr->left;
            }
            else
            {

                rightMostNode->right = nullptr;

                prev->right = curr;
                curr->left = prev;
                prev = prev->right;

                curr = curr->right;
            }
        }
    }

    TreeNode *head = dummy->right;
    dummy->right = head->left = nullptr;

    // for circular doubly linkedlist
    head->left = prev;
    prev->right = head;

    return head;
}
