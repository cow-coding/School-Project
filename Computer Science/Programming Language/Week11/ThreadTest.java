class PriorityThread extends Thread{
  public long cnt;
  //private boolean stop;

  //public void setStop(boolean stop) {
  //  this.stop = stop;
  //}

  PriorityThread(int p) {
    setPriority(p);
    start();
  }

  public void run() {
    while(!Thread.interrupted()) cnt++;
  }
}
// interrupt를 활용한 Thread 종료
public class ThreadTest{
  public static void main(String[] args) {
    PriorityThread t01 = new PriorityThread(Thread.MIN_PRIORITY);
    PriorityThread t02 = new PriorityThread(1);
    PriorityThread t03 = new PriorityThread(Thread.MIN_PRIORITY);
    PriorityThread t04 = new PriorityThread(10);

    try {
      Thread.sleep(2000);
    }catch (InterruptedException e) {
      e.printStackTrace();
    }

    t01.interrupt();
    t02.interrupt();
    t03.interrupt();
    t04.interrupt();

    // t01.setStop(true);
    // t02.setStop(true);
    // t03.setStop(true);
    // t04.setStop(true);
  }
}
