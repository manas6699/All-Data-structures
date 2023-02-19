#include <bits/stdc++.h>
using namespace std;
// return sum , substraction , avg , multiplication

class foreplay
{
    public:
        int a , b , c , d;
};

foreplay function_main(int p , int q , int r ,int s)
{
    foreplay ans;
    ans.a = p + q + r + s;
    ans.b = (p + q) - (r + s);
    ans.c = (p + q + r + s) / 4;
    ans.d = p * q * r *s;

    return ans;
}
int main()
{
    cout << " Enter four number : ";
    int p , q , r , s;
    cin >> p >> q >> r >> s;

    foreplay final_ans = function_main(p , q , r , s);
    cout <<"sum is : " << final_ans.a << endl;
    cout <<"minus is : " << final_ans.b << endl;
    cout <<"avg is : " << final_ans.c << endl;
    cout <<"multiplication is : " << final_ans.d << endl;

    

    return 0;
}