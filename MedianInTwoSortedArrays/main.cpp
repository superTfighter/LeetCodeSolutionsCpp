#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> uni = this->unionVector(nums1, nums2);

        return this->calculateMedian(uni);
    }

private:
    vector<int> unionVector(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> newVector;

        int size1 = nums1.size();
        int size2 = nums2.size();

        int i = 0;
        int j = 0;

        while (i < size1 && j < size2)
        {
            if (nums1[i] < nums2[j])
            {
                newVector.push_back(nums1[i++]);
            }
            else if (nums2[j] < nums1[i])
            {
                newVector.push_back(nums2[j++]);
            }
            else
            {
                newVector.push_back(nums1[i++]);
                newVector.push_back(nums2[j++]);
            }
        }

        while (i < size1)
            newVector.push_back(nums1[i++]);

        while (j < size2)
            newVector.push_back(nums2[j++]);

        return newVector;
    }

    double calculateMedian(vector<int> &nums)
    {
        int size = nums.size();

        if (size > 0)
        {
            if (size % 2 == 0)
            {
                return (nums[size / 2 - 1] + nums[size / 2]) / 2.0;
            }
            else
            {
                return nums[size / 2];
            }
        }

        return size;
    }
};

int main()
{
    vector<int> nums1 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4};
    vector<int> nums2 = {1, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4};

    Solution s;

    double median = s.findMedianSortedArrays(nums1, nums2);

    std::cout << "Median: " << median << std::endl;

    return 0;
}