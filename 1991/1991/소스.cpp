#include <iostream>

using namespace std;



class tree {
	class node {
		tree* arrive=NULL;
	public:
		void setpos(tree* arrival) {
			arrive = arrival;
		}
		tree* getnext() {
			return arrive;
		}
	};
	node left, right;
	char value;
public:
	void addNode(tree* array,char l, char r) {
		if(l!='.') left.setpos(array+l-'A');
		if(r!='.') right.setpos(array+r-'A');
	}
	void displayvalue() {
		printf("%c", value + 'A');
	}
	void setvalue(char value) {
		this->value = value;
	}
	//전위순회
	void zen() {
		displayvalue();
		if (left.getnext() != NULL)left.getnext()->zen();
		if (right.getnext() != NULL)right.getnext()->zen();
	}
	//중위순회
	void middle() {
		if (left.getnext() != NULL)left.getnext()->middle();
		displayvalue();
		if (right.getnext() != NULL)right.getnext()->middle();
	}
	//후위순회
	void hu() {
		if (left.getnext() != NULL)left.getnext()->hu();
		if (right.getnext() != NULL)right.getnext()->hu();
		displayvalue();

	}
};



int main() {
	int time;
	cin >> time;
	tree trees[26];
	for (char i = 0; i < 26; i++) {
		trees[i].setvalue(i);
	}
	while (time--) {
		char a, b, c;
		cin >> a >> b >> c;
		trees[a-'A'].addNode(trees,b, c);
	}
	trees[0].zen();
	cout << "\n";
	trees[0].middle();
	cout << "\n";
	trees[0].hu();
}