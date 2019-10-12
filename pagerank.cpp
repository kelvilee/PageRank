//
// Created by Kelvin Lee on 2019-10-11.
//
#include "pagerank.hpp"

void execute_page_rank() {
    try {
        // ********* CONNECTIVITY MATRIX ***********
        ifstream input{"connectivity.txt"};
        if (!input.is_open()) {
            cerr << "Unable to open file" << endl;
            exit(1);
        }
        int num_of_elements = 0;
        int tmp_num = 0;
        while (input >> tmp_num) {
            num_of_elements++;
        }
        input.clear();
        input.seekg(0);

        double arr_1[num_of_elements];
        const int size = (int) sqrt(num_of_elements);
        int k = 0;
        while (input >> tmp_num) {
            arr_1[k] = tmp_num;
            k++;
        }
        myMatrix con_matrix{arr_1, num_of_elements};


        //********** DEGREE MATRIX ***************
        myMatrix deg_matrix{1, size};
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (con_matrix.get_value(i, j) == 1)
                    deg_matrix.set_value(0, j, (deg_matrix.get_value(0, j) + 1));
            }
        }

        //************ STOCHIASTIC MATRIX ***********
        myMatrix stoch_matrix = con_matrix;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                double con_val = con_matrix.get_value(i, j);
                double deg_val = deg_matrix.get_value(0, j);
                if (0 == deg_val)
                    stoch_matrix.set_value(i, j, (1.0 / size));
                else
                    stoch_matrix.set_value(i, j, (con_val / deg_matrix.get_value(0, j)));
            }
        }

        //********** TELEPORTATION MATRIX ***************
        myMatrix tele_matrix{size};
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                tele_matrix.set_value(i, j, 1.0 / size);
            }
        }

        //************ TRANSITION MATRIX ***********
        myMatrix trans_matrix{size};
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                double val = stoch_matrix.get_value(i, j);
                stoch_matrix.set_value(i, j, (val * p));
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                double val = tele_matrix.get_value(i, j);
                tele_matrix.set_value(i, j, (val * (1 - p)));
            }
        }
        trans_matrix = stoch_matrix + tele_matrix;

        //************ COLUMN MATRIX RANK ***********
        myMatrix col_rank{size, 1};
        for (int i = 0; i < size; i++) {
            col_rank.set_value(i, 0, 1);
        }

        //************ MARKOV PROCESS ***********
        while (trans_matrix * col_rank != col_rank) {
            col_rank = trans_matrix * col_rank;
        }

        //************ PAGE RANK ***********
        double sum = 0;
        const double percent = 100;
        for(int i = 0; i < size; i++) {
            sum += col_rank.get_value(i, 0);
        }

        for(int i = 0; i < size; i++) {
            col_rank.set_value(i, 0, (percent * col_rank.get_value(i, 0) / size));
            switch(i) {
                case 0 :
                    cout << "Page A: " << fixed << setprecision(2) << col_rank.get_value(i, 0)  << "%" << endl;
                    break;
                case 1 :
                    cout << "Page B: " << col_rank.get_value(i, 0) << "%" << endl;
                    break;
                case 2 :
                    cout << "Page C: " << col_rank.get_value(i, 0) << "%" << endl;
                    break;
                case 3 :
                    cout << "Page D: " << setw(5) << right << col_rank.get_value(i, 0) << "%" << endl;
                    break;
                default:
                    break;
            }
        }
    } catch (invalid_argument &ia) { cout << ia.what() << endl; }
}
