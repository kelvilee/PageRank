//
// Created by Kelvin Lee on 2019-10-11.
//
#include "pagerank.hpp"

void execute_page_rank() {
    try {
        // ********* CONNECTIVITY MATRIX ***********
        ifstream input{"connectivity.txt"};
        if(!input.is_open()) {
            cerr << "Unable to open file" << endl;
            exit(1);
        }
        int num = 0;
        int a;
        while(input >> a) {
            num++;
        }
        input.clear();
        input.seekg(0);

        double arr_1[num];
        int k = 0;
        while(input >> a) {
            arr_1[k] = a;
            k++;
        }
        myMatrix con{arr_1, num};
        cout << "Connection Matrix\n" << con << endl;

        //********** TELEPORTATION MATRIX ***************
        int t_num = (int) sqrt(num);
        myMatrix t_matrix{t_num};
        for(int i = 0; i < t_num; i++) {
            for(int j = 0; j < t_num; j++) {
                t_matrix.set_value(i, j, 1.0 / t_num);
            }
        }
        cout << "Teleportation Matrix\n" <<t_matrix << endl;

        //********** DEGREE MATRIX ***************
        double degree_c[4];
        cout << "Degree 'Matrix'" << endl;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                degree_c[i] += con.get_value(j, i);
            }
            cout << degree_c[i] << endl;
        }

        //************ STOCHIASTIC MATRIX ***********
        cout << "\nStochiastic Matrix" << endl;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                double val = con.get_value(i , j);
                if (degree_c[i] == 0)
                    con.set_value(i, j, 0.25);
                else if(val != 0)
                    con.set_value(i, j, val/degree_c[i]);
            }
        }
        cout << con << endl;

//        // transition matrix
//        myMatrix transition{4};
//        for(int i = 0; i < 4; i++)
//        {
//            for(int j = 0; j < 4; j++)
//            {
//                double val = con.get_value(i, j);
//                con.set_value(i, j, val * p);
//            }
//        }
//        for(int i = 0; i < 4; i++)
//        {
//            for(int j = 0; j < 4; j++)
//            {
//                double val = teleport_matrix.get_value(i, j);
//                teleport_matrix.set_value(i, j, val * (1 - p));
//            }
//        }
//        transition = con + teleport_matrix;
//        cout << "Transition Matrix" << endl;
//        cout << transition << endl;
//
//        // column matrix rank
//        myMatrix col_rank{4, 1};
//        for(int i = 0; i < 4; i++)
//        {
//            col_rank.set_value(i, 0, 1.0);
//        }
//        cout << "Column Rank Matrix\n" << col_rank << endl;
//
//        // markov process
//        cout << transition * col_rank << endl;
//        int count = 1;
//        while(transition * col_rank != col_rank) {
//            col_rank = transition * col_rank;
//            cout << "Iteration: " << count++ << endl;
//            cout << col_rank << endl;
//        }
//
//
    } catch (invalid_argument& ia) { cout << ia.what() << endl; }
}
