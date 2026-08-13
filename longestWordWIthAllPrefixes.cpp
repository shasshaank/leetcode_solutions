struct Node{
    Node* links[26] = {nullptr};
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch-'a']!=nullptr);
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};
class Trie{
    private: 
        Node* root;
    public:
        Trie(){
            root = new Node();
        }

        void insert(string word){
            Node* node = root;
            for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i],new Node());
                }
                node = node->get(word[i]);
            }
            node->setEnd();
        }

        bool checkPrefix(string word){
            Node* node = root;
            for(int i=0;i<word.size();i++){
                if(node->containsKey(word[i])){
                    node = node->get(word[i]);
                    if(node->isEnd()==false){
                        return false;
                    }
                }else{
                    return false;
                }
            }
            return true;

        }
};

class Solution {
public:
    Trie trie;
    string completeString(vector<string>& nums) {
        //your code goes here
        for(auto &it:nums){
            trie.insert(it);
        }
        string longest = "";
        for(auto &it:nums){
            if(trie.checkPrefix(it)){
                if(it.length()>longest.length()){
                    longest = it;
                }else if(it.length()==longest.length() && it<longest){
                    longest = it;;
                }
            }
        }
        if(longest==""){
            return "None";
        }
        return longest;

    }
};