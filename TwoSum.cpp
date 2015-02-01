#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> tmp;
		vector<int> result;
        for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
		{
			if (*it <= target)
				tmp.push_back(*it);
		}
		sort(tmp.begin(), tmp.end());
		for (int i = 0; i < tmp.size(); ++i)
			for (int j = i; j < tmp.size(); ++j)
			{
				if (tmp.at(i) + tmp.at(j) == target)
				{
					cout << "index1 = " << i+1 << "; index2 = " << j+1 << endl;
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		return result;
    }
};

int main()
{
	Solution a;
	vector<int> inputVec {2, 7, 11, 15};
	int target = 9;
	a.twoSum(inputVec, target);
	return 0;
}
