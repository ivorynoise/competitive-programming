#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

void printPostorder(struct Node* node)
{
	if (node == NULL)
		return;

	printPostorder(node->left);

	printPostorder(node->right);

	cout << node->data << " ";
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	printInorder(node->left);

	cout << node->data << " ";

	printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node)
{
	if (node == NULL)
		return;


	cout << node->data << " ";

	printPreorder(node->left);

	printPreorder(node->right);
}

void printLevelOrder(Node* root)
{
    if (root == NULL)
        return;
 
    queue<Node*> q;
 
    q.push(root);
 
    while (q.empty() == false) 
    {
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
}
 
// create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);
  
  cout << "\nLevelorder traversal of binary tree is \n";
	printLevelOrder(root);

	return 0;
}
