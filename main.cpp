#include <iostream>
#include "matrix.hpp"

using namespace std;
constexpr int n = 16;

int main() {
    try {
        double p{0.85};
        double degree_c[4];
        double arr[n] = {0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0};
        myMatrix connectivity_matrix{arr, n};

        double arr_2[n] = {0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25};
        myMatrix teleport_matrix{arr_2, n};
        cout << "Connectivity Matrix\n" << connectivity_matrix << endl;
        // degree col
        cout << "Degree Matrix" << endl;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                degree_c[i] += connectivity_matrix.get_value(j, i);
            }
            cout << degree_c[i] << endl;
        }

        cout << "\nStochiastic Matrix" << endl;
        // stochiastic matrix
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                double val = connectivity_matrix.get_value(j, i);
                if (degree_c[i] == 0)
                    connectivity_matrix.set_value(j, i, 0.25);
                else if(val != 0)
                    connectivity_matrix.set_value(j, i, val/degree_c[i]);
            }
        }
        cout << connectivity_matrix << endl;

        // transition matrix
        myMatrix transition{4};
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                double val = connectivity_matrix.get_value(i, j);
                connectivity_matrix.set_value(i, j, val * p);
            }
        }
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                double val = teleport_matrix.get_value(i, j);
                teleport_matrix.set_value(i, j, val * (1 - p));
            }
        }
        transition = connectivity_matrix + teleport_matrix;
        cout << "Transition Matrix" << endl;
        cout << transition << endl;

        // column matrix rank
        myMatrix col_rank{4, 1};
        for(int i = 0; i < 4; i++)
        {
            col_rank.set_value(i, 0, 1.0);
        }
        cout << "Column Rank Matrix\n" << col_rank << endl;

        // markov process
//        cout << transition * col_rank << endl;
        int count = 1;
        while(transition * col_rank != col_rank) {
            col_rank = transition * col_rank;
            cout << "Iteration: " << count++ << endl;
            cout << col_rank << endl;
        }


    } catch (const char * msg) {
        cerr << msg << endl;
    }
    return 0;
}