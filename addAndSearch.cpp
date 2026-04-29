class WordDictionary {
public:
    struct Node{
        unordered_map<char,Node*> children;
        bool end = false;
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(char c:word){
            if(curr->children.find(c)==curr->children.end()){
                curr->children[c] = new Node();
            }

            curr = curr->children[c];
        }

        curr->end = true;
    }
    
    bool search(string word) {
        return searchInNode(word,0,root);
    }

    bool searchInNode(const string& word, int index,Node* curr){
        for(int i=index;i<word.size();i++){
            char c = word[i];
            if(c=='.'){
                for(auto const&[key, childNode]:curr->children){
                    if(searchInNode(word,i+1,childNode)){
                        return true;
                    }
                }

                return false;
            }else{
                if(curr->children.find(c)==curr->children.end()){
                    return false;
                }

                curr = curr->children[c];
            }
        }

        return curr->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */