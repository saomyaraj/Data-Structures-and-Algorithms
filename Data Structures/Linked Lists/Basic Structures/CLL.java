public class CLL {

    public static void main(String[] args) {
        CLL list = new CLL();
        list.insert(10);
        list.insert(8);
        list.insert(6);
        list.insert(4);
        list.insert(2);
        list.delete(8);
        list.display();
    }

    private Node head;
    private Node tail;

    public CLL() {
        this.head=null;
        this.tail=null;
    }

    public void insert(int val) {
        Node node = new Node(val);
        if (head==null) {
            head=node;
            tail=node;
            return;
        }
        tail.next=node;
        node.next=head;
        tail=node;
    }
    
    public void display() {
        Node node = head;
        if (head!=null) {
            do {
                System.out.print(node.val+"->");
                node=node.next;
            } while (node!=head);
        }
        System.out.println("Head");
    }

    public void delete(int val){
        Node node = head;
        if (node==null) {
            head=head.next;
            tail.next=head;
            return;
        }
        do {
            Node n = node.next;
            if (n.val==val) {
                node.next=n.next;
                break;
            }
            node=node.next;
        } while (node!=head);
    }

    private class Node{
        int val;
        Node next;

        public Node(int val) {
            this.val=val;
        }
    }
}