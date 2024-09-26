/*
====================================================
Tree : Node로 이루어지는 비선형 자료구조
- 계층적인 자료를 나타내는 데 자주 사용하는 자료구조
- 부모 Node가 여러 자식 Node를 가질 수 있는 일대다 구조
- 한 Node에서 출발하여 다시 자기 자신의 Node로 돌아오는 순환 구조를 가지지 않는다

[ Tree 구성 ]
- 부모 Node : Root Node 방향으로 직접 연결된 Node
- 자식 Node : Root Node 반대 방향으로 직접 연결된 Node

- 뿌리(Root) : 부모 Node가 없는 최상위 Node. Tree의 depth 0 에 하나만 존재
- 가지(Branch) : 부모 Node와 자식 Node가 모두 있는 Node. Tree의 중간에 존재
- 잎(Leaf) : 자식 Node가 없는 Node. Tree의 끝에 존재

- 길이 : 출발 Node에서 도착 Node까지 거치는 수
- 깊이(depth) : Root Node로부터의 길이
- 차수 : 자식 Node의 개수

[ 용도 ]
- 주로 계층 구조를 가질 수 있는 자료나 효율적인 검색에 많이 사용
	ex)	윈도우의 폴더구조, 문서의 목차, DB, 검색엔진의 구조 등등
		상위 스킬을 배워야 하위스킬을 배울 수 있는 스킬트리

[ Tree 구현 ]
- Node를 기반으로 부모 Node와 자식 Node를 보관할 수 있도록 구성

[ BinaryTree : 이진Tree ]
- 부모 Node가 자식 Node를 최대 2개까지만 가질 수 있는 Tree

[ BinaryTree의 순회 방법 ]
- Tree는 비선형적인 자료구조이기 때문에 순차적으로 처리하기 위해 순회에 대한 규칙이 있다.

   A
 B   C
D E F G

1. 전위순회(PreOrder)	: Node, 왼쪽, 오른쪽 - A,(B,D,E),(C,F,G) -> A,B,D,E,C,F,G	부자자자
2. 중위순회(InOrder)		: 왼쪽, Node, 오른쪽 - D,B,E,A,F,C,G		자자부
3. 후위순회(PostOrder)	: 왼쪽, 오른쪽, Node - D,E,B,F,G,C,A		자부자
====================================================
*/
#include<iostream>
using namespace std;

template<typename T>
class BinaryTree {
public:
	struct Node;

	// Root Node 반환
	Node* Root() {
		return root;
	}

	BinaryTree(T data) {
		root = new Node(data);
	}
	~BinaryTree();

	// 왼쪽 자식 Node 추가
	Node* AddLeft(Node* parent, T data) {
		// 이미 왼쪽에 자식이 있다면?
		if (parent->left != nullptr) {
			cout << "이미 왼쪽에 자식이 있다.\n";
			return nullptr;
		}
		// 새로운 Node를 만들고 부모 Node 왼쪽에 연결
		parent->left = new Node(data);
		// 부모를 설정해주고
		parent->left->parent = parent;
		return parent->left;
	}
	// 오른쪽 자식 Node 추가
	Node* AddRight(Node* parent, T data) {
		if (parent->right != nullptr) {
			cout << "이미 오른쪽에 자식이 있다.\n";
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

	// 출력(중위)
	void PrintInOrder(Node* node) {
		if (node == nullptr)return;
		PrintInOrder(node->left);
		cout << node->data << " ";
		PrintInOrder(node->right);
	}
	// 출력(전위)
	void PrintPreOrder(Node* node) {
		if (node == nullptr)return;
		cout << node->data << " ";
		PrintPreOrder(node->left);
		PrintPreOrder(node->right);
	}
	// 출력(후위)
	void PrintPostOrder(Node* node) {
		if (node == nullptr)return;
		PrintPostOrder(node->left);
		PrintPostOrder(node->right);
		cout << node->data << " ";
	}
private:
	struct Node {
		T data;			// 저장될 데이터
		Node* parent;	// 부모
		Node* left;		// 왼쪽 자식
		Node* right;	// 오른쪽 자식

		Node(T data) :data(data), parent(nullptr), left(nullptr), right(nullptr) {}
	};
	Node* root;			// Root Node
};

int main() {
	// Root Node 20짜리 생성
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