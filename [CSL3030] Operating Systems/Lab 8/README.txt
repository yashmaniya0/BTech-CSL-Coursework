# Assignment 8


## Sleeping barbar’s synchronization problem :

## Compile and Run:
- You can also run it manually using the following command: ```g++ barber.cpp -pthread && ./a.out -b=2 -c=1 -w=1 > output.txt``` [Here b, c, w are the number of barbers, chairs, waiting room capacity respectively.]
- After completing the above steps, you will be prompted to add the number of customers.

## Bugs:
- No known bugs.

## Assumptions:
- Max numbers of barbers and customers is 300. (can be changed in `barber.cpp` lines 46, 47)
- Cutting Hair and cleaning chair both consume 1 sec. [this value can be changed in line 6 of `helper.cpp`]
- All Customers are coming at t0, this can be changed by uncommenting line 45 of `barber.cpp`.
- The solution is free from deadlock and starvation! (since no semaphores are in a circular loop)




## Banker's Algorithm for deadlock avoidance :

## Compile and Run:
```
g++ bankers.cpp -o bankers
./bankers
```

## Bugs:
- No known bugs.

## Assumptions:
- We take 3 matrices as input (Available, Max, Allocation) with max size as 10^9
- The program will take an input for a process request (process no. and a request string
depicting the number of instances required for each resource type). 
- The program will first check whether the input state is safe or unsafe, and then, 
output whether the stated request can be fulfilled or not.

## Comletion Status
- Correct implementation of the first program : Done
- Use of Monitor for the first one : Done
- Correct implementation of the second program : Done
- Deciding whether the process request can be granted or not : Done