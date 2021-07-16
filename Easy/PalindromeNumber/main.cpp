#include <iostream>
#include <string>
#include <algorithm>

/**
 * Given an integer x, return true if x is palindrome integer.
 * An integer is a palindrome when it reads the same backward as forward.
 * For example, 121 is palindrome while 123 is not.class Solution
*/
{
	public:
		bool isPalindrome(int x)
		{
			std::string str = std::to_string(x);

			const auto size = str.size();
			for (auto i = 0; i < size / 2; ++i)
				if (str[i] != str[size - i - 1])
					return false;

			return true;
		}
};

int main()
{
	return 0;
}
