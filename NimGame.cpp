
//u are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.
//
//Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.
//
//For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.


// 只要玩家可以选择1-3颗石头，所以如果对方那轮如果剩4个的话则必胜，否则失败;

class Solution {
	public:
	bool canWinNim(int n) {
		if (n < 4) return true;
		if (n == 4) return false;

		return n%4 > 0;
	}
};
