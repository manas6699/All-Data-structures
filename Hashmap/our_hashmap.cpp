#include <bits/stdc++.h>
using namespace std;
template <typename T>
class map_node
{
public:
    string key;
    T value;
    map_node *next;

    map_node(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~map_node()
    {
        delete next;
    }
};
template <typename T>
class ourmap
{
    map_node<T> **buckets;
    int count;
    int num_buckets;

public:
    ourmap()
    {
        count = 0;
        num_buckets = 5;
        buckets = new map_node<T> *[num_buckets];
        for (int i = 0; i < num_buckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourmap()
    {
        for (int i = 0; i < num_buckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

public:
    int size()
    {
        return count;
    }

    T get_value(string key)
    {
        int bucket_index = get_bucket_index(key);
        map_node<T> *head = buckets[bucket_index];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }

            head = head->next;
        }
        return 0;
    }

private:
    int get_bucket_index(string key)
    {
        int hashcode = 0;
        int current_C = 1;
        for (int i = (key.length() - 1); i >= 0; i--)
        {
            hashcode += key[i] * current_C;
            hashcode = hashcode % num_buckets;
            current_C *= 37;
            current_C = current_C % num_buckets;
        }

        return hashcode % num_buckets;
    }

    void rehash()
    {
        map_node<T> **temp = buckets;
        buckets = new map_node<T> *[2 * num_buckets];
        for (int i = 0; i < 2 * num_buckets; i++)
        {
            buckets[i] = NULL;
        }
        int old_bucket_count = num_buckets;
        num_buckets *= 2;
        count = 0;
        // now it is behaving like an empty map

        for (int i = 0; i < old_bucket_count; i++)
        {
            map_node<T> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                T value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < old_bucket_count; i++)
        {
            map_node<T> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:

    double get_loadfactor()
    {
        return (1.0 * count) / num_buckets;
    }

    void insert(string key, T value)
    {
        int bucket_index = get_bucket_index(key);
        map_node<T> *head = buckets[bucket_index];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }

            head = head->next;
        }
        head = buckets[bucket_index];
        map_node<T> *node = new map_node<T>(key, value);
        node->next = head;
        buckets[bucket_index] = node;
        count++;
        double load_factor = 1.0 * count / num_buckets;
        if (load_factor > 0.7)
        {
            rehash();
        }
    }

    T remove(string key)
    {
        int bucket_index = get_bucket_index(key);
        map_node<T> *head = buckets[bucket_index];
        map_node<T> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucket_index] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                T value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;

            head = head->next;
        }

        // invalid value for 0
        return 0;
    }
};

int main()
{

    ourmap<int> map;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
        cout << map.get_loadfactor() << endl;
    }
    
    cout <<"Before deletion map size is : " << map.size() << endl;
    map.remove("abc2");
    map.remove("abc8");
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout << key << " : " << map.get_value(key) << endl;

    }
    
    cout << "After deletion map size is : " << map.size() << endl; 
    
}