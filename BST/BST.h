#include<iostream>
#include<string>
#include<cassert>
#include<queue>
using namespace std;

namespace BST {


	class BST {
	private:
		struct Node {
			int key;
			string value;

			Node* left;
			Node* right;

			Node(int f_key, string f_value) {
				key = f_key;
				value = f_value;
				left = NULL;
				right = NULL;
			}

			Node(Node &node) {
				key = node.key;
				value = node.value;
				left = NULL;
				right = NULL;
			}

		};

		Node* insertNode2BST(Node* node,const int f_key, const string f_value) {
			if (node == NULL) {
				count++;
				return new Node(f_key, f_value);
			}
			else if (f_key < node->key)
				node->left = insertNode2BST(node->left, f_key, f_value);
			else if (node->key < f_key)
				node->right = insertNode2BST(node->right, f_key, f_value);
			else // f_key == node->key
				node->value = f_value;

			return node;
		}
		string findNodeInBST(Node* node, int f_key) {
			if (NULL == node) {
				return "-1";
			}

			if (f_key == node->key)
				return node->value;
			else if (f_key < node->key)
				return findNodeInBST(node->left, f_key);
			else // if (node->key < f_key)
				return findNodeInBST(node->right, f_key);
			
		}

		void printSubBST(Node* node) {
			if (node == NULL) return;

			printSubBST(node->left);
			cout << node->key << ": " << node->value<< endl;
			printSubBST(node->right);
			
		}

		Node minN(Node* node) {
			if (node->left == NULL) {
				Node resNode(node->key, node->value);
				return resNode;
			}
			else if (node->left != NULL)
				return minN(node->left);
		}

		Node maxN(Node* node){
			if (node->right == NULL) {
				Node resNode(node->key, node->value);
				return resNode;
			}
			else
				return maxN(node->right);
		}


		int minNodeInBST(Node* node) {
			if (node->left == NULL)
				return node->key;
			else
				return minNodeInBST(node->left);
		}

		int maxNodeInBST(Node* node) {
			if (node->right == NULL)
				return node->key;
			else
				return maxNodeInBST(node->right);
		}

		Node* deleteMinNodeInBST(Node* node) {
			if (node->left == NULL) {
				Node* nodeR = node->right;
				delete node; 
				count--;
				return nodeR;
			}
			else //node->left != NULL
				node->left = deleteMinNodeInBST(node->left);

			return node;
		}

		Node* deleteMaxInBST(Node* node) {
			if (node->right == NULL) {
				Node* nodeL = node->left;
				delete node;
				count--;
				return nodeL;
			}
			else
				node->right = deleteMaxInBST(node->right);

			return node;
		}

		bool contain(Node* node, int f_key) {
			assert(count > 0);
			if (node->key == f_key)
				return true;
			else if (f_key < node->key)
				return contain(node->left, f_key);
			else
				return contain(node->right, f_key);

			return false;
		}

		Node* deleteNodeInBST(Node* node, int f_key) {
			if (node->key == f_key) {
				if (node->right == NULL) {
					Node* nodeL = node->left;
					delete node;
					count--;
					return nodeL;
				}
				else if (node->left == NULL) {
					Node* nodeR = node->right;
					delete node;
					count--;
					return nodeR;
				}
				else if (node->left && node->right) {

					Node *newNode = new Node(maxN(node->right));
					deleteMaxInBST(node->right);
					newNode->left = node->left;
					newNode->right = node->right;

					return newNode;
				}
				else {
					delete node;
					return NULL;
				}
			}
			else if (f_key < node->key) {
				node->left = deleteNodeInBST(node->left, f_key);
			}
			else if (node->key < f_key) {
				node->right = deleteNodeInBST(node->right, f_key);
			}
			return node;
		}

	public:
		Node* root;
		int count;

		BST() {
			root = NULL;
			count = 0;
		}
		~BST() {
			//PASS
		}

		int size() {
			return count;
		}

		bool isEmpty() {
			return 0 == count;
		}

		void insertNode(int f_key, string f_value) {
			root = insertNode2BST(root, f_key, f_value);
		}

		string findNode(int f_key) {
			string res = findNodeInBST(root, f_key);
			/*if (res != "-1")
				cout << "Find key: " << f_key << " " << res << endl;
			else
				cout << "Can not find key: " << f_key << endl;*/
			return res;
		}

		void printBST() {
			printSubBST(root);
		}

		Node minN() {
			assert(count > 0);
			return minN(root);
		}

		Node maxN() {
			assert(count > 0);
			return maxN(root);
		}

		int minNode() {
			if (count > 0)
				return minNodeInBST(root);
			else
				return -1;
		}

		int maxNode() {
			if (count > 0)
				return maxNodeInBST(root);
			else
				return -1;
		}

		void deleteMin() {
			if (count <= 1) {
				root = NULL;
				count = 0;
			}else{
				root =  deleteMinNodeInBST(root);
			}
		}

		void deleteMax() {
			if (count == 0)
				root = NULL;
			else if (count == 1) {
				delete root;
				root = NULL;
			}
			else {
				root = deleteMaxInBST(root);
			}

		}

