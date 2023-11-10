#include <iostream>
#include <vector>

using vector_type = std::vector<int>;
//O(n^2)
vector_type twoSum(vector_type & nums, int target) {
    vector_type res = {0,0};
    for (int i = 0; i != nums.size()-1; ++i) {
        for (int j = i+1; j != nums.size(); ++j) {
            if (nums[i] + nums[j] == target)
            {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return res;
}

int main() {
    int n = 0;
    int val = 0;
    std::cin >> n;
    vector_type input;
    for (size_t i = 0; i != n; ++i)
    {
        std::cin >> val;
        input.push_back(val);
    }
    int target = 0;
    std::cin >> target;
    vector_type res = twoSum(input, target);
    std::cout << res[0] << " " << res[1] << std::endl;
    return 0;
}