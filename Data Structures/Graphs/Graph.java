import java.util.*;

public class Graph {
    private Map<Integer, List<Integer>> adjacencyList;

    public Graph() {
        this.adjacencyList = new HashMap<>();
    }

    // Operation 1: Add a Vertex
    public void addVertex(int vertex) {
        adjacencyList.put(vertex, new ArrayList<>());
    }

    // Operation 2: Add an Edge
    public void addEdge(int source, int destination) {
        adjacencyList.get(source).add(destination);
        adjacencyList.get(destination).add(source); // For an undirected graph
    }

    // Operation 3: Remove a Vertex
    public void removeVertex(int vertex) {
        adjacencyList.remove(vertex);

        // Remove edges pointing to the vertex
        for (List<Integer> neighbors : adjacencyList.values()) {
            neighbors.removeIf(v -> v.equals(vertex));
        }
    }

    // Operation 4: Remove an Edge
    public void removeEdge(int source, int destination) {
        adjacencyList.get(source).remove(Integer.valueOf(destination));
        adjacencyList.get(destination).remove(Integer.valueOf(source)); // For an undirected graph
    }

    // Operation 5: Check if Vertex Exists
    public boolean containsVertex(int vertex) {
        return adjacencyList.containsKey(vertex);
    }

    // Operation 6: Check if Edge Exists
    public boolean containsEdge(int source, int destination) {
        return adjacencyList.get(source).contains(destination);
    }

    // Operation 7: Depth-First Search (DFS)
    public void dfs(int start) {
        Set<Integer> visited = new HashSet<>();
        dfsHelper(start, visited);
    }

    private void dfsHelper(int vertex, Set<Integer> visited) {
        System.out.print(vertex + " ");
        visited.add(vertex);

        for (int neighbor : adjacencyList.get(vertex)) {
            if (!visited.contains(neighbor)) {
                dfsHelper(neighbor, visited);
            }
        }
    }

    // Operation 8: Breadth-First Search (BFS)
    public void bfs(int start) {
        Set<Integer> visited = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();

        visited.add(start);
        queue.offer(start);

        while (!queue.isEmpty()) {
            int current = queue.poll();
            System.out.print(current + " ");

            for (int neighbor : adjacencyList.get(current)) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.offer(neighbor);
                }
            }
        }
    }

    public static void main(String[] args) {
        // Example usage of the Graph class
        Graph graph = new Graph();

        graph.addVertex(1);
        graph.addVertex(2);
        graph.addVertex(3);
        graph.addEdge(1, 2);
        graph.addEdge(2, 3);

        System.out.println("DFS starting from vertex 1:");
        graph.dfs(1);

        System.out.println("\nBFS starting from vertex 1:");
        graph.bfs(1);
    }
}

