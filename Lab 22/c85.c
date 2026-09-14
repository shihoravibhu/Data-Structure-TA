// 85. You are given an undirected graph with N nodes (numbered 1 through N).  
// For each valid i, the i-th node has a weight Wi. Also, for each pair of nodes i and 
// j, there is an edge connecting nodes if j – i ≠ Wj - Wi.  
 
// Find the number of connected components in this graph. 
 
// Input Format: 
//  The first line of the input contains a single integer T denoting the number of 
// test  cases. The description of T test cases follows. 
//  The first line of each test case contains a single integer N. 
//  The line contains N space-separated integers W1, W2, ..., WN. 
 
// Output Format : 
 
// For each test case, print a single line containing one integer --- the number of 
// components in the graph. 
 
// Sample Example: 
 
// Input: 
 
// 2 
// 2 
// 1 2  
// 2 
// 2 1 
// Output: 
 
// 2 
// 1

// There is an edge between nodes i and j if:
//
//      j - i != Wj - Wi
//
// No edge exists when:
//
//      j - i = Wj - Wi
//
// Rearranging:
//
//      j - Wj = i - Wi
//
// So for every node we define:
//
//      key = i - Wi
//
// If two nodes have the same key:
//      -> No edge between them.
//
// If two nodes have different keys:
//      -> Edge exists between them.
//
// Therefore:
//      Nodes having the same key form a group.
//
//      Inside a group:
//          No edges.
//
//      Between different groups:
//          All possible edges exist.
//
// This forms a complete multipartite graph.
//
// Case 1:
//      All nodes have the same key.
//
//      Example:
//          W = [1, 2]
//
//          1 - 1 = 0
//          2 - 2 = 0
//
//      No edges exist.
//      Hence every node is its own component.
//
//      Components = N
//
// Case 2:
//      At least two different keys exist.
//
//      Then every group is connected to every other group.
//      Therefore the whole graph becomes connected.
//
//      Components = 1
//
// So:
//      If all (i - Wi) values are equal:
//          Answer = N
//      Else:
//          Answer = 1

#include <stdio.h>

void main() {

    int T;
    scanf("%d", &T);

    while (T--) {

        int N;
        scanf("%d", &N);

        int W[N];

        for (int i = 0; i < N; i++) {
            scanf("%d", &W[i]);
        }

        int firstKey = 1 - W[0];
        int allSame = 1;

        for (int i = 1; i < N; i++) {

            int key = (i + 1) - W[i];

            if (key != firstKey) {
                allSame = 0;
                break;
            }
        }

        if (allSame)
            printf("%d\n", N);
        else
            printf("1\n");
    }

}