		bool contain(int f_key) {
			return contain(root, f_key);
		}

		void deleteNode(int f_key) {
			assert(contain(f_key));
			root = deleteNodeInBST(root, f_key);
		}

		void printInLayer() {
			queue<Node*> q;
			q.push(root);
			cout << "Print In Layer:" << endl;
			while (!q.empty()){
				Node* node = q.front();
				q.pop();
				cout << node->key << ": " << node->value << endl;

				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
		}
	};

}


namespace BST2 {
	class BST {
	private:
		struct Node {
			int key;
			string value;
			Node* left;
			Node* right;

			Node(int key, string value) {
				this->key = key;
				this->value = value;
				this->left = NULL;
				this->right = NULL;
			}

			Node(Node& node) {
				this->key = node.key;
				this->value = node.value;
				this->left = node.left;
				this->right = node.right;
			}

		};

		Node* root;
		int count;
		
		Node* insertNode(Node* node, int f_key, string f_value) {
			if (node == NULL) {
				count++;
				return new Node(f_key, f_value);
			}

			if (node->key == f_key)
				node->value = f_value;
			else if (f_key < node->key) {
				node->left = insertNode(node->left, f_key, f_value);
			}
			else
				node->right = insertNode(node->right, f_key, f_value);

			return node;
		}

		bool findNode(Node* node, int f_key) {
			if (node == NULL) return false;

			if (node->key == f_key) 
				return true;
			else if (f_key < node->key)
				return findNode(node->left, f_key);
			else
				return findNode(node->right, f_key);

		}

		void printInOrder(Node* node) {
			if (node == NULL) return;

			printInOrder(node->left);
			cout << node->key << ": " << node->value << endl;
			printInOrder(node->right);
		}

		Node* minNode(Node* node) {
			if (node->left == NULL)
				return node;
			else
				return minNode(node->left);
		}

		Node* maxNode(Node* node) {
			if (node->right == NULL)
				return node;
			else
				return maxNode(node->right);
		}

		Node* deleteMinNode(Node* node) {
			if (node->left == NULL) {
				Node* nodeR = node->right;
				delete node;
				count--;
				return nodeR;
			}
			else
				node->left = deleteMinNode(node->left);

			return node;
		}

		Node* deleteMaxNode(Node* node) {
			if (node->right == NULL) {
				Node* nodeL = node->left;
				delete node;
				count--;
				return nodeL;
			}
			else
				node->right = deleteMaxNode(node->right);

			return node;
		}

		bool contain(Node* node, int f_key) {
			assert(count > 0);
			if (node == NULL) return false;
			
			if (f_key == node->key)
				return true;
			else if (f_key < node->key)
				return contain(node->left, f_key);
			else
				return contain(node->right, f_key);

		}

		Node* deleteNode(Node* node, int f_key) {
			if (node->key == f_key) {
				if (node->left == NULL && node->right == NULL) {
					delete node;
					count--;
					node = NULL;
					return node;
				}
				else if (node->left && node->right == NULL) {
					Node* nodeL = node->left;
					count--;
					delete node;
					return nodeL;
				}
				else if (node->left == NULL && node->right) {
					Node* nodeR = node->right;
					count--;
					delete node;
					return nodeR;
				}
				else {
					Node *newNode = new Node(maxNode(node->left)->key, maxNode(node->left)->value);
					node->left = deleteMaxNode(node->left);
					newNode->left = node->left;
					newNode->right = node->right;
					return newNode;
				}
			}
			else if (f_key < node->key)
				node->left = deleteNode(node->left, f_key);
			else
				node->right = deleteNode(node->right, f_key);

			return node;
		}

	public:
		BST() {
			root = NULL;
			count = 0;
		}
		~BST() {
			while (count > 0) {
				deleteMinNode();
				count--;
			}
		}

		bool isEmpty() {
			return 0 == count;
		}
		int size() {
			return count;
		}

		void insertNode(int f_key, string f_value) {
			root = insertNode(root, f_key, f_value);
		}

		void findNode(int f_key) {
			assert(count > 0);
			if(findNode(root, f_key))
				cout << "find key " << f_key <<endl;
			else
				cout << "can not find key " << f_key << endl;
		}

		void printBST() {
			assert(count > 0);
			printInOrder(root);
		}

		Node* minNode() {
			assert(count > 0);
			return minNode(root);
		}

		Node* maxNode() {
			assert(count > 0);
			return maxNode(root);
		}

		void deleteMinNode() {
			assert(count > 0);
			if (count == 1) {
				delete root;
				root = NULL;
				count = 0;
			}
			else if (count > 1)
				root = deleteMinNode(root);
		}

		void deleteMaxNode() {
			assert(count > 0);
			if (count == 1) {
				delete root;
				count--;
				root = NULL;
			}
			else
				root = deleteMaxNode(root);
		}

		void deleteNode(int f_key) {
			assert(contain(root, f_key));
			root = deleteNode(root, f_key);
		}
	};
}