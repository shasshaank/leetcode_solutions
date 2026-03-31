class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>targetCount;
        for(char c:t){
            targetCount[c]++;
        }
        unordered_map<char,int>windowCount;
        int left = 0, right = 0;
        int required = targetCount.size();
        int formed = 0;
        int minLen = -1,startIdx = 0;
        while(right<s.length()){
            char c = s[right];
            windowCount[c]++;
            if(targetCount.count(c) && windowCount[c]==targetCount[c]){
                formed++;
            }
            while(left<=right && formed==required){
                c = s[left];
                if(minLen == -1 || right-left+1<minLen){
                    minLen = right - left+1;
                    startIdx = left;
                }

                windowCount[c]--;
                if(targetCount.count(c) && windowCount[c]<targetCount[c]){
                    formed--;
                }
                left++;
            }

            right++;
        }

        return minLen == -1 ?"":s.substr(startIdx,minLen);
    }


};