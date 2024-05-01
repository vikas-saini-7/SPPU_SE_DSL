/*

Problem Statement : There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. The cost of the edge can be the time that flight take to reach city B from A, or the amount of fuel used for the journey. Represent this as a graph. The node can be represented by airport name or name of the city. Use adjacency list representation of the graph or use adjacency matrix representation of the graph Check whether the graph is connected or not. Justify the storage representation used.
*/
#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    string city[20];
    int adj_matrix[50][50];

    cout << "Enter the number of cities: ";
    cin >> n;

    // Input city names
    for (int i = 0; i < n; i++) {
        cout << "Enter the name of city " << i + 1 << ": ";
        cin >> city[i];
    }

    // Input time required to travel between cities and construct adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if(i == j){
                adj_matrix[i][j] = 0;
                continue;
            }
            cout << "Enter the time required to travel from city " << city[i] << " to " << city[j] << ": ";
            cin >> adj_matrix[i][j];
            adj_matrix[j][i] = adj_matrix[i][j];
        }
    }

    // Print adjacency matrix
    cout << "\n\t";
    for (int i = 0; i < n; i++) {
        cout << city[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << city[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << adj_matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
