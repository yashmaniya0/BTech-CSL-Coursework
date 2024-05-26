#include <bits/stdc++.h>
#include <pthread.h>
#include <semaphore.h>
#include "helper.cpp"
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


#define forl(i,n) for(int i=(0);i<(n);i++)
#define rep(i,a,n) for(int i=(a);i<(n);i++)

#define MAX_BRBRS 300
#define MAX_CSTMRS 300

#define CUST_SLEEP_TIME_LIMIT 10

#define WAITING_OUTSIDE 1
#define WAIT_ROOM 2
#define SITTING_ON_COUCH 3
#define BRBR_CHAIR 4
#define CLEANED_CHAIR 5
#define READY_TO_PAY 6
#define PAYMENT_ACCEPTED 7
#define CAN_EXIT 8
#define OUTSIDE 9

int n_brbrs=-1, n_chrs=-1, n_wtRoom=-1;
bool gateKeeperPresent = true;

int cstmrStatus[MAX_CSTMRS]; // 0 in chair, 1 cutting done, 2 payment done
int cstmrBRBR[MAX_BRBRS];

queue<int> outsideQ;
queue<int> waitingRoomQ;
queue<int> couchQ;
queue<int> leaveQ;

const int INITIAL_VALUE = 1;
sem_t semaphoreCouch, semaphoreOutside, semaphoreWaitingRoom, semaphorePayment, semaphoreCSTMR_BRBR, semaphoreClean, semaphoreCstmrStatus, semaphoreLeave;

void* initCustomer(void* ptr){
    // std::this_thread::sleep_for (std::chrono::seconds(rand()%CUST_SLEEP_TIME_LIMIT));
    int id = *(int *)(&ptr);
    Customer c(id);

    sem_wait(&semaphoreOutside);
    outsideQ.push(id);
    sem_post(&semaphoreaphoreOutside);

    while(cstmrStatus[id]!=WAIT_ROOM) continue;
    
    sem_wait(&semaphoreWaitingRoom);
    c.enterShop();
    waitingRoomQ.push(id);
    sem_post(&semaphoreWaitingRoom);

    while(!(waitingRoomQ.front() == id)) continue;

    while(true){
        if(couchQ.size() < n_chrs){
            sem_wait(&semaphoreCouch);
            couchQ.push(id);
            c.sitOnSofa();
            sem_post(&semaphoreCouch);

            sem_wait(&semaphoreWaitingRoom);
            waitingRoomQ.pop();
            sem_post(&semaphoreWaitingRoom);

            break;
        }
    }

    while(couchQ.front()!=id) continue;

    int myBRBR = -1;
    while(myBRBR==-1){
        forl(i, n_brbrs){
            if(cstmrBRBR[i]==-1){
                sem_wait(&semaphoreCSTMR_BRBR);
                cstmrBRBR[i] = id;
                sem_post(&semaphoreCSTMR_BRBR);
                
                myBRBR = i;
                c.sitInBarberChair(myBRBR);
                break;
            }
        }
    }

    sem_wait(&semaphoreCouch);
    couchQ.pop();
    sem_post(&semaphoreCouch);

    sem_wait(&semaphoreCstmrStatus);
    cstmrStatus[id] = BRBR_CHAIR;
    sem_post(&semaphoreCstmrStatus);
    

    c.waitforPayment();
    while(cstmrStatus[id]!=CLEANED_CHAIR)continue;

    sem_wait(&semaphoreCstmrStatus);
    cstmrStatus[id] = READY_TO_PAY;
    sem_post(&semaphoreCstmrStatus);

    c.pay(myBRBR);
    while(cstmrStatus[id]!=PAYMENT_ACCEPTED)continue;

    sem_wait(&semaphoreLeave);
    c.leaveShop();
    leaveQ.push(id);
    sem_post(&semaphoreLeave);

    while(cstmrStatus[id]!=CAN_EXIT)continue;
    c.exitShop();
}

