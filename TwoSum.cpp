#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	int value;
	int index;
	node(int val, int idx):value(val), index(idx){}
};

bool compare(node n1, node n2){
	return n1.value < n2.value;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
			vector<node> tmp;
		vector<int> result;
		for (size_t idx = 0; idx < numbers.size(); ++idx) { 
			tmp.push_back(node(numbers.at(idx), idx+1));
		}

		sort(tmp.begin(), tmp.end(), compare);
		int i = 0, j = tmp.size()-1;
		while (i < j)
		{
			int sum = tmp[i].value + tmp[j].value;
			if (sum == target)
			{
			    if (tmp[i].index < tmp[j].index) {
			    	result.push_back(tmp[i].index);
			    	result.push_back(tmp[j].index);
		    	} else {
                    result.push_back(tmp[j].index);
                    result.push_back(tmp[i].index);
		    	}
				return result;
			}

			if (sum > target)
				j--;
			else 
				i++;
		}
		return result;
	}
};

int main()
{
	Solution a;
	int input[] = {3,2,4};
	vector<int> inputVec; /* {-3, 7, 3, 15};*/
	for (int i= 0; i < sizeof(input)/sizeof(int); ++i)
	{
		inputVec.push_back(input[i]);
	}
	int target = 6;
	vector<int> idx = a.twoSum(inputVec, target);

	for (vector<int>::iterator it = idx.begin(); it != idx.end(); ++it)
		cout << *it << endl;
	
	cin >> target; 
	return 0;
}

