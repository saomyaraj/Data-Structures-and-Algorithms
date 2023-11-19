class LL {
  private class Node {
    int data;
    Node next;

    Node(int data) {
      this.data = data;
      this.next = null;
    }
  }

  private Node head;
  private Node tail;
  private int size;

  public LL() {
    head = null;
    tail = null;
    size = 0;
  }

  public void insertFirst(int data) {
    Node node = new Node(data);
    node.next = head;
    head = node;

    if (tail == null) {
      tail = head;
    }

    size++;
  }

  public void insertLast(int data) {
    if (tail==null) {
      insertFirst(data);
      return;
    }
    Node node = new Node(data);
    tail.next = node;
    tail = node;
    size++;
  }

  public void insertAtIndex(int index, int data) {
      if (index < 0 || index > size) {
          System.out.println("Invalid index");
          return;
      }
      if (index == 0) {
          insertFirst(data);
          }
      else if (index == size) {
        insertLast(data);
      } else {
          Node node = new Node(data);
          Node temp = head;
          for (int i = 0; i < index - 1; i++) {
              temp = temp.next;
          }
          node.next = temp.next;
          temp.next = node;
      }
      size++;
  }

  public void deleteFirst() {
        if (head != null) {
           head = head.next;
        }
  }

  public void deleteLast() {
        if (head == null || head.next == null) {
            
            head = null;
        } else {
            Node temp = head;
            while (temp.next.next != null) {
                temp = temp.next;
            }
            temp.next = null;
        }
  }

public void deleteAtIndex(int index) {
        if (index < 0 || head == null) {
            return;
        }

        if (index == 0) {
          head = head.next;
            return;
        }

        Node temp = head;
        int currentIndex = 0;

        while (temp != null && currentIndex < index - 1) {
            temp = temp.next;
            currentIndex++;
        }
        if (temp == null || temp.next == null) {
            return;
        }
        temp.next = temp.next.next;
}

    public boolean search(int value) {
        Node current = head;

        while (current != null) {
            if (current.data == value) {
                return true;
            }
            current = current.next;
        }
        return false;
    }
  
  public void display() {
    Node temp = head;
    while (temp != null) {
      System.out.print(temp.data + "->");
      temp = temp.next;
    }
    System.out.println("End");
  }

  
  public static void main(String[] args) {
    LL list = new LL();
    list.insertFirst(3);
    list.insertFirst(4);
    list.insertFirst(5);
    list.display();
    list.insertLast(2);
    list.insertLast(1);
    list.display();
    list.insertAtIndex(2,6);
    list.insertAtIndex(3,2);
    list.display();
    list.deleteFirst();
    list.display();
  }
}