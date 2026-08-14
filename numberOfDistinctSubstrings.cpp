class Node{
    public:
        Node* links[26] = {nullptr};
        bool containsKey(char ch){
            return (links[ch-'a']!=nullptr);
        }

        Node* get(char ch){
            return links[ch-'a'];
        }

        void put(char ch, Node* node){
            links[ch-'a'] = node;
        }
};

class Solution{	
	public:
		int countDistinctSubstring(string s){
            int n = s.size();
            int cnt = 0;
            Node* root = new Node();
            for(int i=0;i<n;i++){
                Node* node = root;
                for(int j=i;j<n;j++){
                    if(!node->containsKey(s[j])){
                        cnt++;
                        node->put(s[j],new Node());
                    }
                    node = node->get(s[j]);
                }
            }

            return cnt+1;

		}
};