// now lets understand the concept of union find
// where we keep a track of nodes connected in a graph and detect the cycles in a graph

# include <unordered_map>

using std :: unordered_map;

// lets start by defining a class where we would all the operations

class UnionFind {
    public:
        unordered_map<int, int> par_;
        unordered_map<int, int> rank_;

        UnionFind(int n) {
            // we will iterate till th number of elements in the graph
            for (int i = 1; i <= n; i++) {
                // set the initial value of the parent
                par_[i] = i;
                // and the rank to 0
                rank_[i] = 0;
            }
        }

        // lets see how we can find the element in the graph
        int find(int n) {
            // lets start with the parent at node n
            int p = par_[n];
            // if the node is not a parent/root node
            while (p != par_[p]) {
                // we will perform path compression
                par_[p] = par_[par_[p]];
                p = par_[p];
            }
            return p;
        }

        // now lets see how we can find the union by height / rank
        bool Union(int n1, int n2) {
            // we will initalize 2 variable to store root/parent of n1 and n2
            int p1 = find(n1), p2 = find(n2);
            // now we need to check if the parents are in the same union
            if (p1 == p2) {
                return false;
            }

            // now for union by rank/height there would be 3 conditions:
            // if p1 is taller
            if (rank_[p1] > rank_[p2]) {
                par_[p2] = p1;
            }
            // if p2 is taller
            else if (rank_[p2] > rank_[p1]) {
                par_[p1] = p2;
            }
            // if both are of same rank then we can just assume one to be taller than other 
            // and then increase the height
            else {
                par_[p1] = p2;
                rank_[p2] += 1;
            }
            return true;
        }
};