void* initBarber(void* ptr){
    int id = *(int *)(&ptr);
    Barber b(id);
    bool awake = true;

    while(gateKeeperPresent){
        if(cstmrBRBR[id] == -1){ // wait for customer to show up
            if(awake) b.sleep();
            awake = false;
            continue;
        }
        awake = true;

        int myCstmr = cstmrBRBR[id];

        while(cstmrStatus[myCstmr]!=BRBR_CHAIR) continue;
        b.cutHair(myCstmr);

        sem_wait(&semaphoreClean);
        b.cleanChair();
        sem_post(&semaphoreClean);

        sem_wait(&semaphoreCstmrStatus);
        cstmrStatus[myCstmr]=CLEANED_CHAIR;
        sem_post(&semaphoreCstmrStatus);

        while(cstmrStatus[myCstmr]!=READY_TO_PAY)continue;

        sem_wait(&semaphorePayment);
        b.acceptPayment(myCstmr);
        sem_post(&semaphorePayment);

        sem_wait(&semaphoreCstmrStatus);
        cstmrStatus[myCstmr]=PAYMENT_ACCEPTED;
        sem_post(&semaphoreCstmrStatus);

        sem_wait(&semaphoreCSTMR_BRBR);
        cstmrBRBR[id] = -1;
        sem_post(&semaphoreCSTMR_BRBR);
    }
}

void initGatekeeper(int n_cstmrs){
    Gatekeeper g;
    while(n_cstmrs > 0){
        if((!outsideQ.empty()) && g.tokens_issued < n_wtRoom + n_chrs + n_brbrs){
            int nextCust;

            sem_wait(&semaphoreOutside);
            nextCust=outsideQ.front();
            outsideQ.pop();
            sem_post(&semaphoreOutside);

            g.giveToken(nextCust);

            sem_wait(&semaphoreCstmrStatus);
            cstmrStatus[nextCust] = WAIT_ROOM;
            sem_post(&semaphoreCstmrStatus);
        }

        if(!leaveQ.empty()){
            int leavingCust = leaveQ.front();
            if(cstmrStatus[leavingCust]==PAYMENT_ACCEPTED){
                g.verifyPayment(leavingCust);
            }
            g.takeToken(leavingCust);
            
            sem_wait(&semaphoreLeave);
            leaveQ.pop();
            sem_post(&semaphoreLeave);

            sem_wait(&semaphoreCstmrStatus);
            cstmrStatus[leavingCust] = CAN_EXIT;
            sem_post(&semaphoreCstmrStatus);
            
            n_cstmrs--;
        }
    }
    gateKeeperPresent = false;
    return;
}

int main(int argc, char *argv[]){

    sem_init(&semaphoreCouch, 0, INITIAL_VALUE);
    sem_init(&semaphoreOutside, 0, INITIAL_VALUE);
    sem_init(&semaphorePayment, 0, INITIAL_VALUE);
    sem_init(&semaphoreWaitingRoom, 0, INITIAL_VALUE);
    sem_init(&semaphoreCSTMR_BRBR, 0, INITIAL_VALUE);
    sem_init(&semaphoreClean, 0, INITIAL_VALUE);
    sem_init(&semaphoreCstmrStatus, 0, INITIAL_VALUE);
    sem_init(&semaphoreLeave, 0, INITIAL_VALUE);
    sem_init(&S, 0, INITIAL_VALUE);

    mem(cstmrStatus, 0);
    forl(i, MAX_BRBRS) cstmrBRBR[i] = -1;

    int n_cstmrs;

    cerr<<"Done with initialising\n";
    itr(i, 1, argc){
        if(argv[i][0]!='-')continue;
        switch (argv[i][1]){
        case 'b':
            n_brbrs = atoi(argv[i]+3);
            break;
        case 'c':
            n_chrs = atoi(argv[i]+3);
            break;
        case 'w':
            n_wtRoom = atoi(argv[i]+3);
            break;
        default:
            cerr<<"Incorrect flag: "<<argv[i];
            break;
        }
    }

    cerr<<"Enter the number of customers: ";
    cin>>n_cstmrs;

    pthread_t brbrs[n_brbrs];
    forl(i,n_brbrs){
        brbrs[i] = pthread_t();
        pthread_create( &brbrs[i], NULL, initBarber,(void*) i);
    }

    pthread_t cstmrs[n_cstmrs];
    forl(i,n_cstmrs){
        cstmrs[i] = pthread_t();
        pthread_create( &cstmrs[i], NULL, initCustomer,(void*) i);
    }

    initGatekeeper(n_cstmrs);

    forl(i, n_cstmrs)
        pthread_join(cstmrs[i], NULL);
    cerr<<"All customers done\n";
    forl(i, n_brbrs)
        pthread_join(brbrs[i], NULL);   

    return 0;
}