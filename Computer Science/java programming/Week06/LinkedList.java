public class LinkedList {

    private Node head;
    private Node tail;
    private int size = 0;
    private class Node{
        private Object data;
        private Node next;
        public Node(Object input) {
            this.data=input;
            this.next=null;
        }
    }
    public void addNode(Object input) {
        Node newNode=new Node(input);
        if(size==0) {
            newNode.next=head;
            head=newNode;
            size++;
            if(head.next==null) {
                tail=head;
            }
            else {
                tail.next=newNode;
                tail=newNode;
                size++;
            }
        }
    }
    public int getSize() {
        return size;
    }
    Node node(int index) {
        Node x=head;
        for(int i=0;i<index; i++)
            x=x.next;
        return x;
    }
    public Object get(int k) {
        Node tmp=node(k);
        return tmp.data;
    }
    public Object deleteNode(){
        Node tmp=head;
        head=tmp.next;
        Object returnData=tmp.data;
        tmp=null;
        size--;
        return returnData;
    }

    public static void main(String[] args) {


    }

}