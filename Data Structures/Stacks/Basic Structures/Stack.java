public class Stack {

    public static void main(String[] args) throws Exception {
        Stack stack = new Stack(3);
        stack.push(3);
        stack.push(4);
        stack.push(5);

        System.out.println(stack.pop());
        System.out.println(stack.pop());
    }

    protected int[] data;
    private static final int default_size = 10;
    int ptr = -1;

    // Constructor to initialize the data array
    public Stack() {
        this(default_size);
    }

    public Stack(int size) {
        this.data = new int[size];
    }

    public boolean push(int item) {
        if (isFull()) {
            System.out.println("Stack is full.");
            return false;
        }
        ptr++;
        data[ptr] = item;
        return true;
    }

    public int pop() throws Exception {
        if (isEmpty()) {
            throw new Exception("Cannot pop from an empty stack");
        }
        int removed = data[ptr];
        ptr--;
        return removed;
    }

    public int peek() throws Exception {
        if (isEmpty()) {
            throw new Exception("Cannot peek from an empty stack");
        }
        return data[ptr];
    }

    private boolean isFull() {
        return ptr == data.length - 1;
    }

    private boolean isEmpty() {
        return ptr == -1;
    }

}
