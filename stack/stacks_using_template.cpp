template <typename T>

class stack_use
{
    T *data;
    int capacity;
    int next_index;

public:
    stack_use()
    {
        data = new T[5];
        next_index = 0;
        capacity = 5;
    }

    void push(T element)
    {

        if (next_index == capacity)
        {
            //cout << "Stack overflow\n";
            T *newset = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newset[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newset;
        }

        data[next_index] = element;
        next_index++;
    }

    int size()
    {
        return next_index;
    }

    T top()
    {
        if (next_index == capacity)
        {
            return 0;
        }

        return data[next_index - 1];
    }

    //  isempty , pop 
};

// int main()
// {
//     stack_use s1;
//     s1.push(10);
//     s1.push(20);
//     s1.push(30);
//     s1.push(40);
//     s1.push(50);
//     s1.push(60);
//     s1.push(70);
//     s1.push(80);
//     s1.push(90);
//     s1.push(100);
//     s1.push(200);
//     s1.push(300);
//     s1.push(400);
//     s1.push(500);
//     s1.push(600);

//     cout << s1.top() << endl;
//     cout << s1.size() << endl;

//     return 0;
// }