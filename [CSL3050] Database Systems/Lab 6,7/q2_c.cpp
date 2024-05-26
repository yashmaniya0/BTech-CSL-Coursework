#include <bits/stdc++.h>
#include <chrono>
using namespace std;

// To store the rows of the table
struct Row{
    string Author_ID,Book_ID,Author_Name,Book;

    Row(string a,string b,string c,string d){
        Author_ID=a;
        Book_ID=b;
        Author_Name=c;
        Book=d;
    }
    Row(){}
};

struct Bucket{
    int id=0;
    unordered_map<int,Row> v;
};



// class Hashing{

    // public:
    map<int,Bucket*> bmap;
    int gd=1,bucket_size=4;
    

    int required_LSBS(int n,int gd){
        string binary_rep = "";
        while(n>0){
            binary_rep += to_string(n%2);
            n/=2;
        }
        if(binary_rep.size()<gd){
            int diff = gd - binary_rep.size();
            while(diff--){
                binary_rep += "0";
            }
        }
        string ans = binary_rep.substr(0,gd);
        // reverse(ans.begin(),ans.end());
        int tmp=1;
        int final_val=0;
        for(int i=0;i<gd;i++){
            if(ans[i]=='1'){
                final_val += (tmp);
            }
            tmp*=2;
        }

        return final_val;
    }

    int ascii_val(string s){
        int ans=0;
        for(auto i:s){
            ans+=(int)i;
        }
        return ans;
    }

    int hash_function(Row R){
        string a_id = R.Author_ID;
        string b_id = R.Book_ID;
        int ans = 0;
        ans+=ascii_val(a_id);
        ans+=ascii_val(b_id.substr(0,4));
        return ans;
    }

    bool search(Row R){
        int n = hash_function(R);
        int bucket_id = required_LSBS(n,gd);
        for(auto j:bmap[bucket_id]->v){
            auto i = j.second;
            if(i.Author_ID== R.Author_ID && i.Author_Name==R.Author_Name && i.Book==R.Book && i.Book_ID==R.Book_ID){
                return true;
            }
        }
        return false;
    }

    void insert(Row R){
        int hash_value = hash_function(R);
        int req_id = required_LSBS(hash_value,gd);
        // cout<<req_id<<endl;
        if(bmap[req_id]->v.size() < bucket_size){
            bmap[req_id]->v.insert({hash_value,R});
            return;
        }
        else{
            int multiply = pow(2,gd);
            gd++;
            // cout<<"gd = "<<gd<<endl;
            map<int,Bucket*> temp;
            // cout<<"size of bmap = "<<bmap.size()<<endl;

            for(auto i:bmap){
                // cout<<"size of bmap = "<<bmap.size()<<endl;

                int x1 = i.first;
                int x2 = x1+multiply;
                // temp[x1] = i.second;
                // temp[x2] = i.second;
                // if(temp.find(x1)==temp.end()){
                    temp[x1] = new Bucket;
                // }
                // if(temp.find(x2)==temp.end()){
                    temp[x2] = new Bucket;
                // }
                for(auto j:i.second->v){
                    auto k = j.second;
                    int temp1 = required_LSBS(hash_function(k),gd);
                    // cout<<temp1<<" "<<x1<<endl;
                    if(temp1 == x1){
                        // cout<<"yee"<<endl;
                        
                        temp[x1]->v.insert({hash_function(k),k});
                        // cout<<temp1<<" "<<x1<<endl;

                    }
                    else{
                        
                        temp[x2]->v.insert({hash_function(k),k});

                    }

                }
                temp[x1]->id = x1;
                temp[x2]->id = x2;
                // cout<<"size of temp = "<<temp.size()<<endl;

            }

            bmap.clear();
            for(auto i:temp){
                bmap[i.first] = i.second;
            }
            // cout<<"size of bmap = "<<bmap.size()<<endl;

            insert(R);

            return;
        }
    }

// };

int main(){
    // Hashing database;
    // R.Author_ID = "An_Ch_0103";
    // R.Author_Name = "Anjan Chatterjee";
    // R.Book = "The Aesthetic Brain";

    // R.Book_ID = "Aest_AC_0103";
    // cout<<"yee"<<endl;
    int bucketSize;
    cout<<"Insert the Bucket Size : ";

    cin>>bucketSize;
    bucket_size = bucketSize;
    bmap[0] = new Bucket;
    bmap[1] = new Bucket;
    // insert(R);

    Row R1("An_Ch_0103","Aest_AC_0103","Anjan Chatterjee","The Aesthetic Brain");
    Row R2("An_Da_0104 ","Self_AD_0104","Antonio Damasio","Self Comes to Mind");
    Row R3("Ca_Sa_0319","Anim_CS_0319","Carl Safina","What Animals Think");
    Row R4("Jo_Ro_1018","Deat_JR_1018","Joanne K. Rowling","Deathly Hallows_Harry Potter");
    Row R5("Jo_Ro_1018","Fant_JR_1018","Joanne K. Rowling","Fantastic Beasts and Where to  Find Them");
    Row R6("Jo_Ro_1018","Gobl_JR_1018","Joanne K. Rowling","Goblet of Fire_Harry Potter");
    Row R7("Jo_Ro_1018","Phil_JR_1018","Joanne K. Rowling","Philosopher\'s Stone_Harry Potter");
    Row R8("Jo_Ro_1018","Pris_JR_1018","Joanne K. Rowling","Prisoner of Azkaban_Harry Potter");
    Row R9("La_Ch_1203","Mind_LC_1203","Lars Chittka","The Mind of a Bee");
    Row R10("Ma_Mi_1313","Ma_Mi_1313","Marvin Minsky","Emotion Machine");
    Row R11("Ma_Mi_1313","Soci_MM_1313","Marvin Minsky","Society of Mind");
    Row R12("Pe_Wo_1623","Aunt_PW_1623","Pelham G. Wodehouse","Aunts Aren't Gentlemen");
    Row R13("Pe_Wo_1623","Wode_PW_1623","Pelham G. Wodehouse","Wodehouse at the Wicket");
    Row R14("Vi_Ra_2218","Emer_VR_2218","Vilayanur Ramachandran","The Emerging Mind");
    Row R15("Vi_Ra_2218","Phan_VR_2218","Vilayanur Ramachandran","Phantoms in the Brain");

// clock_t start,end;
//     start = clock();
    auto start = chrono::high_resolution_clock::now();
    vector<Row> v1 = {R1,R2,R3,R4,R5,R6,R7,R8,R9,R10,R11,R12,R13,R14,R15};
    for(auto i:v1){
        insert(i);
    }
    // cout<<endl;
    auto end = chrono::high_resolution_clock::now();
    

    bool xd = search(R11);

    // end = clock();
    // double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  
    time_taken *= 1e-9;
    // cout<<time_taken<<endl;
    cout<<"time taken by the query to get executed is "<<fixed<<time_taken<<setprecision(9);
    cout<<" sec"<<endl;
    cout<<xd<<endl;
}



