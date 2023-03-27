#include "iostream"
#include "vector"
#include "unordered_map"

class Solution
{

public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> mapSet;

        for (int i = 0; i < nums.size(); i++)
        {
            if (mapSet.find(target - nums[i]) != mapSet.end())
            {
                return { mapSet[target - nums[i]] , i };
            }
            else
            {
                mapSet[nums[i]] = i;
            }
            
        }

        return {};
    };
};

int main()
{
    Solution s;

    std::vector<int> nums = {2, 7, 11, 15};

    std::vector<int> result = s.twoSum(nums, 9);

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }

    return 0;
}
