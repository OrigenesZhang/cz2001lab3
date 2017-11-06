package flights;

public class Main {
    public static void main(String[] args) {
        int numOfCities = 8;
        Graph graph = new Graph(numOfCities);
        graph.addEdge("Beijing", new String[] {"Hong Kong", "Shanghai", "Singapore", "Tokyo"});
        graph.addEdge("Hong Kong", new String[] {"Singapore", "Shanghai"});
        graph.addEdge("Singapore", new String[] {"Shanghai", "Sydney", "Tokyo","Seoul"});
        graph.addEdge("Shanghai", new String[] {"Seoul", "Tokyo"});
        graph.addEdge("Seoul", new String[] {"Tokyo", "Los Angeles"});
        graph.addEdge("Tokyo", "Los Angeles");

        graph.addCity("Hawaii");
        graph.BFS("Hong Kong", "Los Angeles");
        // String flights = graph.DFS("Beijing", "Sydney");
    }
}
