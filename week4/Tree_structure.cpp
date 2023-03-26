#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// 새로운 노드 생성 함수
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 이진 트리에 노드 추가 함수
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

// 중위 순회(Inorder Traversal)를 통해 저장된 노드 출력
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

    cout << "트리에 추가할 노드의 개수를 입력하세요: ";
    cin >> n;

    cout << "노드를 순서대로 입력하세요: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insert(root, data);
    }

    cout << "트리에 저장된 노드의 값은 다음과 같습니다." << endl;

    inorderTraversal(root);

    return 0;
}
