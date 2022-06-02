// 哈夫曼编码
// @Time 2022-5-27 6:58
// @Author HJL

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {  // 节点定义
	char ch;
	unsigned weight;
	Node* l;
	Node* r;
	bool operator>(const Node& other) const {
		return weight > other.weight;
	}
	Node operator+(const Node& other) {  // 重载'+'方便合并节点
		return Node{ 0,weight + other.weight,new Node(*this),new Node(other) };
	}
};

class HuffTree {
public:
	HuffTree(string text) :text(text) {
		for (const auto& c : text)
			freq[c]++;
		for (const auto& i : freq)
			huff.push({ i.first,i.second,nullptr,nullptr });
		while (huff.size() >= 2) {
			auto n1 = huff.top(); huff.pop();
			auto n2 = huff.top(); huff.pop();
			// 合并节点树
			huff.push(n1 + n2);
		}
		root = new Node(huff.top());  // 此处必须重新构造Node
		encode(this->root);
		for (auto& i : table)
			cout << i.first << " " << i.second << endl;
	};

	string encode() {
		string res;
		for (auto& c : text)
			res += table[c];
		return res;
	}

	string decode(string text) {
		string res;
		Node* cur = root;
		for (auto& c : text) {
			if (cur->ch != '\0') {
				res += cur->ch;
				cur = root;
			}
			if (c == '0')
				cur = cur->l;
			else if (c == '1')
				cur = cur->r;
			else
				throw "解码字符串编码错误！";
		}
		return res;
	}

	~HuffTree() {
		destory(root);
	}

private:
	void encode(Node* root) {
		if (root->l == nullptr && root->r == nullptr) {
			table[root->ch] = code;
			return;
		}
		code.push_back('0');
		encode(root->l);
		code.pop_back();   // 回溯
		code.push_back('1');
		encode(root->r);
		code.pop_back();   // 回溯
	}

	void destory(Node* root) {  // 递归析构
		if (root != nullptr) {
			destory(root->l);
			destory(root->r);
			delete root;
		}
	}
private:
	Node* root;
	priority_queue<Node, vector<Node>, greater<Node>> huff;  // 最小堆里的每个元素本身又是一个最大堆
	map<char, unsigned> freq;  // 频次表
	map<char, string> table;  // 编码表	
	string text;  // 原始文本
	string code;  // 辅助变量
};

int main() {
	HuffTree huff("abbcccddddeeeeeffffffggggggg");
	cout << huff.encode() << endl;
	cout << huff.decode("01100111011101001001011011011011011111111111111100000000000010101010101010");

	return 0;
}