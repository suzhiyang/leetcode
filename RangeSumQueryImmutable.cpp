class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i)
            if (i > 0) sum.push_back(sum.back() + nums[i]);
            else sum.push_back(nums[0]);
    }

    int sumRange(int i, int j) {
        return i == 0 ? sum[j]:sum[j] - sum[i - 1];
    }
};
