package flights;

import java.util.ArrayList;

public class Vertex implements Comparable<Vertex>{
    private final String city;
    public ArrayList<Vertex> neighbours;
    public boolean visited;
    public Vertex parent;

    public Vertex(String cityName) {
        this.city = cityName;
        neighbours = new ArrayList<>();
        visited = false;
    }

    public String toString() { return city;}

    @Override
    public int compareTo(Vertex o) {
        return this.city.compareTo(o.city);
    }
}
