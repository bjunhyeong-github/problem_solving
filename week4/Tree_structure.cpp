#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// ���ο� ��� ���� �Լ�
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ���� Ʈ���� ��� �߰� �Լ�
void insert(Node*& root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return;
    }

    if (data < root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

// ���� ��ȸ(Inorder Traversal)�� ���� ����� ��� ���
void inorderTraversal(Node* root) {
    if (root == NULL)

        return ;


    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = NULL;
    int n, data;

    cout << "Ʈ���� �߰��� ����� ������ �Է��ϼ���: ";
    cin >> n;

    cout << "��带 ������� �Է��ϼ���: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insert(root, data);
    }

    cout << "Ʈ���� ����� ����� ���� ������ �����ϴ�." << endl;

    inorderTraversal(root);

    return 0;
}
