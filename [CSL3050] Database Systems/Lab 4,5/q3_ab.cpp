#include <bits/stdc++.h>
#include "./linear_hashing_with_non_linear_bucket.cpp"
#include <chrono>

using namespace std;

void queries(Directory &d, vector<Data> &entries, int initial_global_depth, int bucket_size)
{
    int n_entries = entries.size();
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n_entries; i++)
    {
        d.insert(&entries[i]);
    }
    cout << "\nInserted all the entries" << endl;
    cout << endl;
    auto end = std::chrono::high_resolution_clock::now();
    d.display();

    int time_taken = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    cout << "\nMetrics for Insertion queries :\n";
    cout << endl;
    cout << "Global Depth (n) : " << initial_global_depth << endl;
    cout << "Bucket size : " << bucket_size << endl;
    cout << "Time taken : " << (float)time_taken / 1000 << " ms" << endl;
}

int main()
{
    int bucket_size = 4, initial_global_depth = 7;

    Directory d(initial_global_depth, bucket_size);
    cout << "Initialized directory structure with \nBucket size : " << bucket_size << "\nInitial Global depth (n) : " << initial_global_depth << endl
         << endl;

    vector<string> author_ids = {"An_Ch_0103", "An_Da_0104", "Ca_Sa_0319", "Jo_Ro_1018", "Jo_Ro_1018", "Jo_Ro_1018", "Jo_Ro_1018", "Jo_Ro_1018", "La_Ch_1203", "Ma_Mi_1313", "Ma_Mi_1313", "Pe_Wo_1623", "Pe_Wo_1623", "Vi_Ra_2218", "Vi_Ra_2218"};
    vector<string> book_ids = {"Aest_AC_0103", "Self_AD_0104 ", "Anim_CS_0319", "Deat_JR_1018", "Fant_JR_1018", "Gobl_JR_1018", "Phil_JR_1018", "Pris_JR_1018", "Mind_LC_1203", "Emot_MM_1313", "Soci_MM_1313", "Aunt_PW_1623", "Wode_PW_1623", "Emer_VR_2218", "Phan_VR_2218"};
    vector<string> authors = {"Anjan Chatterjee", "Antonio Damasio", "Carl Safina", "Joanne K. Rowling", "Joanne K. Rowling", "Joanne K. Rowling", "Joanne K. Rowling", "Joanne K. Rowling", "Lars Chittka", "Marvin Minsky", "Marvin Minsky", "Pelham G. Wodehouse", "Pelham G. Wodehouse", "Vilayanur Ramachandran", "Vilayanur Ramachandran"};
    vector<string> books = {"The Aesthetic Brain", "Self Comes to Mind", "What Animals Think", "Deathly Hallows_Harry Potter", "Fantastic Beasts and Where to  Find Them", "Goblet of Fire_Harry Potter", "Philosopher’s Stone_Harry Potter", "Prisoner of Azkaban_Harry Potter", "The Mind of a Bee", "Emotion Machine", "Society of Mind", "Aunts Aren’t Gentlemen", "Wodehouse at the Wicket", "The Emerging Mind", "Phantoms in the Brain"};
    vector<Data> entries;
    int n_entries = books.size();
    for (int i = 0; i < n_entries; i++)
    {
        Data r(book_ids[i], books[i], author_ids[i], authors[i]);
        entries.push_back(r);
    }

    queries(d, entries, initial_global_depth, bucket_size);

    auto start = std::chrono::high_resolution_clock::now();
    d.search(entries[11]);
    auto end = std::chrono::high_resolution_clock::now();
    float time_taken = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    cout << "Time taken : " << time_taken / 1000 << " ms" << endl;

    return 0;
}