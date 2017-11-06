package flights;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class Graph {

    private HashMap<String, Vertex> cities;
    public long CPUTime;

    public Graph() {
        cities = new HashMap<>();
    }

    public Graph(int numOfVertices) {
        cities = new HashMap<>(numOfVertices);
    }

    /**
     * used to add a single node in the graph without any edges connected to it
     * @param cityName
     */
    public void addCity(String cityName) {
        if(!cities.containsKey(cityName))
            cities.put(cityName, new Vertex(cityName));
    }

    /**
     * add an edge between two nodes
     * the graph is undirected
     * @param city1
     * @param city2
     */
    public void addEdge(String city1, String city2) {
        if (!cities.containsKey(city1))
            cities.put(city1, new Vertex(city1));

        if (!cities.containsKey(city2))
            cities.put(city2, new Vertex(city2));

        Vertex v1 = cities.get(city1);
        Vertex v2 = cities.get(city2);

        if(!v1.neighbours.contains(v2))
            v1.neighbours.add(v2);

        if(!v2.neighbours.contains(v1))
            v2.neighbours.add(v1);
    }

    /**
     * add a list of edges to a single node
     * @param city
     * @param neighbours nodes adjacent to the node
     */
    public void addEdge(String city, String[] neighbours) {
        if (!cities.containsKey(city))
            cities.put(city, new Vertex(city));

        Vertex v1 = cities.get(city);

        for (String neighbour: neighbours) {
            if(!cities.containsKey(neighbour))
                cities.put(neighbour, new Vertex(neighbour));

            Vertex v2 = cities.get(neighbour);

            if(!v1.neighbours.contains(v2))
                v1.neighbours.add(v2);

            if(!v2.neighbours.contains(v1))
                v2.neighbours.add(v1);
        }

    }

    /**
     * BFS search on the graph
     * @param departure
     * @param arrival
     */
    public void BFS (String departure, String arrival) {
        if (!(cities.containsKey(departure) && cities.containsKey(arrival))){
            System.out.println("City not found!");
            return;
        }

        Vertex src = cities.get(departure);
        Vertex dest = cities.get(arrival);

        for(Vertex v : cities.values()) {
            v.visited = false;
            v.parent = null;
        }

        Queue<Vertex> queue = new LinkedList<>();
        queue.add(src);

        boolean foundPath = false;
        this.CPUTime = 0;
        long startTime = System.nanoTime();

        while (!queue.isEmpty() && !foundPath) {
            Vertex current = queue.poll();
            for(Vertex neighbour : current.neighbours) {
                if (!neighbour.visited) {
                    neighbour.visited = true;
                    queue.add(neighbour);
                    neighbour.parent = current;

                    if(neighbour.compareTo(dest) == 0) {
                        foundPath = true;
                        break;
                    }
                }
            }
        }

        showPath(src, dest, foundPath);
    }

    /**
     * DFS search to find a path
     * @param departure
     * @param arrival
     */
    public void DFS (String departure, String arrival) {
        if (!(cities.containsKey(departure) && cities.containsKey(arrival))){
            System.out.println("City not found!");
            return;
        }

        Vertex src = cities.get(departure);
        Vertex dest = cities.get(arrival);

        for(Vertex v : cities.values()) {
            v.visited = false;
            v.parent = null;
        }

        this.CPUTime = 0;
        long startTime = System.nanoTime();
        boolean foundPath = DFSUtil(src, dest);
        this.CPUTime = System.nanoTime() - startTime;

        showPath(src, dest, foundPath);
    }

    private boolean DFSUtil(Vertex src, Vertex dest) {
        src.visited = true;

        for(Vertex neighbour : src.neighbours) {
            if(!neighbour.visited) {
                neighbour.parent = src;
                if (neighbour.compareTo(dest) == 0)
                    return true;
                else if (DFSUtil(neighbour, dest))
                    return true;
            }
        }
        return false;
    }

    /**
     * Called after the search algorithm to display the result.
     * @param src
     * @param dest
     * @param foundPath
     */

    private void showPath(Vertex src, Vertex dest, boolean foundPath){
        System.out.println("Time Taken:" + this.CPUTime);
        this.CPUTime = 0;

        if(!foundPath){
            System.out.println("Can not find a path between " + src.toString() +
                    " and " + dest.toString());
            return;
        }

        StringBuilder path = new StringBuilder();
        String arrow = " --> ";
        path.append(dest.toString());

        for(Vertex v = dest.parent; v.compareTo(src) != 0; v = v.parent)
            path.insert(0, v.toString() + arrow);

        path.insert(0,src.toString() + arrow);
        System.out.println(path);
    }
}
