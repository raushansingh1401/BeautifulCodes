//https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int len(s.length()),openPar(0);

        for(int i=0; i<len ;i++){
            if(s[i]=='(') openPar++;
            else if(s[i]==')'){
                if(openPar == 0){
                    s[i]='*';
                }else{
                    openPar--;
                }
            } 
        }

        int j = len-1;
        while(openPar>0 && j>=0){
            if(s[j]=='('){
                s[j] = '*';
                openPar--;
            }
            j--;
        }

        string res="";

        for(int i=0 ;i<len ;i++){
            if(s[i]!='*') res += s[i];
        }

        return res;
    }
};