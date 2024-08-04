#include<bits/stdc++.h>
using namespace std;
// summation
struct segmenttree {
	int n;
	vector<int> st;

	int build(int start, int ending, int node, vector<int> &v  ) {
		// leaf node base case
		if (start == ending) {
		    
			st[node] = v[start];
			return 1 ;
		}

        int turn {} ;
		int mid = (start + ending) / 2;


		// left subtree is (start,mid)
		turn = build(start, mid, 2 * node + 1, v );

		// right subtree is (mid+1,ending)
		build(mid + 1, ending, 2 * node + 2, v );
        
        if(turn )
		    st[node] = st[node * 2 + 1] | st[node * 2 + 2];
		else
		    st[node] = st[node * 2 + 1] ^ st[node * 2 + 2];
        
        return turn^1 ;
	}

	int query(int start, int ending, int l, int r, int node) {
		// non overlapping case
		if (start > r || ending < l) {
			return 0;
		}

		// complete overlap
		if (start >= l && ending <= r) {
			return st[node];
		}

		// partial case
		int mid = (start + ending) / 2;

		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

		return q1 + q2;
	}

	int update(int start, int ending, int node, int index, int value ) {
		// base case
		if (start == ending) {
			st[node] = value;
			return 1;
		}

        int turn {} ;
		int mid = (start + ending) / 2;
		if (index <= mid) {
			// left subtree
			turn = update(start, mid, 2 * node + 1, index, value );
		}
		else {
			// right
			turn = update(mid + 1, ending, 2 * node + 2, index, value );
		}

        if(turn )
		    st[node] = st[node * 2 + 1] | st[node * 2 + 2];
		else
		    st[node] = st[node * 2 + 1] ^ st[node * 2 + 2];
        
        return turn^1 ;
	}

	void build(vector<int> &v) {
		this->n = v.size();
		st.resize(4 * n, 0);

		build(0, n - 1, 0, v );
	}

	int query(int l, int r) {

		return query(0, n - 1, l, r , 0);
	}

	void update(int x, int y) {

		update(0, n - 1, 0, x, y);
	}
};
vector<int> solve( vector<int>a, vector<vector<int>> queries ){
    cerr << "{" ; for(auto ele : a) cerr <<  ele << "," ; cerr << "}" << endl ;
    cerr << "{" ; for(auto ele : queries) cerr << "{" << ele[0] << " ," << ele[1] << "} ,"   ; cerr << "}" << endl ;
    vector<int> ans {} ;
    segmenttree tree ;
    tree.build(a) ;
    for(const auto &query : queries){
        tree.update(query[0]-1 , query[1]) ;
        for(auto ele : tree.st) cerr <<  ele << "  " ; cerr << endl ; 
        ans.emplace_back(tree.st[0]) ;
    }
    
    return ans ;
    
}

int main() {
    solve({425,796,873,880,9,293,445,893} ,{{4 ,8}  }) ;
    return 0 ;
}