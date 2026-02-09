class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        int i=0,j=0;
        string merged = "";
        while(i<l1 || j<l2){
            // string s1(1,word1[i]);
            // string s2(1,word2[j]);
            mxerged+=word1[i];
            merged+=word2[j];
            i++;
            j++;
        }

        while(i<l1){
            // string s1(1,word1[i]);
            merged+=word1[i];
            i++;
        }

        while(j<l2){
            // string s2(1,word2[j]);
            merged+=word2[j];
            j++;
        }

        return merged;
    }
};