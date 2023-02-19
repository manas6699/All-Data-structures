// string fractionToDecimal(int numerator, int denominator) {

// 	   string ans;
//     int q = numerator/denominator;
//     ans = to_string(q);
//     int r = numerator%denominator;
//     if(r==0){
//         return ans;
//     }
//     else{
//         ans+='.';
//         unordered_map<int,int> rwp;
//         while(r!=0){
//             if(rwp.count(r)){
//                 ans.insert(rwp[r],"(");
//                 ans+=')';
//                 return ans;
//             }
//             rwp[r]=ans.length();
//             r*=10;
//             q = r/denominator;
//             ans+=to_string(q);
//             r%=denominator;
//         }
//     }

// 	}