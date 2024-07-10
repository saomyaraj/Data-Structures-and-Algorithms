class Circular_Queue {

    private int[] data;
    private static final int default_size=10;
    int end = 0;
    int front = 0;
    private int size = 0;

    public Circular_Queue() {
        this(default_size);
    }
    public Circular_Queue(int size) {
        this.data = new int[size];
    }
    public boolean isFull() {
        return size == data.length;
    }
    public boolean isEmpty() {
        return end == 0;
    }

    public boolean insert(int item) {
        if (isFull()) {
            return false;
        }
        data[end++] = item;
        end = end%data.length;
        size++;
        return true;
    }

    public int remove() throws Exception {
        if (isEmpty()) {
            throw new Exception("Queue is empty");
        }
        int removed = data[front];
        front = front % data.length;
        size--;
        return removed;
    }

    public int front() throws Exception {
        if (isEmpty()) {
            throw new Exception("Queue is empty");
        }
        return data[front];
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Empty");
            return;
        }
        int i = front;
        do {
            System.out.println(data[i] + " -> ");
            i++;
            i %= data.length;
        } while (i!=end);
        System.out.println("END");
    }
}