class Solution{
public:	
	string addBinary(string A, string B)
	{
	    // your code here
	     int n = A.length();

     int m = B.length();

     string s;

     int carry = 0,sum = 0,val = 0;

     

     while(n && m){

         sum = (A[n-1]-'0') + (B[m-1]-'0') + carry;

          val = sum % 2;

    

         s.push_back(val+'0');

         

         carry = sum/2;

         n--;

         m--;

     }

     

     while(n){

          sum = (A[n-1]-'0') + carry;

          val = sum % 2;

         s.push_back(val+'0');

         carry = sum/2;

         

         n--;

     }

     while(m){

          sum = (B[m-1]-'0') + carry;

          val = sum % 2;

         s.push_back(val+'0');

         carry = sum/2;

         m--;

     }

     if(carry!=0)

     s.push_back(carry+'0');

      reverse(s.begin(), s.end());

      string t;

     for(int i=0;i<s.length();i++){

         if(s[i]=='1'){

             for(int j=i;j<s.length();j++){

                 t.push_back(s[j]);

             }

             break;

         }

     }

     return t;
	}
};
