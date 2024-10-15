#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    if (nums.size() < 4)
    {
        return result;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; i++)
    {
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            int left = j + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum < target)
                {
                    left++;
                }
                else if (sum > target)
                {
                    right--;
                }
                else
                {
                    vector<int> quadruplet;
                    quadruplet.push_back(nums[i]);
                    quadruplet.push_back(nums[j]);
                    quadruplet.push_back(nums[left]);
                    quadruplet.push_back(nums[right]);
                    result.push_back(quadruplet);
                    while (left < right && nums[left] == quadruplet[2])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == quadruplet[3])
                    {
                        right--;
                    }
                }
            }
            while (j < nums.size() - 2 && nums[j] == nums[j + 1])
            {
                j++;
            }
        }
        while (i < nums.size() - 3 && nums[i] == nums[i + 1])
        {
            i++;
        }
    }
    return result;
}

int main()
{
    int target;
    int n;
    cin >> target >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<vector<int>> result = fourSum(nums, target);
    for (vector<int> &quadruplet : result)
    {
        for (int i = 0; i < quadruplet.size(); i++)
        {
            if (i < quadruplet.size() - 1)
                cout << quadruplet[i] << " ";
            else
                cout << quadruplet[i];
        }
        cout << endl;
    }
    return 0;
}