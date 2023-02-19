#include <bits/stdc++.h>
using namespace std;

class stackd
{
    int *data;
    int next_index;
    int check;

    public :
        stackd(int total_size)
        {
            data = new int[total_size];
            next_index = 0;
            check = next_index;
        }

        void push(int element)
        {
            if (next_index == check)
            {
                cout << "Stack overflow\n";
            }
            
            data[next_index] = element;
            next_index++;
        }

        int size()
        {
            return next_index;
        }

        bool is_empty()
        {
            return next_index == 0;
        }

        int pop()
        {
            if (is_empty())
            {
                return INT_MIN;
            }
            
            next_index--;
            return data[next_index];
        }

        int top()
        {
            if (next_index == check)
            {
                return INT_MIN;
            }
            
            return data[next_index - 1];
        }

};

// int main()
// {
//     stackd s1(10);

//     s1.push(10);
//     s1.push(20);
//     s1.push(30);
//     s1.push(40);
//     s1.push(50);

//     return 0;
// }