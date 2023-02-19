#include <bits/stdc++.h>
using namespace std;


template<typename T>

class queue_using_array
{
    T *data;
    int next_index;
    int first_index;
    int size;
    int capacity;

    public:
        queue_using_array(int s)
        {
            data = new T[s];
            next_index = 0;
            first_index = -1;
            size = 0;
            capacity = s;
        }

        int get_size()
        {
            return size;
        }

        bool is_empty()
        {
            return size == 0;
        }

        void enqueue(T element)
        {

            if (size == capacity)
            {
                T *newdata = new T[2 * capacity];
                int j = 0;
                for (int i = first_index; i < capacity; i++)
                {
                    newdata[j] = data[i];
                    j++;
                }
                for (int i = 0; i < first_index; i++)
                {
                    newdata[j] = data[i];
                    j++;
                }

                delete[] data;
                data = newdata;
                first_index = 0;
                next_index = capacity;
                capacity *= 2;
                
                
                // cout << "queue full\n";
                // return;
            }
            
            data[next_index] = element;
            next_index = next_index + 1 % capacity;

            if (first_index == -1)
            {
                first_index = 0;
            }
            
            size++;

        }

        T front()
        {
            if (is_empty())
            {
                cout << "queue is empty! \n";
                return 0;
            }
            return data[first_index];
            
        }

        T deque()
        {
            if (is_empty())
            {
                cout << "queue is empty!\n";
                return 0;
            }
            T ans = data[first_index + 1] % capacity;
            first_index++;
            size--;
            return ans;
            if (size == 0)
            {
                first_index = -1;
                next_index = 0;
            }
            
        }


};