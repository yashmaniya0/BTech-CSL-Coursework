#include <bits/stdc++.h>

using namespace std;


// -------- Macros ---------------------------------------------------------------------------------------------------
#define ll                     long long int
#define ull                     unsingned long long
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define vii                     vector<int>
#define usii                    unordered_set<int>
#define sii                     set<int>
#define mii                     map<int, int>
#define umii                    unordered_map<int, int>
#define effi(x)                 x.max_load_factor(0.2);     // takes greater space to avoid collisions
#define pb                      push_back
#define sp                      " "
#define yep                     cout<<"YES"<<endl;
#define nope                    cout<<"NO"<<endl;
#define neg1                    cout<<-1<<endl;
#define boost                   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mem(v,i) memset(v,i,sizeof(v))
#define forl(i,n)               for(int i=0;i<n;i++)
#define itr(i,a,b)              for(int i=a;(b>=a)?i<b:i>b;(b>=a)?i++:i--)
#define print_arr2d(arr,n,m)    forl(i,n){forl(j,m){cout<<arr[i][j]<<' ';}cout<<endl;}
#define input(arr,n)            forl(i,n){cin>>arr[i];}
#define input_arr2d(arr, n, m)  forl(i,n){forl(j,m){cin>>arr[i][j];}}
#define sprec(x,y)              fixed<<setprecision(y)<<x
#define all(v)                  v.begin(),v.end()
#define rall(v)                 v.rbegin(),v.rend()
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b)) / __gcd((a),(b))
#define min3(a,b,c)             min(c, min(a, b))
#define min4(a,b,c,d)           min(d, min(c, min(a, b)))
#define max3(a,b,c)             max(c, max(a, b))
#define max4(a,b,c,d)           max(d, max(c, max(a, b)))
// --------------------------------------------------------------------------------------------------------------------

const int str_size = 150;
const int page_types = 30;

// --------------------------------------------------------------------------------------------------------------------

int pgFaultsFIFO(vector<int> pages, int capacity){
    int n = pages.size();

    int pgFault  = 0;
    queue<int> fifo;
    unordered_set<int> present;

    forl(i, n){
        int page = pages[i];
        if(present.find(page) != present.end()) continue;

        if(fifo.size() >= capacity){
            int rem = fifo.front();
            fifo.pop();
            present.erase(rem);
            // cerr<<"Rem=>"<<rem<<endl;
        }

        fifo.push(page);
        present.insert(page);

        pgFault++;
        // cerr<<page<<endl;
    }
    // cerr<<endl;
    return pgFault;
}

int pgFaultsLRU(vector<int> pages, int capacity){
    int n = pages.size();

    int pgFault  = 0;
    vector<int> lru;
    unordered_set<int> present;

    forl(i, n){
        int page = pages[i];
        if(present.find(page) != present.end()){
            for (auto it = lru.begin(); it != lru.end(); ++it){
                if(*it==page) lru.erase(it);
            }
            lru.push_back(page);
        } else{
            if(lru.size() >= capacity){
                int rem = lru.front();
                lru.erase(lru.begin());
                present.erase(rem);
            }

            lru.push_back(page);
            present.insert(page);

            pgFault++;
        } 
    }
    return pgFault;
}


int pgFaultsOPR(vector<int> pages, int capacity){
    int n = pages.size();

    int pgFault  = 0;
    vector<int> opr;
    unordered_set<int> present;

    forl(i, n){
        int page = pages[i];
        if(present.find(page) != present.end()) continue;

        if(opr.size() >= capacity){
            int num = -1;
            int num_pos = -1;
            for (auto& it : opr){
                int tnum = it, tnum_pos = -1;
                for(int j = i+1; j < n; j++){
                    if(pages[j]==it){
                        tnum_pos = j;
                    }
                }
                if(tnum_pos==-1){
                    num = tnum;
                    num_pos = tnum_pos;
                    break;
                } else if(num!=-1){
                    if(tnum_pos>num_pos){
                        num = tnum;
                        num_pos = tnum_pos;
                    }
                } else{
                    num = tnum;
                    num_pos = tnum_pos;
                }
            }

            for (int it1 = 0; it1 < opr.size(); ++it1){
                if(it1==num) opr.erase(opr.begin()+it1);
            }
            
            present.erase(num);
        }

        opr.push_back(page);
        present.insert(page);

        pgFault++;

    }
    return pgFault;
}

int main(){
    #ifdef DBG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n_frames;
    cout<<"Enter number of Frames: ";
    cin>>n_frames;

    vector<int> rString;

    cout<<"\nEnter the Pages array (pages[i]>0): \n";

    while (true) {
        int temp;
        cin >> temp;
        if(temp == -1) break;

        rString.push_back(temp);
        if (cin.peek() == '\n') {
            break;
        }
    }
    cout<<endl;
    cout<<"Page Faults encountered in the corresponding algos :\n\n";
    cout<<"FIFO: "<<pgFaultsFIFO(rString, n_frames)<<endl;
    cout<<"LRU: "<<pgFaultsLRU(rString, n_frames)<<endl;
    cout<<"OPR: "<<pgFaultsOPR(rString, n_frames)<<endl;
    
    cout<<"\nFor Belady's anomaly, Please enter the number of simulations: ";
    int n;
    cin>>n;

    srand(time(0));

    int ctr=0;

    forl(i,n){
        int inp_string;
        rString.clear();

        forl(j, str_size) rString.push_back(rand()%page_types);

        int lastFault = INT_MAX;

        itr(j, 2, (str_size/5)){
            int currFault = pgFaultsFIFO(rString, j);
            if(currFault>lastFault){
                ctr++;
                cout<<"\nBelady's Anomaly detected\n";
                cout<<"Number of frames: "<<j-1<<"     ||     Faults: "<<lastFault;cout<<endl;;
                cout<<"Number of frames: "<<j<<"     ||     Faults: "<<currFault;cout<<endl;;
            }
            lastFault = currFault;
        }
    }

    cout<<"\n\nBelady's Anomaly detected in ["<<ctr<<" / "<<n<<"] simulations."<<endl;
    return 0;
}