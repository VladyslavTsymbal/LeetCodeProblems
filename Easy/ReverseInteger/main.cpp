#include <iostream>
#include <string>
#include <algorithm>

/**
 * Given a signed 32-bit integer x, return x with its digits reversed.
 * If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
 * Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 */
class Solution
{
	public:
		int reverse(int x)
		{
			std::string str = std::to_string(x);

			auto beg = str.begin();
			if (str[0] == '-') ++beg;

			std::reverse(beg, str.end());

			int ret = 0;
			try
			{
				ret = std::stoi(str);
			}
			catch (...)
			{}

			return ret;
		}
};

int main()
{
	return 0;
}
