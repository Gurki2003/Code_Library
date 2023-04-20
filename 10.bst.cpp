#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void level_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

void kth_level_sum(struct Node *root, int k) // the sum of all the nodes at a level of a binary tree
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (level == k)
            {
                sum += node->data;
            }
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
    cout << sum;
}

int no_nodes(struct Node *root) // number of nodes in a binary tree
{
    static int count = 0;

    if (root != NULL)
    {
        no_nodes(root->left);
        no_nodes(root->right);
        count++;
    }
    return count;
}

int sum_of_nodes(struct Node *root) // sum of all the nodes
{

    if (root == NULL)
    {
        return 0;
    }
    return sum_of_nodes(root->left) + sum_of_nodes(root->right) + root->data;
}

int height(struct Node *root) // the distance bw the root and the last leaf
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight, rheight) + 1;
}

int cal_diameter(struct Node *root) // the largest distance between any 2 nodes
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    int currdiameter = lheight + rheight + 1;

    int ldiameter = cal_diameter(root->left);
    int rdiameter = cal_diameter(root->right);

    return max(currdiameter, max(ldiameter, rdiameter));
}

void sum_replace(Node *root) // adding the data of the children to the parents
{
    if (root == NULL)
    {
        return;
    }
    sum_replace(root->left);
    sum_replace(root->right);

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

bool isbalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (isbalanced(root->left) == false)
    {
        return false;
    }
    if (isbalanced(root->right) == false)
    {
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Right_view(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == n - 1)
            {
                cout << curr->data << " ";
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

void Left_view(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == 0)
            {
                cout << curr->data << " ";
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}


void flatten(struct Node* root)
{
    
    if(root==NULL || root->left==NULL || root->right==NULL)
    {
        return;
    }
    if(root->left!=NULL)
    {
        flatten(root->left);
        Node* temp = root->right;
        root->right=root->left;
        Node* t = root->right;
        while(t->right!=NULL)
        {
            t=t->right;
        }

    }
    flatten(root->right);
}

void heighest_comm_ans(Node* root,int k1, int k2)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data>=k1 && root->data<=k2)
    {
        cout<<root->data;
        exit(0);
    }
    if(root->data > k1 && root->data> k2)
    {
        heighest_comm_ans(root->left,k1,k2);
    }
    if(root->data<k1 && root->data <k2)
    {
        heighest_comm_ans(root->right,k1,k2);
    }
}

int main()
{
    struct Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout << "Inorder : ";
    inorder(root);
    cout << endl;
    cout << "Preorder : ";
    preorder(root);
    cout << endl;
    cout << "Postorder : ";
    postorder(root);
    cout << endl;
    cout << "Level order : ";
    level_order(root);
    cout << endl;
    cout << "Kth level sum: ";
    kth_level_sum(root, 1);
    cout << endl;
    cout << "Number of nodes :";
    cout << no_nodes(root);
    cout << endl;
    cout << "Sum of all nodes :";
    cout << sum_of_nodes(root);
    cout << endl;
    cout << "The height of the tree is : " << height(root);
    cout << endl;
    cout << "The diameter of the tree is : " << cal_diameter(root) << endl;

    // sum_replace(root);
    // cout<<endl;
    // level_order(root);
    cout << "is the tree balanced : " << isbalanced(root) << endl;
    cout << "The left view of the tree is : ";
    Left_view(root);
    cout << endl;
    cout << "The right view of the tree is : ";
    Right_view(root);
    cout << endl;
    flatten(root);
    preorder(root);
    //heighest_comm_ans(root,4,14);
}