public class DLL {

    public static void main(String[] args) {
        DLL list = new DLL();
        list.insertFirst(10);
        list.insertFirst(8);
        list.insertFirst(6);
        list.insertFirst(4);
        list.insertFirst(2);
        list.insertLast(12);
        list.insertIndex(65, 8);
        list.display();
    }
    private Node head;
    private Node tail;

    public void insertFirst(int val) {
        Node node = new Node(val);
        node.next=head;
        node.prev=null;
        if (head!=null) {
            head.prev=node;
        }
        head=node;
    }

    public void display() {
        Node node = head;
        while (node!=null) {
            System.out.print(node.val + "->");
            tail=node;
            node=node.next;
        }
        System.out.println("End");
        System.out.println("Printing in Reverse");
        while (tail!=null) {
            System.out.print(tail.val+"->");
            tail=tail.prev;
        }
        System.out.println("Start");
    }

    public void insertLast(int val){
        Node node = new Node(val);
        Node last = head;
        node.next = null;
        if (head==null) {
            node.prev=null;
            head=node;
            return;
        }
        while (last.next!=null) {
            last=last.next;
        }
        last.next=node;
        node.prev=last;
    }

    public Node find(int value) {
        Node node = head;
        while(node!=null) {
            if (node.val==value) {
                return node;
            }
            node=node.next;
        }
        return null;
    }

    public void insertIndex(int val, int after) {
        Node p = find(after);
        if (p==null) {
            System.out.println("Does Not Exists");
            return;
        }
        Node node = new Node(val);
        node.next=p.next;
        p.next=node;
        node.prev=p;
        if (node.next!=null){
            node.next.prev=node;
        }
    }

    private class Node {
        int val;
        Node next;
        Node prev;
        public Node(int val) {
            this.val=val;
        }
        // public Node(int val, Node next, Node prev) {
        //     this.val=val;
        //     this.next=next;
        //     this.prev=prev;
        // }
    }
}