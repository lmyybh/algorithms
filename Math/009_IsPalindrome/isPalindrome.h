/*
 * 题目：9.回文数
 * 链接：https://leetcode.cn/problems/palindrome-number/
 */

// 解法：反转一半数字
// 时间复杂度：O(log(n))
// 空间复杂度：O(1)
bool isPalindrome(int x)
{
    if (x < 0 || (x != 0 && x % 10 == 0))
        return false;

    int y = 0;
    // 只翻转一半数字，可以避免溢出问题
    while (x > y)
    {
        y = 10 * y + x % 10;
        x /= 10;
    }

    // x 与 y 相等，或者 x 与 y 去掉一位相等，都是回文数字
    return x == y || x == y / 10;
}