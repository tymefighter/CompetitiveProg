#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Infinity - denotes absence of edge or path
// between an ordered pair of vertices
const int INF = static_cast<int>(1e8);

// Class to create Error Objects
class Error {
    private:
        string msg; // error message
    public:
        Error(const string msg_):
            msg(msg_) {}

        ~Error() {}

        inline string what() {return msg;}
};

// Read the cost matrix (i.e. adjacency matrix)
// from the file located at the given file path
// if the file exists, else throw error
void readCost (
    const int n,                    // Number of nodes
    const string costFilePath,      // File path
    vector<vector<int> > &adjMat    // Adjacency matrix
) {
    ifstream ifs (costFilePath);    // Input file stream

    if(!ifs.is_open())  // Error in opening file, throw error
        throw Error("Error In Opening Cost File");
    
    adjMat.clear();
    adjMat.resize(n, vector<int>(n)); // Allocate adjacency matrix

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            string cost;
            ifs >> cost;     // Get cost from input file
            if(cost == "na") // No edge between i and j
                adjMat[i][j] = INF;
            else             // Edge is present with provided cost
                adjMat[i][j] = stoi(cost);
        }
    }

    ifs.close(); // Close file
}

void dijkstraSSSP (
    const vector<vector<int> > &adjMat, // Adjacency matrix
    const int s,                        // Source Vertex
    vector<int> &minCost,               // Output - Minimum cost to each vert
    vector<int> &prevVert               // Output - Predecessor to each vert
) {
    int n = adjMat.size();              // Get number of vertices
    vector<bool> computed(n, false);    // Initially no final costs have
                                        // been computed

    minCost.clear();
    minCost.assign(n, INF); // Allocate minimum distance array
    minCost[s] = 0;         // Minimum distance from source to itself is 0
    prevVert.clear();
    prevVert.assign(n, -1); // Allocate predecessor array

    while(true) {
        int leastCostVert = -1;     // This would contain the least cost vert
        int leastCostToVert = INF;  // This would contain cost to least cost vert

        for(int u = 0;u < n;u++) {  // Find least cost vert
            // If vert's final cost is not computed and has
            // lesser cost than current cost, make it the least
            if(!computed[u] && minCost[u] < leastCostToVert) {
                leastCostVert = u;
                leastCostToVert = minCost[u];
            }
        }

        // If no more vertices are left whose final cost has
        // to be computed, then break
        if(leastCostVert == -1)
            break;

        // Since vert has least cost, we know that it's cost
        // is the final cost
        computed[leastCostVert] = true;

        // for every vertex, try to check if there is a lower
        // cost path via vertex `leastCostVert`
        for(int v = 0;v < n;v++) {
            if(
                !computed[v]                    // value is not computed
                &&
                adjMat[leastCostVert][v] < INF  // and an edge is present
                &&
                leastCostToVert + adjMat[leastCostVert][v] < minCost[v] 
                // and path via `leastCostVert` has lesser cost
            ) {
                // then update cost and predecessor along path
                // from source `s` to vert `v`
                minCost[v] = leastCostToVert + adjMat[leastCostVert][v];
                prevVert[v] = leastCostVert;
            }
        }
    }
}

// Prints least cost path from source vertex to vert `v`
void printPath (
    int v, // Vertex to which the path is to be printed
    const vector<int> &prevVert // Predecessor array
) {
    if(v == -1) // We have come one step before source
        return;

    // print path from source to predecessor of v
    printPath(prevVert[v], prevVert);
    cout << v << " "; // then print v itself
}

void computeShortestPath (
    const int n,    // Number of vertices
    const int s,    // Source vertex
    const string costFilePath // File path
) {
    vector<vector<int> > adjMat; // Adjacency Matrix (Cost Matrix)
    vector<int> minCost, prevVert;
    // Arrays to be computed - minimum cost array
    // and predecessor array

    try { // If file is valid, then get adjacency matrix
        readCost(n, costFilePath, adjMat);
    }
    catch(Error &err) { // Else print error message and return
        cout << err.what() << "\n";
        return;
    }

    // Compute the shortest paths and shortest path costs
    dijkstraSSSP(adjMat, s, minCost, prevVert);

    for(int u = 0;u < n;u++) {
        if(minCost[u] == INF) // Path does not exist
            cout << "No path from " << s << " to " << u << "\n";
        else {  // Path exists, print minimum cost and the path itself
            cout 
                << "Path cost from "
                << s
                << " to "
                << u
                << " is "
                << minCost[u]
                << ", ";

            cout << "Path is as follows: ";
            printPath(u, prevVert);
            cout << "\n";
        }
    }
}

int main() {
    // Compute Shortest Paths and Print them
    computeShortestPath(8, 0, "costFile.txt");
    return 0;
}
