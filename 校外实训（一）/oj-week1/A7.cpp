#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义函数 threeSum 用于寻找和为目标值的三元组
vector<vector<int>> threeSum(vector<int>& nums, int target) {
    vector<vector<int>> result;  // 用于存储满足条件的三元组

    // 对输入的数组进行排序
    sort(nums.begin(), nums.end());

    // 遍历数组
    for (int i = 0; i < nums.size() - 2; i++) {
        // 如果当前数字与前一个数字相同，跳过此次循环
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;  // 左指针
        int right = nums.size() - 1;  // 右指针

        // 当左指针小于右指针时，执行以下操作
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];  // 计算当前三个数字的和

            // 如果和等于目标值
            if (sum == target) {
                // 将三元组添加到结果中
                result.push_back({ nums[i], nums[left], nums[right] });

                // 跳过左指针指向的重复数字
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                // 跳过右指针指向的重复数字
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                // 左指针右移，右指针左移，继续寻找其他可能的三元组
                left++;
                right--;
            }
            // 如果和小于目标值，左指针右移
            else if (sum < target) {
                left++;
            }
            // 如果和大于目标值，右指针左移
            else {
                right--;
            }
        }
    }

    // 返回所有找到的三元组
    return result;
}

int main() {
    int target, n;
    cin >> target >> n;  // 输入目标值和数组元素个数

    vector<int> nums(n);  // 创建存储数组元素的向量
    for (int i = 0; i < n; i++) {
        cin >> nums[i];  // 输入数组元素
    }

    vector<vector<int>> res = threeSum(nums, target);  // 调用函数获取结果

    // 输出所有满足条件的三元组
    for (const auto& triplet : res) {
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
    }

    return 0;
}