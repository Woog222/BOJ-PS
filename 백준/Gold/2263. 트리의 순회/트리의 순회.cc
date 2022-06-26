#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

class Node{ // null node = 0
	public:
	int val;
	int left;
	int right;
	Node(int a=0, int b=0, int c=0) : val(a), left(b), right(c) {}
};

int n;
Node tree[100001];

void make_tree(vector<int> &post, vector<int> &in, 
			  pair<int,int> post_boundary, pair<int,int> in_boundary)
{	
	int size = post_boundary.second - post_boundary.first +1;
	/* Basis Case (leaf node ) */
	if (size == 1)
	{
		int val = post[post_boundary.first];
		tree[ val ] = Node(val,0,0);
		return;
	}
	else if (size<=0) return;
		
	int root = post[post_boundary.second];
	int root_idx_inorder;
	for (int i = in_boundary.first; i<=in_boundary.second; ++i)
	{
		if (in[i] == root) {
			root_idx_inorder = i; break;
		}
	}
	int left_size, right_size, left_node, right_node;
	if ( ( left_size = root_idx_inorder - in_boundary.first ) > 0 )
		left_node = post[post_boundary.first+left_size-1];
	else
		left_node = 0;
	if (  (right_size = in_boundary.second - root_idx_inorder) > 0 ) 
		right_node = post[post_boundary.second-1];
	else
		right_node = 0;
	
	/*
	cout << "\nroot, root_inorder_idx : " << root << " "<< root_idx_inorder << '\n';
	cout << "post_boundary: "<<post_boundary.first<<", "<<post_boundary.second<<endl;
	cout << "in_boundary: "<<in_boundary.first<<", "<<in_boundary.second<<endl;
	cout << "size : " << left_size <<", " << right_size<<endl;
	cout << "branches : "<<left_node <<", "<<right_node<<endl;
	*/
	//for(int i=0; i<100000000; i++);
	
	tree[root] = Node(root, left_node, right_node);
		
	
	// left
	//cout << root << "-> left:\n"; 
	make_tree(post, in, 
		make_pair(post_boundary.first, post_boundary.first+left_size-1), 
		make_pair(in_boundary.first, root_idx_inorder-1)
			 );
	// right
	//cout << root << "-> right:\n"; 
	make_tree(post, in, 
		make_pair(post_boundary.first+left_size, post_boundary.second-1), 
		make_pair(root_idx_inorder+1, in_boundary.second)
			 );
			 
} 

void free_order(Node tr[], int root)
{
	if (root==0) return;
	
	Node node = tr[root];
	cout << node.val <<" ";
	free_order(tr, node.left);
	free_order(tr, node.right);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	vector<int> in_order(n+1,0);
	vector<int> post_order(n+1,0);	
	for (int i=1; i<=n; i++)
		cin >> in_order[i];
	for (int i=1; i<=n; i++)
		cin >> post_order[i];
	

	
	
	int root = post_order[n];

	
	make_tree(post_order, in_order, make_pair(1,n), make_pair(1,n));

	
	free_order(tree, root);
}