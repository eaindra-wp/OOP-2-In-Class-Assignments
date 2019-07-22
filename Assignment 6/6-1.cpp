/*
    CH08-320143
    a6-p1.cpp
    Eaindra Wun Pyae
    e.wunpyae@jacobs-university.de
*/

#include <iostream>
using namespace std;

int find(int a[], int nr, int el) {
	for(int i=0; i<=nr; i++)
		if (a[i] == el)
			return i;
	return -1;
}

unsigned long difference(unsigned long a, unsigned long b) {
	if (a-b < 0)
		return b-a;
	else
		return a-b;
}

int main() {
	int n, val;
	cout << "n=";
	cin >> n;
	int *v=new int[n];
	cout << "Elements the elements of array:" << endl;
	for(int i=0; i<n; i++)
		cin >> v[i];
	cout << "val=";
	cin >> val;
	int result = find(v, n, val);
	cout << "Position of the searched element=" << result << endl;
	delete v;
	unsigned long x, y;
	x=550000;
	y=550005;
	cout << "Difference=" << difference(x, y) << endl;
	return 0;
}
/*
$> g++ -g -o 6-1 6-1.cpp
$> gdb 6-1
(gdb) run
The below lines are codes which I received after 'run' command.
[New Thread 2208.0x327c]
[New Thread 2208.0x4bbc]
[New Thread 2208.0x2f64]
[New Thread 2208.0x4030]
n=3
Elements the elements of array:
2
5
1
val=3
Position of the searched element=-1
Difference=4294967291
[Thread 2208.0x4030 exited with code 0]
[Thread 2208.0x2f64 exited with code 0]
[Thread 2208.0x4bbc exited with code 0]
[Inferior 1 (process 2208) exited normally]

In my cygwin compiler,the program does not crash, but it returns the
wrong difference value.
In the main function, x is less than y, and x-y will be -5.
However,-5 cannot be returned properly as the return
value from difference function is unsigned long(non-negative) values and
it doesn't contain negative numbers.
So,i typed break 17 and break 23,the beginning and end of difference
function. While rerunning the program,the message below is shown.
Thread 1 hit Breakpoint 1, difference (a=550000, b=550005) at 6-1.cpp:22
22                      return a-b;

Other problem is 'delete v' in line 37. It will only delete the first
element in the array list. Every element in the array will not be deleted
successfully.
Thread 1 hit Breakpoint 3, main () at 6-1.cpp:37
37              delete v;

For find function,it won't return the same index that people usually
understand.So,the return index value will start from 0,rather than 1.
So, I set a break points at line 11 and 16, and run the file again.
The following message appears while running.
Thread 1 hit Breakpoint 1, find (a=0x10a2950, nr=3, el=1) at 6-1.cpp:12
12              for(int i=0; i<=nr; i++)
*/
