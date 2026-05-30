class Solution {
private:
    struct SegTreeNode{
        long long rangeSum;
        long long prefMaxSum;
        long long suffMaxSum;
        long long maxSubArrSum;

        SegTreeNode(){}

        SegTreeNode(long long rs, long long ps, long long ss, long long ms){
            rangeSum = rs;
            prefMaxSum = ps;
            suffMaxSum = ss;
            maxSubArrSum = ms;
        }
    };

    void buildSegTree(int ind, int l, int r, vector<int> &arr, vector<SegTreeNode> &segTree){
        if(l == r){
            segTree[ind].rangeSum = arr[l];
            segTree[ind].prefMaxSum = max(0, arr[l]);
            segTree[ind].suffMaxSum = max(0, arr[r]);
            segTree[ind].maxSubArrSum = max(0, arr[l]);
            return;
        }

        int mid = (l + r) / 2;
        buildSegTree(2 * ind + 1, l, mid, arr, segTree);
        buildSegTree(2 * ind + 2, mid + 1, r, arr, segTree);

        segTree[ind].rangeSum = segTree[2 * ind + 1].rangeSum + segTree[2 * ind + 2].rangeSum;
        segTree[ind].prefMaxSum = max(segTree[2 * ind + 1].prefMaxSum, segTree[2 * ind + 1].rangeSum + segTree[2 * ind + 2].prefMaxSum);
        segTree[ind].suffMaxSum = max(segTree[2 * ind + 1].suffMaxSum + segTree[2 * ind + 2].rangeSum, segTree[2 * ind + 2].suffMaxSum);
        segTree[ind].maxSubArrSum = max({segTree[2 * ind + 1].maxSubArrSum, segTree[2 * ind + 2].maxSubArrSum, segTree[2 *  ind + 1].suffMaxSum + segTree[2 * ind + 2].prefMaxSum});
    }

    void pointUpdate(int ind, int l, int r, int pos, int newVal, vector<SegTreeNode> &segTree){
        if(l == r){
            segTree[ind].rangeSum = newVal;
            segTree[ind].prefMaxSum = max(0, newVal);
            segTree[ind].suffMaxSum = max(0, newVal);
            segTree[ind].maxSubArrSum = max(0, newVal);
            return;
        }

        int mid = (l + r) / 2;
        if(pos <= mid)
            pointUpdate(2 * ind + 1, l, mid, pos, newVal, segTree);
        else
            pointUpdate(2 * ind + 2, mid + 1, r, pos, newVal, segTree);

        segTree[ind].rangeSum = segTree[2 * ind + 1].rangeSum + segTree[2 * ind + 2].rangeSum;
        segTree[ind].prefMaxSum = max(segTree[2 * ind + 1].prefMaxSum, segTree[2 * ind + 1].rangeSum + segTree[2 * ind + 2].prefMaxSum);
        segTree[ind].suffMaxSum = max(segTree[2 * ind + 1].suffMaxSum + segTree[2 * ind + 2].rangeSum, segTree[2 * ind + 2].suffMaxSum);
        segTree[ind].maxSubArrSum = max({segTree[2 * ind + 1].maxSubArrSum, segTree[2 * ind + 2].maxSubArrSum, segTree[2 *  ind + 1].suffMaxSum + segTree[2 * ind + 2].prefMaxSum});
    }

    SegTreeNode getRangeMaxSubSum(int ind, int l, int r, int start, int end, vector<SegTreeNode> &segTree){
        if(l > end || r < start)
            return SegTreeNode(0, -1e17, -1e17, -1e17);

        if(l >= start && r <= end)
            return segTree[ind];

        int mid = (l + r) / 2;
        SegTreeNode leftNode = getRangeMaxSubSum(2 * ind + 1, l, mid, start, end, segTree);
        SegTreeNode rightNode = getRangeMaxSubSum(2 * ind + 2, mid + 1, r, start, end, segTree);

        return SegTreeNode(leftNode.rangeSum + rightNode.rangeSum,
                        max(leftNode.prefMaxSum, leftNode.rangeSum + rightNode.prefMaxSum),
                        max(leftNode.suffMaxSum + rightNode.rangeSum, rightNode.suffMaxSum),
                        max({leftNode.maxSubArrSum, rightNode.maxSubArrSum, leftNode.suffMaxSum + rightNode.prefMaxSum}));
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int n = queries.size();

        int max_dist = 0;
        for(int i = 0; i < n; i++){
            if(queries[i][0] == 1)
                max_dist = max(max_dist, queries[i][1]);
            else
                max_dist = max({max_dist, queries[i][1], queries[i][2]});
        }

        vector<int> arr(2 * max_dist);
        for(int i = 0; i < max_dist; i++){
            arr[2 * i] = 1;
            arr[2 * i + 1] = 0;
        }

        vector<SegTreeNode> segTree(4 * (2 * max_dist));
        buildSegTree(0, 0, 2 * max_dist - 1, arr, segTree);

        vector<bool> ans;
        for(int i = 0; i < n; i++){
            if(queries[i][0] == 1)
                pointUpdate(0, 0, 2 * max_dist - 1, 2 * queries[i][1] - 1, -1e8, segTree);
            else
                ans.push_back(queries[i][2] <= getRangeMaxSubSum(0, 0, 2 * max_dist - 1, 0, 2 * queries[i][1] - 1, segTree).maxSubArrSum);
        }

        return ans;
    }
};