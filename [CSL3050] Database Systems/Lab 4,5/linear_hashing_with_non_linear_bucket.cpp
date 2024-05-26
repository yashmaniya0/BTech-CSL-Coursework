#include <bits/stdc++.h>
using namespace std;

class Data
{
public:
    string bid, book, aid, author;
    int key;
    Data(string book_id, string book_name, string author_id, string author_name)
    {
        bid = book_id;
        book = book_name;
        author = author_name;
        aid = author_id;
        key = hash(book_id);
        // key += hash(author_id);
    }

    int hash(string s)
    {
        int k = 0;
        for (char c : s)
        {
            k += c;
        }
        return k;
    }

    void display()
    {
        cout << bid << "\t";
        cout << book << "\t";
        cout << aid << "\t";
        cout << author << endl;
    }
};

class Bucket
{
public:
    int depth, size;
    std::map<int, Data *> values;

    Bucket(int depth, int size)
    {
        this->depth = depth;
        this->size = size;
    }

    int insert(Data *value)
    {
        int key = value->key;
        auto it = values.find(key);
        if (it != values.end())
            return -1;
        if (isFull())
            return 0;
        values[key] = value;
        return 1;
    }

    void search(int key)
    {
        auto it = values.find(key);
        if (it != values.end())
        {
            cout << "Found item :\n";
            it->second->display();
        }
        else
        {
            cout << "This item does not exists" << endl;
        }
    }

    int isFull(void)
    {
        if (values.size() == size)
            return 1;
        else
            return 0;
    }

    void display()
    {
        std::map<int, Data *>::iterator it;
        for (it = values.begin(); it != values.end(); it++)
        {
            cout << it->second->bid << ", ";
            // it->second->display();
        }
        cout << endl;
    }
};

class Directory
{
public:
    int global_depth, bucket_size;
    vector<Bucket *> buckets;

    Directory(int depth, int bucket_size)
    {
        this->global_depth = depth;
        this->bucket_size = bucket_size;
        for (int i = 0; i < depth; i++)
        {
            buckets.push_back(new Bucket(depth, bucket_size));
        }
    }

    void grow(void)
    {
        vector<Data *> all_data;
        for (int i = 0; i < global_depth; i++)
        {
            for (auto p : buckets[i]->values)
            {
                all_data.push_back(p.second);
            }
        }

        this->global_depth <<= 1;
        buckets.clear();
        for (int i = 0; i < global_depth; i++)
        {
            buckets.push_back(new Bucket(global_depth, bucket_size));
        }
        for (Data *row : all_data)
        {
            insert(row, true);
        }
    }

    void insert(Data *value, bool rev = false)
    {
        int key = value->key;
        int bucket_no = key % global_depth;
        int status = buckets[bucket_no]->insert(value);
        if (status == 1)
        {
            if (!rev)
            {
                cout << "Inserted given book \"" << value->book << "\" in bucket " << bucket_no << endl;
            }
        }
        else if (status == 0)
        {
            cout << endl;
            // display();
            cout << "\nBucket size full at " << bucket_no << "\nChanging global depth to " << (global_depth << 1) << endl;
            grow();
            insert(value);
        }
        else
        {
            cout << "Key " << value->key << " already exists in bucket " << bucket_no << endl;
        }
        // display();
    }

    void search(Data value)
    {
        int bucket_no = value.key % global_depth;
        buckets[bucket_no]->search(value.key);
    }

    void display()
    {
        for (int key = 0; key < global_depth; key++)
        {
            cout << key << "\t=>\t";
            buckets[key]->display();
            cout << endl;
        }
    }
};