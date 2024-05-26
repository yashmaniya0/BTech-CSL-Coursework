# Assignment 7


Question 1

a) 
It seems that starvation can occur in this part, because two forks are necessary to eat and
until the philosopher don’t get its two nearest fork, it has to wait and this wait can be forever. Suppose,
we have a situation where philosopher 1 has neither fork available, and in this duration philosopher 5
has its right fork available (which is left fork of 1st) and philosopher 2 has already left fork occupied
(which is right fork of 1st), and philosopher 5 got its remaining fork, then it will begin to eat. Next after
eating it releases its fork, then philosopher 2 got its remaining fork and starts eating, and in this
duration philosopher 5 again will get its left fork and right fork is already free (as philosopher 1 has
only one fork so it can’t eat and can’t take any fork too). This loop between all philosophers except
philosopher 1 can run forever and starvation can occur this way.
To prevent this what we can do is to allow only a limited no. of philosophers ‘k’ to eat at a particular
time and after they are done, another ‘k’ philosophers will be allowed to eat, in this way starvation
will not occur. Suppose, you are blocked waiting for your left fork. Eventually your left neighbor, who
was in the previous ‘k’ eaters, will put it down, because eat can’t run forever. Since you are the only
thread waiting for that fork, you will necessarily get it next. Similarly, you can get your right fork too.

Compilation and Execution : 
```
gcc no_deadlock.c -o no_deadlock –pthread
./no_deadlock
```

b)
Each philosopher grabs the two forks one by one – first the left fork, and then
after some waiting the right fork, seems to be Starvation free. Suppose, we have a situation where
philosopher 1 has neither fork available, and in this duration philosopher 5 has its right fork available
(which is left fork of 1st) and philosopher 2 has already left fork occupied (which is right fork of 1st),
and philosopher 5 got its remaining fork, then it will begin to eat. Next after eating it releases its fork,
and in that time philosopher 2 got its remaining fork and starts eating, and in this duration philosopher
1 will take its left fork as philosopher 5 has dropped it and after philosopher 2 has eaten, it will also
release its fork and hence philosopher 1 will get both its forks and starts eating. This way every
philosopher can get its fork and starvation cannot occur. 

Compilation and Execution : 
```
gcc with_deadlock.c -o with_deadlock –pthread
./with_deadlock
```

Sample Output:

Philosopher 1 starts thinking
Philosopher 2 starts thinking
Philosopher 3 starts thinking
Philosopher 4 starts thinking
Philosopher 5 starts thinking
Philosopher 1 grabs left fork 5 
Philosopher 1 grabs right fork 1
Philosopher 1 starts eating
Philosopher 1 ends eating
Philosopher 1 releases forks 5 (left) and 1 (right)
Philosopher 1 starts thinking
Philosopher 5 grabs left fork 4 
Philosopher 5 grabs right fork 5
Philosopher 5 starts eating
Philosopher 5 ends eating
Philosopher 5 releases forks 4 (left) and 5 (right)
Philosopher 5 starts thinking
Philosopher 2 grabs left fork 1
Philosopher 2 grabs right fork 2
Philosopher 2 starts eating
Philosopher 4 grabs left fork 3 
Philosopher 4 grabs right fork 4
Philosopher 4 starts eating
Philosopher 2 ends eating
Philosopher 4 ends eating
Philosopher 2 starts thinking
Philosopher 3 starts thinking

To terminate the program use Ctrl+C


Question 2

We've created 10 readers and 5 writers in this classic reader-writer problem. A writer can 
only write the content, i.e. enter the critical section, when there are no readers to read it.


Assumptions and Conditions:
- Multiple readers are allowed to read at the same time. 
- Only 1 writer can write at a time. 
- There shall be no starvation for a reader. 
- Starvation may be possible for the writer.
- If a writer is already writing, reader can't read.

Compilation and Execution : 
->gcc reader_writer.c
->./a.out

Sample Output:

Writer 1 modified variable to 2
Writer 4 modified variable to 4
Reader 1: read variable as 4
Writer 2 modified variable to 8
Writer 5 modified variable to 16
Reader 10: read variable as 16
Reader 4: read variable as 16
Reader 3: read variable as 16
Reader 8: read variable as 16
Reader 5: read variable as 16
Reader 6: read variable as 16
Reader 7: read variable as 16
Reader 2: read variable as 16
Reader 9: read variable as 16
Writer 3 modified variable to 32