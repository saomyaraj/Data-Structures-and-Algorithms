class TreeNode {
    int data;
    TreeNode left, right;

    public TreeNode(int item) {
        data = item;
        left = right = null;
    }
}

class BinaryTree {
    TreeNode root;

    public BinaryTree() {
        root = null;
    }

    // Insertion
    void insert(int data) {
        root = insertRec(root, data);
    }

    TreeNode insertRec(TreeNode root, int data) {
        if (root == null) {
            root = new TreeNode(data);
            return root;
        }

        if (data < root.data) {
            root.left = insertRec(root.left, data);
        } else if (data > root.data) {
            root.right = insertRec(root.right, data);
        }

        return root;
    }

    // In-order Traversal
    void inOrderTraversal(TreeNode root) {
        if (root != null) {
            inOrderTraversal(root.left);
            System.out.print(root.data + " ");
            inOrderTraversal(root.right);
        }
    }

    // Pre-order Traversal
    void preOrderTraversal(TreeNode root) {
        if (root != null) {
            System.out.print(root.data + " ");
            preOrderTraversal(root.left);
            preOrderTraversal(root.right);
        }
    }

    // Post-order Traversal
    void postOrderTraversal(TreeNode root) {
        if (root != null) {
            postOrderTraversal(root.left);
            postOrderTraversal(root.right);
            System.out.print(root.data + " ");
        }
    }

    // Search
    TreeNode search(int key) {
        return searchRec(root, key);
    }

    TreeNode searchRec(TreeNode root, int key) {
        if (root == null || root.data == key) {
            return root;
        }

        if (key < root.data) {
            return searchRec(root.left, key);
        }

        return searchRec(root.right, key);
    }

    // Deletion
    void delete(int key) {
        root = deleteRec(root, key);
    }

    TreeNode deleteRec(TreeNode root, int key) {
        if (root == null) {
            return root;
        }

        // Recursive calls to find the node to be deleted
        if (key < root.data) {
            root.left = deleteRec(root.left, key);
        } else if (key > root.data) {
            root.right = deleteRec(root.right, key);
        } else {
            // Node with only one child or no child
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            }

            // Node with two children
            root.data = minValue(root.right);

            // Delete the in-order successor
            root.right = deleteRec(root.right, root.data);
        }

        return root;
    }

    int minValue(TreeNode root) {
        int minValue = root.data;
        while (root.left != null) {
            minValue = root.left.data;
            root = root.left;
        }
        return minValue;
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();

        // Inserting nodes
        tree.insert(50);
        tree.insert(30);
        tree.insert(20);
        tree.insert(40);
        tree.insert(70);
        tree.insert(60);
        tree.insert(80);

        // In-order Traversal
        System.out.println("In-order Traversal:");
        tree.inOrderTraversal(tree.root);
        System.out.println();

        // Pre-order Traversal
        System.out.println("Pre-order Traversal:");
        tree.preOrderTraversal(tree.root);
        System.out.println();

        // Post-order Traversal
        System.out.println("Post-order Traversal:");
        tree.postOrderTraversal(tree.root);
        System.out.println();

        // Search
        int key = 40;
        TreeNode result = tree.search(key);
        if (result != null) {
            System.out.println(key + " found in the tree.");
        } else {
            System.out.println(key + " not found in the tree.");
        }

        // Deletion
        int keyToDelete = 30;
        System.out.println("Deleting node with key " + keyToDelete);
        tree.delete(keyToDelete);

        // In-order Traversal after deletion
        System.out.println("In-order Traversal after deletion:");
        tree.inOrderTraversal(tree.root);
        System.out.println();
    }
}