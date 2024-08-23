class Solution {
public:
    string fractionAddition(string expression) {
        int nume=0,deno=1;

        int i=0;
        int n=expression.size();

        while(i<n){
            int curnume=0,curdeno=0;

            bool isneg=(expression[i]=='-');

            if(expression[i]=='+' || expression[i]=='-'){
                i++;
            }

            //current numerator

            while(i<n && isdigit(expression[i])){
                int val=expression[i]-'0';
                curnume=(curnume*10)+val;
                i++;
            }

            i++;

            if(isneg==true){
                curnume=curnume*-1;
            }

            while(i<n && isdigit(expression[i])){
                int val=expression[i]-'0';
                curdeno=(curdeno*10)+val;
                i++;
            }

            nume=nume*curdeno+curnume*deno;
            deno=deno*curdeno;
        }

        int gcd=abs(__gcd(nume,deno));

        nume=nume/gcd;
        deno=deno/gcd;

        return to_string(nume)+"/"+to_string(deno);
    }
};