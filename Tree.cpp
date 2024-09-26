/*
====================================================
Tree : Node�� �̷������ ���� �ڷᱸ��
- �������� �ڷḦ ��Ÿ���� �� ���� ����ϴ� �ڷᱸ��
- �θ� Node�� ���� �ڽ� Node�� ���� �� �ִ� �ϴ�� ����
- �� Node���� ����Ͽ� �ٽ� �ڱ� �ڽ��� Node�� ���ƿ��� ��ȯ ������ ������ �ʴ´�

[ Tree ���� ]
- �θ� Node : Root Node �������� ���� ����� Node
- �ڽ� Node : Root Node �ݴ� �������� ���� ����� Node

- �Ѹ�(Root) : �θ� Node�� ���� �ֻ��� Node. Tree�� depth 0 �� �ϳ��� ����
- ����(Branch) : �θ� Node�� �ڽ� Node�� ��� �ִ� Node. Tree�� �߰��� ����
- ��(Leaf) : �ڽ� Node�� ���� Node. Tree�� ���� ����

- ���� : ��� Node���� ���� Node���� ��ġ�� ��
- ����(depth) : Root Node�κ����� ����
- ���� : �ڽ� Node�� ����

[ �뵵 ]
- �ַ� ���� ������ ���� �� �ִ� �ڷᳪ ȿ������ �˻��� ���� ���
	ex)	�������� ��������, ������ ����, DB, �˻������� ���� ���
		���� ��ų�� ����� ������ų�� ��� �� �ִ� ��ųƮ��

[ Tree ���� ]
- Node�� ������� �θ� Node�� �ڽ� Node�� ������ �� �ֵ��� ����

[ BinaryTree : ����Tree ]
- �θ� Node�� �ڽ� Node�� �ִ� 2�������� ���� �� �ִ� Tree

[ BinaryTree�� ��ȸ ��� ]
- Tree�� �������� �ڷᱸ���̱� ������ ���������� ó���ϱ� ���� ��ȸ�� ���� ��Ģ�� �ִ�.

   A
 B   C
D E F G

1. ������ȸ(PreOrder)	: Node, ����, ������ - A,(B,D,E),(C,F,G) -> A,B,D,E,C,F,G	��������
2. ������ȸ(InOrder)		: ����, Node, ������ - D,B,E,A,F,C,G		���ں�
3. ������ȸ(PostOrder)	: ����, ������, Node - D,E,B,F,G,C,A		�ں���
====================================================
*/
#include<iostream>
using namespace std;

template<typename T>
class BinaryTree {
public:
	struct Node;

	// Root Node ��ȯ
	Node* Root() {
		return root;
	}

	BinaryTree(T data) {
		root = new Node(data);
	}
	~BinaryTree();

	// ���� �ڽ� Node �߰�
	Node* AddLeft(Node* parent, T data) {
		// �̹� ���ʿ� �ڽ��� �ִٸ�?
		if (parent->left != nullptr) {
			cout << "�̹� ���ʿ� �ڽ��� �ִ�.\n";
			return nullptr;
		}
		// ���ο� Node�� ����� �θ� Node ���ʿ� ����
		parent->left = new Node(data);
		// �θ� �������ְ�
		parent->left->parent = parent;
		return parent->left;
	}
	// ������ �ڽ� Node �߰�
	Node* AddRight(Node* parent, T data) {
		if (parent->right != nullptr) {
			cout << "�̹� �����ʿ� �ڽ��� �ִ�.\n";
			return nullptr;
		}
		parent->right = new Node(data);
		parent->right->parent = parent;
		return parent->right;
	}
	void deleteTree(Node* node) {
		if (node == nullptr)return;
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}

	// ���(����)
	void PrintInOrder(Node* node) {
		if (node == nullptr)return;
		PrintInOrder(node->left);
		cout << node->data << " ";
		PrintInOrder(node->right);
	}
	// ���(����)
	void PrintPreOrder(Node* node) {
		if (node == nullptr)return;
		cout << node->data << " ";
		PrintPreOrder(node->left);
		PrintPreOrder(node->right);
	}
	// ���(����)
	void PrintPostOrder(Node* node) {
		if (node == nullptr)return;
		PrintPostOrder(node->left);
		PrintPostOrder(node->right);
		cout << node->data << " ";
	}
private:
	struct Node {
		T data;			// ����� ������
		Node* parent;	// �θ�
		Node* left;		// ���� �ڽ�
		Node* right;	// ������ �ڽ�

		Node(T data) :data(data), parent(nullptr), left(nullptr), right(nullptr) {}
	};
	Node* root;			// Root Node
};

int main() {
	// Root Node 20¥�� ����
	BinaryTree<int>* tree = new BinaryTree<int>(20);
	BinaryTree<int>::Node* node = nullptr;

	node = tree->AddLeft(tree->Root(), 30);
	tree->AddLeft(node, 100);
	tree->AddRight(node, 200);

	node = tree->AddRight(tree->Root(), 40);
	tree->AddLeft(node, 400);
	tree->AddRight(node, 2000);

	tree->PrintInOrder(tree->Root());
}