#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *child[1000]; // Each node can point to 1000 different nodes using these pointers
    int counter = 0;
    int check = 0;
    Node()
    {
        for (int i = 0; i < 1000; i++)
        {
            child[i] == NULL;
        }
    }
};

// void printConnections(Node* nodes[]){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<nodes[i]->counter;j++){
//             if(nodes[i]->child[j]==NULL)continue;
//             cout<<nodes[i]->data<<"->"<<nodes[i]->child[j]->data<<endl;
//         }
//     }
// }

void path(Node *root, int *pathlen, int level, int *p)
{
    Node *temp = root;
    if (temp->check == 1) // Base condition : already visited node
    {
        pathlen[*p] = level - 1;
        (*p)++;
        return;
    }
    if (temp->counter == 0) // Base conditon : leaf node
    {
        pathlen[*p] = level; // Insert current level value in pathlen
        (*p)++;
        return;
    }
    temp->check = 1; // Marks node as visited
    for (int i = 0; i < temp->counter; i++)
    {
        Node *temp2 = temp->child[i];
        path(temp2, pathlen, (level + 1), p);
    }
    return;
}

float mean(int *arr, int n)
{
    float mean = 0;
    for (int i = 0; i < n; i++)
    {
        mean += arr[i];
    }
    mean /= n;
    return mean;
}

int main()
{
    int x, y;
    int n;
    cin >> n;
    int pathlen[n];
    int p = 0;      // Counter for pathlen array
    Node *nodes[n]; // Array of pointers to each node

    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node();
        nodes[i] = temp;
    }
    Node *root = nodes[0];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        nodes[x - 1]->child[nodes[x - 1]->counter] = nodes[y - 1]; // Make x point to y
        (nodes[x - 1]->counter)++;
    }

    // Function to check whether tree has been made correctly

    // printConnections(nodes);

    // Function which recursively calculates all possible path lengths

    path(root, pathlen, 0, &p);

    // Print array with different path length values

    // for (int i = 0; i < p; i++)
    // {
    //     cout << pathlen[i] << "\t";
    // }
    // cout << endl;

    // Print mean of all path lengths

    cout << mean(pathlen, p);

    return 0;
}