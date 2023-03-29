#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

class QuickSort
{

public:
    QuickSort(int *array)
    {
        this->arr = array;
    }

    int *sort(int low, int high)
    {

        if (low < high)
        {
            int pi = this->partition(low, high);

            sort(low, pi - 1);
            sort(pi + 1, high);
        }

        return this->arr;
    }

private:
    int *arr;

    int partition(int low, int high)
    {
        int pivot = this->arr[high];
        int i = (low - 1);

        for (size_t j = low; j <= high - 1; j++)
        {
            if (this->arr[j] < pivot)
            {
                i++;
                this->swap(i, j);
            }
        }

        this->swap(i + 1, high);
        return i + 1;
    }

    void swap(int i, int j)
    {
        int helper = arr[i];
        arr[i] = arr[j];
        arr[j] = helper;
    }
};

class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        QuickSort s(satisfaction.data());

        int *data = s.sort(0, satisfaction.size() - 1);

        satisfaction = vector<int>(data, data + satisfaction.size());

        int maxSatisfaction = 0;
        int suffixSum = 0;
        for (int i = satisfaction.size() - 1; i >= 0; i--)
        {
            suffixSum += satisfaction[i];

            if (suffixSum <= 0)
                break;
                
            maxSatisfaction += suffixSum;
        }

        return maxSatisfaction;
    }
};

int main()
{

    Solution s;

    vector<int> input1 = {4, 3, 2};

    int result = s.maxSatisfaction(input1);

    std::cout << "Result: " << result << std::endl;

    return 0;
}