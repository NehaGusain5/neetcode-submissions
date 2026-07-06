class Solution {
public:
        
    int calc(int a,int b,string opr){
        if(opr=="+"){
            return a+b;
        }
        if(opr=="-"){
            return b-a;
        }
        if(opr=="*"){
            return a*b;
        }
        return b/a;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(calc(a,b,tokens[i]));

            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();

        
    }
};