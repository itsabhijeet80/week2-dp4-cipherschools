#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerToTheLeft(vector<int> &heights)
{
    int len = heights.size();
    vector<int> nsl(len);
    stack<int> S;

    for (int i = 0; i < len; i++)
    {
        while (!S.empty() && heights[S.top()] >= heights[i])
        {
            S.pop();
        }
        nsl[i] = (S.empty() ? -1 : S.top());
        S.push(i);
    }
    return nsl;
}
vector<int> nextSmallerToTheRight(vector<int> heights)
{
    int len = heights.size();
    vector<int> nsr(len);
    stack<int> S;

    for (int i = len - 1; i >= 0; i--)
    {
        while (!S.empty() && heights[S.top()] >= heights[i])
        {
            S.pop();
        }
        nsr[i] = (S.empty() ? len : S.top());
        S.push(i);
    }
    return nsr;
}

int largestRectangleArea(vector<int> &heights)
{

    vector<int> left = nextSmallerToTheLeft(heights);
    vector<int> right = nextSmallerToTheRight(heights);
  
    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int width = (right[i] - 1) - (left[i] + 1) + 1;
        maxArea = max(maxArea, width * heights[i]);
    }
    return maxArea;
}

int main()
{

    return 0;
}