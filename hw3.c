

class pthread extends Thread {
private Thread t;
private int threadName;
private int sum ;
private int start;
private int end;

pthread( int s,int e,int name) {
start =s; // starting number
end =e; // ending numbaer
threadName = name;
}

@Override
public void run() {
try {
for(int i = start; i <= end; i++) {
sum = sum+i; // Sum of ecah thread updated
Thread.sleep(50); // thread sleep
}
} catch (InterruptedException e) {
System.out.println("Thread No " + threadName + " interrupted.");
}
System.out.println(" The Sum of Number From "+start+" to "+end+" is "+sum+" From Thread "+ threadName );
}

public void start () { // start the thread
if (t == null) {
t = new Thread (this, String.valueOf(threadName));
t.start (); // run call
}
}
}

public class ThreadMain {

public static void main(String args[]) {
int n =1000;
int st=1;
int en=1000;
for(int i =0;i<n;i++){ // create 10 Thread
pthread objThread = new pthread( st,en,i);
objThread.start();
st = en+1;
en = en+10;
}
System.out.println(" 10 Thread Created Successfuly \n\n\n");

}
}
