#include <iostream>

using namespace std;

struct TreeNode
{
	char left, right;
};

TreeNode node[26];

void preorder(int num)
{
	cout << (char)(num + 'A');
	if (node[num].left != -1)
		preorder((int)(node[num].left - 'A'));
	if (node[num].right != -1)
		preorder((int)(node[num].right - 'A'));
}

void inorder(int num)
{
	if (node[num].left != -1)
		inorder((int)(node[num].left - 'A'));
	cout << (char)(num + 'A');
	if (node[num].right != -1)
		inorder((int)(node[num].right - 'A'));
}

void postorder(int num)
{

	if (node[num].left != -1)
		postorder((int)(node[num].left - 'A'));
	if (node[num].right != -1)
		postorder((int)(node[num].right - 'A'));	
	cout << (char)(num + 'A');
}

int main()
{
	int n;
	cin >> n;
	char tmp, tmpl, tmpr;

	for (int i = 1; i <= n; i++)
	{
		cin >> tmp >> tmpl >> tmpr;
		
		if (tmpl != '.')
			node[(int)(tmp - 'A')].left = tmpl;
		else
			node[(int)(tmp - 'A')].left = -1;

		if (tmpr != '.')
			node[(int)(tmp - 'A')].right = tmpr;
		else
			node[(int)(tmp - 'A')].right = -1;
	}

	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
	return 0;
}

