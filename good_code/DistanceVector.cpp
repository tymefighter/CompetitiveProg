#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

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

// Incident Edge Structure: -
// `vert`: vertex on which this edge is incident
// `wt`: weight of edge incident on this vertex
struct IncidentEdge {
    int vert, wt;
};

// Routing Table Entry Structure: -
// `vert`: Vertex to go to if we want to go
// to the destination corresponding to
// this routing table entry
// `minDist`: minimum distance to
// destination corresponding to
// this routing table entry
struct RoutingTableEntry {
    int vert, minDist;
};

// Routing Table of a router - vector of routing
// table entries, each corresponding to a router
// ith entry -> ith vertex is the destination
typedef vector<RoutingTableEntry> RoutingTable;

// Adjacency List Graph Representation
typedef vector<vector<IncidentEdge> > AdjacencyList;

// Read the cost matrix from the file located
// at the given file path if the file exists,
// else throw error
// Imp: This function constructs an Adjacency List
// from the Cost Matrix instead of directly using
// the cost matrix
void readCost (
    const int n,                 // Number of nodes
    const string costFilePath,   // File path
    AdjacencyList &network       // Network Graph's Adjacency List 
) {
    ifstream ifs (costFilePath); // Input file stream

    if(!ifs.is_open()) // Error in opening file, throw error
        throw Error("Error In Opening File");
    
    network.clear();
    network.resize(n); // Allocate space for network graph

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            string cost;
            ifs >> cost;     // Get cost from input files
            if(cost != "na") // Edge is Present
                network[i].push_back({j, stoi(cost)}); // (vert, edge cost)
        }
    }

    ifs.close(); // Close file
}

void distanceVectorRouting (
    const AdjacencyList &network,       // Network Graph's Adjacency List 
    vector<RoutingTable> &routingTables // Routing Tables which are to be built
) {
    int n = network.size();     // Number of vertices
    bool hasConverged = false;  // Has the algorithm coverged

    routingTables.assign(n, vector<RoutingTableEntry>(n));
    for(int i = 0;i < n;i++) { // Initialize Routing Tables
        for(int j = 0;j < n;j++) {
            if(i == j)  // We have this entry - vertex to itself
                routingTables[i][i] = {i, 0};
            else        // We do not have this entry
                routingTables[i][j] = {-1, INF};
        }
    }

    while(!hasConverged) { // While not converged
        hasConverged = true; // Assume convergence

        vector<int> updateOrder(n); // Order in which routers update their
                                    // entries
        for(int i = 0;i < n;i++) updateOrder[i] = i;
        random_shuffle(updateOrder.begin(), updateOrder.end()); // Permute indices

        for(int u : updateOrder) { // Source Vert
            for(int v = 0;v < n;v++) {  // Destination Vert
                int minVert = -1;
                int minDist = routingTables[u][v].minDist; // Computed Value

                // Try to update minimum distance from source to destination
                // via using a path via the neighbouring vertices
                for(const IncidentEdge &edge : network[u]) { // Go over neighbours
                    if(
                        // Path from neighbour to destination exists
                        routingTables[edge.vert][v].minDist < INF
                        &&
                        // Path from source to neighbour to destination
                        // has lower cost
                        edge.wt + routingTables[edge.vert][v].minDist < minDist
                    ) {
                        // Update which vertex to go to and the current minimum
                        // distance to destination
                        minVert = edge.vert;
                        minDist = edge.wt + routingTables[edge.vert][v].minDist;
                    }
                }

                if(minVert != -1) { // If table entry is to be updated
                    hasConverged = false; // Then not converged yet
                    routingTables[u][v] = {minVert, minDist}; // update entry
                }
            }
        }
    }
}

void buildRoutingTables (
    const int n,                // Number of vertices
    const string costFilePath   // File Path
) {
    AdjacencyList network;              // Network Graph's Adjacency List 
    vector<RoutingTable> routingTables; // Routing Tables of each vert

    try { // If file is valid, then build network graph
        readCost(n, costFilePath, network);
    }
    catch(Error &err) { // Else print error message and return
        cout << err.what() << "\n";
        return;
    }

    // Use Distance Vector Routing Algorithm to build routing
    // tables
    distanceVectorRouting(network, routingTables);

    // Print the routing tables for each vertex
    for(int u = 0;u < n;u++) {
        cout << "Routing Table for " << u << ": -\n";
        cout << "Destination | Vertex | Distance\n";
        for(int v = 0;v < n;v++)
            printf(
                "%11d | %6d | %8s\n",
                v,
                routingTables[u][v].vert,
                (
                    routingTables[u][v].minDist < INF ?
                        to_string(routingTables[u][v].minDist).c_str()
                        :
                        "na"
                )
            );
        cout << "\n";
    }
}

int main() {
    // Build the Routing Tables and print them
    buildRoutingTables(8, "costFile.txt");
    return 0;
}
