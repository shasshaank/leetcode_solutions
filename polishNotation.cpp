class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>numbers;
        for(int i=0;i<tokens.size();i++){
            string token = tokens[i];
            if(token=="+"||token=="-"||token=="*"||token=="/"){
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();      
                int result;
                if(token=="+"){
                    result = a+b;
                }else if(token=="-"){
                    result = a-b;
                }else if(token=="*"){
                    result = a*b;
                }else{
                    result = a/b;
                }

                numbers.push(result);
            }else{
                numbers.push(stoi(token));
            }
        }

        return numbers.top();
    }
};