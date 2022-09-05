/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/

#include <algorithm>

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = std::lower_bound( std::begin( nums ), std::end( nums ), target );

        if ( it == std::end( nums ) )
        {
            it = std::upper_bound( std::begin( nums ), std::end( nums ), target );
        }

        return std::distance( std::begin( nums ), it );
    }
};

int main()
{
    return 0;
}
