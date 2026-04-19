//
//  84. Largest Rectangle in Histogram.h
//  leetcodeInXcode
//
//  Created by niejikang on 19.4.26.
//  Copyright © 2026 edu.self. All rights reserved.
//

#ifndef _4__Largest_Rectangle_in_Histogram_h
#define _4__Largest_Rectangle_in_Histogram_h

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        vector<int> h = heights;
        h.push_back(0);

        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[st.top()] > h[i]) {
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }

    void Test()
    {
        vector<int> heights = {2, 1, 5, 6, 2, 3};
        cout << largestRectangleArea(heights) << endl;
    }
};

#endif /* _4__Largest_Rectangle_in_Histogram_h */