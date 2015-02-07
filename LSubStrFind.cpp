#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if (s.empty())
			return 0;
		int large_num = 1;
		int pre_large_num = 1;
		size_t bPos = 0;
		size_t ePos = 1;
		string sub; 
		while (bPos != string::npos && ePos != string::npos)		       
		{
			if (ePos >= s.size() || bPos >= s.size())
				break;

			sub = s.substr(bPos, ePos - bPos);
			size_t pos = sub.find(s.at(ePos));
			cout << sub << "  : " << pos << "end s : " << s.at(ePos) << endl;
			ePos++;
			if (pos != string::npos)
			{
				bPos = bPos + pos + 1;
				pre_large_num = large_num > pre_large_num ? large_num : pre_large_num;
				large_num = ePos - bPos;
				continue;
			}
			large_num++;
		}
		return large_num > pre_large_num ? large_num : pre_large_num;
    }
};

int main()
{
	Solution s;
	string input = "www";
	cout << input.substr(0,1) << endl;
	cout << input.substr(1,2) << endl;
	cout << input.substr(2,string::npos) << endl;
	cout << s.lengthOfLongestSubstring(input) << endl;
	return 0; 

}
