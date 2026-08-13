// Last updated: 13/08/2026, 10:09:05
// i don't the solution of this problem
1class Solution {
2private:
3    struct Node {char leftChar; char rightChar; int length; int prefix; int suffix; int best;
4};
5    vector<Node> tree;
6    Node mergeNodes(const Node& left, const Node& right) {
7        Node res;
8
9        res.leftChar = left.leftChar;
10        res.rightChar = right.rightChar;
11        res.length = left.length + right.length;
12
13        res.prefix = left.prefix;
14
15        if (
16            left.rightChar == right.leftChar &&
17            left.prefix == left.length
18        ) {
19            res.prefix = left.length + right.prefix;
20        }
21
22        res.suffix = right.suffix;
23
24        if (
25            left.rightChar == right.leftChar &&
26            right.suffix == right.length
27        ) {
28            res.suffix = right.length + left.suffix;
29        }
30
31        res.best = max(left.best, right.best);
32
33        if (left.rightChar == right.leftChar) {
34            res.best = max(
35                res.best,
36                left.suffix + right.prefix
37            );
38        }
39
40        return res;
41    }
42
43    void build( int node, int start, int end, const string& s
44    ) {
45        if (start == end) {
46            tree[node] = {s[start], s[start], 1, 1, 1, 1};
47            return;
48        }
49
50        int mid = (start + end) / 2;
51
52        build(node * 2, start, mid, s);
53        build(node * 2 + 1, mid + 1, end, s);
54
55        tree[node] = mergeNodes(
56            tree[node * 2],
57            tree[node * 2 + 1]
58        );
59    }
60
61    void update( int node, int start, int end, int index, char ch ) {
62        if (start == end) {
63            tree[node] = {ch, ch, 1, 1, 1, 1};
64            return;
65        }
66
67        int mid = (start + end) / 2;
68
69        if (index <= mid) {
70            update(node * 2, start, mid, index, ch);
71        } else {
72            update(node * 2 + 1, mid + 1, end, index, ch);
73        }
74
75        tree[node] = mergeNodes(
76            tree[node * 2],
77            tree[node * 2 + 1]
78        );
79    }
80
81public:
82    vector<int> longestRepeating( string s, string queryCharacters, vector<int>& queryIndices) {
83        int n = s.size();
84        tree.resize(4 * n);
85        build(1, 0, n - 1, s);
86        vector<int> answer;
87
88        for (int i = 0; i < queryIndices.size(); i++) {
89            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
90            answer.push_back(tree[1].best);
91        }
92
93        return answer;
94    }
95};