//2+3+4*5-6/7+9
#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;
TreeNode n1 = { 4,NULL,NULL };
TreeNode n2 = { 5,NULL,NULL };
TreeNode n3 = { (int)'*',&n1,&n2};
TreeNode n4 = { 3,NULL,NULL };
TreeNode n5 = { (int)'+',&n4,&n3};
TreeNode n6 = { 2,NULL,NULL };
TreeNode n7 = { (int)'+',&n6,&n5};
TreeNode n8 = { (int)'+',&n4,&n5};
TreeNode n9 = { 6,NULL,NULL };
TreeNode n10 = { 7,NULL,NULL };
TreeNode n11 = { (int)'/',&n9,&n10};
TreeNode n12 = { (int)'-',&n8, &n11 };
TreeNode n13 = { 9,NULL,NULL };
TreeNode n14 = { (int)'+',&n12,&n13};
TreeNode* exp = &n14;

int evaluate(TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;
	else {
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		printf("%d &c %d = ", op1, root->data, op2);
		switch (root->data) {
		case'+':
			return op1 + op2;
		case'-':
			return op1 - op2;
		case'*':
			return op1 * op2;
		case'/':
			return op1 / op2;
		}
	}
	return 0;
}

int main(void)
{
	evaluate(&n1);
	printf("수식의 값은 %d입니다.\n", evaluate(exp));

	return 0;
}