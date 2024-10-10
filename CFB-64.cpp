#include <bits/stdc++.h>
using namespace std;

int text_c;
vector<vector<int>> input_bin;
vector<vector<vector<int>>> sBoxes =
{
    {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
    },
    {
        {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
        {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
        {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
        {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
    },
    {
        {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
        {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
        {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
        {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
    },
    {
        {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
        {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
        {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
        {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
    },
    {
        {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
        {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
        {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
        {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
    },
    {
        {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
        {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
        {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
        {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
    },
    {
        {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
        {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
        {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
        {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
    },
    {
        {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
        {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
        {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
        {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
    }
};

vector<int> ebit =
{
    32, 1, 2, 3, 4, 5,
    4, 5, 6, 7, 8, 9,
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1
};
vector<int> permutation =
{
    16, 7, 20, 21,
    29, 12, 28, 17,
    1, 15, 23, 26,
    5, 18, 31, 10,
    2, 8, 24, 14,
    32, 27, 3, 9,
    19, 13, 30, 6,
    22, 11, 4, 25
};

vector<int> inverseinitialpermutation =
{
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25
};

vector<vector<int>> text_to_binary_vector(const string& text)
{
    vector<vector<int>> binary_2d_vector;

    for (size_t i = 0; i < text.size(); i += 8)
    {
        vector<int> binary_row;

        for (size_t j = i; j < i + 8 && j < text.size(); j++)
        {
            bitset<8> binary_representation(text[j]);

            // Append the binary representation of the character to the row
            for (int k = 7; k >= 0; k--)
            {
                binary_row.push_back(binary_representation[k]);
            }
        }

        binary_2d_vector.push_back(binary_row);
    }

    // Display the binary_2d_vector
    for (const auto& row : binary_2d_vector)
    {
        for (int bit : row)
        {
            cout << bit;
        }
        cout << endl;
    }

    return binary_2d_vector;
}

int determineRow(int ar2dValue)
{
    if (ar2dValue == 0)
        return 0;
    else if (ar2dValue == 1)
        return 1;
    else if (ar2dValue == 2)
        return 2;
    else if (ar2dValue == 3)
        return 3;
    // Add more conditions if needed
    else
        return -1; // Invalid input
}
int determineColumn(const vector<int>& ar2dValues)
{
    int coll = 0;
    for (int i = 1; i < 5; ++i)
    {
        coll <<= 1;
        coll |= ar2dValues[i];
    }
    return coll;
}
int getSBoxValue(int row, int col, int row3d)
{
    return sBoxes[row3d][row][col];
}
vector<int> initialvector =
{
    1, 0, 1, 1, 0, 1, 0, 1,
    1, 1, 1, 0, 1, 0, 1, 1,
    0, 1, 0, 1, 1, 1, 0, 1,
    1, 1, 0, 1, 0, 0, 1, 1,
    1, 0, 1, 1, 0, 1, 1, 1,
    0, 1, 0, 1, 1, 1, 0, 1,
    0, 0, 1, 1, 1, 0, 1, 0,
    1, 1, 0, 1, 1, 0, 0, 1
};
vector<vector<int>> Cipher2d(100, vector<int>(64, 0));
vector<int>initialvector1=initialvector;

char binaryToAscii(const std::vector<int>& bits)
{
    if (bits.size() != 8)
    {
        // Ensure the input has exactly 8 bits
        std::cerr << "Error: Input must be an 8-bit binary sequence." << std::endl;
        return '\0'; // Return null character for error
    }

    int decimalValue = 0;
    for (int i = 0; i < 8; ++i)
    {
        decimalValue = (decimalValue << 1) | bits[i];
    }

    return static_cast<char>(decimalValue);
}

void encryption(int text_c)
{
    for(int s=0; s<text_c; s++)
    {
        //Example Key
        vector<int> example_key;
        example_key =
        {
            0, 0, 1, 1, 0, 1, 0, 0,
            0, 0, 1, 0, 1, 1, 0, 1,
            1, 0, 1, 1, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 0, 0,
            0, 0, 0, 1, 1, 1, 0, 1,
            1, 1, 0, 1, 1, 0, 1, 1,
            1, 0, 0, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 0, 0
        };


        /*string input_key;
        cout << "Enter a 64-bit key (8 characters): ";
        getline(cin, input_key);

        if (input_key.length() != 8)
        {
            cerr << "Error: Invalid key length. Please enter 8 characters." << endl;
            return 1;
        }

        for (char ch : input_key)
        {
            bitset<8> binary_representation(ch);

            for (int i = 7; i >= 0; i--)
            {
                example_key.push_back(binary_representation[i]);
            }
        }*/

        /*cout << "\nExample key is:" << endl;
        for (int i = 0; i < example_key.size(); i++)
        {
            cout << example_key[i] << ' ';
            if ((i + 1) % 8 == 0)
            {
                cout << endl;
            }
        }*/


        ////////////////////////////////////////////////////// 4. Permuted Choice � 1 (PC � 1) /////////////////////////////////////////////////
        vector<int> pc1 =
        {
            57, 49, 41, 33, 25, 17, 9,
            1, 58, 50, 42, 34, 26, 18,
            10, 2, 59, 51, 43, 35, 27,
            19, 11, 3, 60, 52, 44, 36,
            63, 55, 47, 39, 31, 23, 15,
            7, 62, 54, 46, 38, 30, 22,
            14, 6, 61, 53, 45, 37, 29,
            21, 13, 5, 28, 20, 12,4
        };
        //cout << "\After Permuted Choice: 1 (PC 1):" << endl;
        vector<int> per1;

        for (int i = 0; i < pc1.size(); i++)
        {
            int index = pc1[i];
            per1.push_back(example_key[index-1]);

            /*cout << per1.back() << ' ';
            if ((i + 1) % 7 == 0)
            {
                cout << endl;
            }*/
        }


        ///////////////////////////////////////////////////////////////// 5. Key Scheduler //////////////////////////////////////////////////////
        vector<int> pc2 =
        {
            14, 17, 11, 24, 1, 5,
            3, 28, 15, 6, 21, 10,
            23, 19, 12, 4, 26, 8,
            16, 7, 27, 20, 13, 2,
            41, 52, 31, 37, 47, 55,
            30, 40, 51, 45, 33, 48,
            44, 49, 39, 56, 34, 53,
            46, 42, 50, 36, 29, 32
        };
        vector<int> numberOfShifts =
        {
            1,1,2,2,
            2,2,2,2,
            1,2,2,2,
            2,2,2,1
        };

        vector<int> prev_key(per1.begin(), per1.end());
        vector<vector<int>> keys_16(16, vector<int>(48));
        for (int i = 0; i < 16; i++)
        {
            if(i==0 || i==1 || i==8 || i==15)
            {
                int last_bit_C_first_half = prev_key[0];
                rotate(prev_key.begin(), prev_key.begin() + 1, prev_key.begin() + 28);
                prev_key[27] = last_bit_C_first_half;

                int last_bit_D_second_half = prev_key[28];
                rotate(prev_key.begin() + 28, prev_key.begin() + 29, prev_key.end());
                prev_key[55] = last_bit_D_second_half;
            }
            else
            {
                int Second_last_bit_C_first_half = prev_key[0];
                int first_last_bit_C_first_half = prev_key[1];
                rotate(prev_key.begin(), prev_key.begin() + 2, prev_key.begin() + 28);
                prev_key[26] = Second_last_bit_C_first_half;
                prev_key[27] = first_last_bit_C_first_half;

                int Second_last_bit_D_first_half = prev_key[28];
                int first_last_bit_D_first_half = prev_key[29];
                rotate(prev_key.begin() + 28, prev_key.begin() + 30, prev_key.end());
                prev_key[54] = Second_last_bit_D_first_half;
                prev_key[55] = first_last_bit_D_first_half;
            }
            // Key generation using pc2
            for (int m = 0; m < 48; m++)
            {
                int tem = pc2[m] - 1;
                keys_16[i][m] = prev_key[tem];
            }
        }

        // Display the generated keys
        /*cout << "Generated keys:" << endl;
        for (int i = 0; i < 16; i++)
        {
            cout << "Round-" << i + 1 << " key : \n";
            for (int j = 0; j < 48; j++)
            {
                cout << keys_16[i][j] << " ";
                //if ((j + 1) % 6 == 0)
                //{
                //    cout << "\n";
                //}
            }
            cout << "\n";
        }*/

        //Only for the iterations greater than 0
        if(s>0)
        {
            for (int i = 0; i < 64; ++i)
            {
                initialvector[i] = Cipher2d[s-1][i];
            }
        }


        vector<int> initial_permutation =
        {
            58, 50, 42, 34, 26, 18, 10, 2,
            60, 52, 44, 36, 28, 20, 12, 4,
            62, 54, 46, 38, 30, 22, 14, 6,
            64, 56, 48, 40, 32, 24, 16, 8,
            57, 49, 41, 33, 25, 17, 9, 1,
            59, 51, 43, 35, 27, 19, 11, 3,
            61, 53, 45, 37, 29, 21, 13, 5,
            63, 55, 47, 39, 31, 23, 15, 7
        };

        //cout << "\After Initial Permutation (IP):" << endl;
        vector<int> initial_per;
        for (int i = 0; i < initial_permutation.size(); i++)
        {
            int index = initial_permutation[i]-1;
            initial_per.push_back(initialvector[index]);

            /*cout << initial_per.back() << ' ';
            if ((i + 1) % 8 == 0)
            {
                cout << endl;
            }*/
        }


        cout<<"\n----------------------------------ENCRYPTION------------------------------------\n";

        vector<int> temp;
        for(int a=0; a<16; a++)
        {

            int middle_index = initial_per.size() / 2;

            vector<int> first_half(initial_per.begin(), initial_per.begin() + middle_index);
            vector<int> second_half(initial_per.begin() + middle_index, initial_per.end());

            //E bit selection table
            vector<int> ebit_temp;
            //cout<<"E-bit\n";
            for (int i = 0; i < 48; i++)
            {
                int index = ebit[i]-1;
                ebit_temp.push_back(second_half[index]);

                /*cout << ebit_temp.back() << ' ';
                if ((i + 1) % 6 == 0)
                {
                    cout << endl;
                }*/
            }

            //XOR
            vector<int>x_or;
            for(int i=0; i<48; i++)
            {
                if((keys_16[a][i])==ebit_temp[i])
                {
                    x_or.push_back(0);
                }
                else
                {
                    x_or.push_back(1);
                }
                /*cout << x_or.back() << ' ';
                if ((i + 1) % 6 == 0)
                {
                    cout << endl;
                }*/
            }

            /*cout<<"\nAFTER XOR:\n";
            for(int i=0; i<48; i++)
            {
                cout<<x_or[i]<<" ";
                if ((i + 1) % 6 == 0)
                {
                    cout << endl;
                }
            }*/


            int numRows = 8;
            int numCols = 6;

            // Convert to 2D vector
            vector<vector<int>> result;

            if (x_or.size() == numRows * numCols)
            {
                for (int i = 0; i < numRows; ++i)
                {
                    vector<int> row(x_or.begin() + i * numCols, x_or.begin() + (i + 1) * numCols);
                    result.push_back(row);
                }
            }

            //S BOX
            vector<int> binaryValues;
            for (int i = 0; i < 8; ++i)
            {
                int row = determineRow((result[i][0] << 1) | result[i][5]);
                int col = determineColumn(result[i]);

                int value = getSBoxValue(row, col, i);

                //cout<<value<<" ";
                bitset<4> binaryValue(value);
                for (int j = 3; j >= 0; j--)
                {
                    binaryValues.push_back(binaryValue[j]);

                }

            }
            /*for(int i=0;i<32;i++)
            {
                cout<<binaryValues[i]<<" ";
            }*/

            //Permutation
            vector<int> after_per;
            //cout<<"permutation\n";
            for (int i = 0; i < 32; i++)
            {
                int index = permutation[i];
                after_per.push_back(binaryValues[index-1]);

                /*cout << after_per.back() << ' ';
                if ((i + 1) % 6 == 0)
                {
                    cout << endl;
                }*/
            }

            //Xor left right
            vector<int>x_or_temp;
            for(int i=0; i<32; i++)
            {
                if((first_half[i])==after_per[i])
                {
                    x_or_temp.push_back(0);
                }
                else
                {
                    x_or_temp.push_back(1);
                }
                /*cout << x_or_temp.back() << ' ';
                if ((i + 1) % 6 == 0)
                {
                    cout << endl;
                }*/
            }
            temp.clear();

            temp.insert(temp.end(), x_or_temp.begin(), x_or_temp.end());
            temp.insert(temp.end(), second_half.begin(), second_half.end());

            /*cout<<"Round\n";
            for(int i=0; i<64; i++)
            {
                cout<<temp[i]<<" ";
                if ((i + 1) % 8 == 0)
                {
                    cout << endl;
                }
            }*/
            cout<<"Encrypted ASCII values of Round:"<<a<<endl;
            for (int i = 0; i < 64; i += 8)
            {
                vector<int> group(temp.begin() + i, temp.begin() + i + 8);

                char asciiChar = binaryToAscii(group);

                if (asciiChar != '\0')
                {
                    cout << asciiChar << " ";
                }
            }

            cout<<endl;
            initial_per.clear();
            initial_per = temp;
        }

        ///////////////////// 7.inverse initial permutation////////////////
        vector<int> fin;
        //cout<<"\nEncryption of b-bits : \n";
        for (int i = 0; i < 64; i++)
        {
            int index = inverseinitialpermutation[i];
            fin.push_back(temp[index-1]);

            //cout << fin.back() << ' ';
            if ((i + 1) % 8 == 0)
            {
                //cout << endl;
            }
        }

        //selecting s bits
        vector<int>select_s(64);
        for (int i = 0; i < 64; ++i)
        {
            select_s[i] = fin[i];
        }
        /*for(int i=0;i<8;i++)
        {
            cout<<select_s[i]<<" ";
        }*/

        //Xor of s bits
        vector<int>cipher(64);
        for(int i=0; i<64; i++)
        {
            if((select_s[i])==input_bin[s][i])
            {
                cipher[i]=0;
            }
            else
            {
                cipher[i]=1;
            }
        }

        /*cout<<"Cipher Text:\n";
        for(int i=0; i<8; i++)
        {
            cout<<cipher[i]<<" ";
        }*/

        for(int i=0; i<64; i++)
        {
            Cipher2d[s][i]=cipher[i];
        }

    }

}


vector<vector<int>> decrypt2d(100, vector<int>(64, 0));
void decryption(int text_c)
{
    for(int s=0; s<text_c; s++)
    {
        //Example Key
        vector<int> example_key;
        example_key =
        {
            0, 0, 1, 1, 0, 1, 0, 0,
            0, 0, 1, 0, 1, 1, 0, 1,
            1, 0, 1, 1, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 0, 0,
            0, 0, 0, 1, 1, 1, 0, 1,
            1, 1, 0, 1, 1, 0, 1, 1,
            1, 0, 0, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 0, 0
        };


        /*string input_key;
        cout << "Enter a 64-bit key (8 characters): ";
        getline(cin, input_key);

        if (input_key.length() != 8)
        {
            cerr << "Error: Invalid key length. Please enter 8 characters." << endl;
            return 1;
        }

        for (char ch : input_key)
        {
            bitset<8> binary_representation(ch);

            for (int i = 7; i >= 0; i--)
            {
                example_key.push_back(binary_representation[i]);
            }
        }*/

        /*cout << "\nExample key is:" << endl;
        for (int i = 0; i < example_key.size(); i++)
        {
            cout << example_key[i] << ' ';
            if ((i + 1) % 8 == 0)
            {
                cout << endl;
            }
        }*/


        ////////////////////////////////////////////////////// 4. Permuted Choice � 1 (PC � 1) /////////////////////////////////////////////////
        vector<int> pc1 =
        {
            57, 49, 41, 33, 25, 17, 9,
            1, 58, 50, 42, 34, 26, 18,
            10, 2, 59, 51, 43, 35, 27,
            19, 11, 3, 60, 52, 44, 36,
            63, 55, 47, 39, 31, 23, 15,
            7, 62, 54, 46, 38, 30, 22,
            14, 6, 61, 53, 45, 37, 29,
            21, 13, 5, 28, 20, 12,4
        };
        //cout << "\After Permuted Choice: 1 (PC 1):" << endl;
        vector<int> per1;

        for (int i = 0; i < pc1.size(); i++)
        {
            int index = pc1[i];
            per1.push_back(example_key[index-1]);

            /*cout << per1.back() << ' ';
            if ((i + 1) % 7 == 0)
            {
                cout << endl;
            }*/
        }


        ///////////////////////////////////////////////////////////////// 5. Key Scheduler //////////////////////////////////////////////////////
        vector<int> pc2 =
        {
            14, 17, 11, 24, 1, 5,
            3, 28, 15, 6, 21, 10,
            23, 19, 12, 4, 26, 8,
            16, 7, 27, 20, 13, 2,
            41, 52, 31, 37, 47, 55,
            30, 40, 51, 45, 33, 48,
            44, 49, 39, 56, 34, 53,
            46, 42, 50, 36, 29, 32
        };
        vector<int> numberOfShifts =
        {
            1,1,2,2,
            2,2,2,2,
            1,2,2,2,
            2,2,2,1
        };

        vector<int> prev_key(per1.begin(), per1.end());
        vector<vector<int>> keys_16(16, vector<int>(48));
        for (int i = 0; i < 16; i++)
        {
            if(i==0 || i==1 || i==8 || i==15)
            {
                int last_bit_C_first_half = prev_key[0];
                rotate(prev_key.begin(), prev_key.begin() + 1, prev_key.begin() + 28);
                prev_key[27] = last_bit_C_first_half;

                int last_bit_D_second_half = prev_key[28];
                rotate(prev_key.begin() + 28, prev_key.begin() + 29, prev_key.end());
                prev_key[55] = last_bit_D_second_half;
            }
            else
            {
                int Second_last_bit_C_first_half = prev_key[0];
                int first_last_bit_C_first_half = prev_key[1];
                rotate(prev_key.begin(), prev_key.begin() + 2, prev_key.begin() + 28);
                prev_key[26] = Second_last_bit_C_first_half;
                prev_key[27] = first_last_bit_C_first_half;

                int Second_last_bit_D_first_half = prev_key[28];
                int first_last_bit_D_first_half = prev_key[29];
                rotate(prev_key.begin() + 28, prev_key.begin() + 30, prev_key.end());
                prev_key[54] = Second_last_bit_D_first_half;
                prev_key[55] = first_last_bit_D_first_half;
            }
            // Key generation using pc2
            for (int m = 0; m < 48; m++)
            {
                int tem = pc2[m] - 1;
                keys_16[i][m] = prev_key[tem];
            }
        }

        // Display the generated keys
        /*cout << "Generated keys:" << endl;
        for (int i = 0; i < 16; i++)
        {
            cout << "Round-" << i + 1 << " key : \n";
            for (int j = 0; j < 48; j++)
            {
                cout << keys_16[i][j] << " ";
                //if ((j + 1) % 6 == 0)
                //{
                //    cout << "\n";
                //}
            }
            cout << "\n";
        }*/

        //Only for the iterations greater than 0
        if(s>0)
        {
            for (int i = 0; i < 64; ++i)
            {
                initialvector1[i] = Cipher2d[s-1][i];
            }
        }


        vector<int> initial_permutation =
        {
            58, 50, 42, 34, 26, 18, 10, 2,
            60, 52, 44, 36, 28, 20, 12, 4,
            62, 54, 46, 38, 30, 22, 14, 6,
            64, 56, 48, 40, 32, 24, 16, 8,
            57, 49, 41, 33, 25, 17, 9, 1,
            59, 51, 43, 35, 27, 19, 11, 3,
            61, 53, 45, 37, 29, 21, 13, 5,
            63, 55, 47, 39, 31, 23, 15, 7
        };

        //cout << "\After Initial Permutation (IP):" << endl;
        vector<int> initial_per;
        for (int i = 0; i < initial_permutation.size(); i++)
        {
            int index = initial_permutation[i]-1;
            initial_per.push_back(initialvector1[index]);

            /*cout << initial_per.back() << ' ';
            if ((i + 1) % 8 == 0)
            {
                cout << endl;
            }*/
        }


        cout<<"\n----------------------------------DECRYPTION------------------------------------\n";

        vector<int> temp;
        for(int a=0; a<16; a++)
        {

            int middle_index = initial_per.size() / 2;

            vector<int> first_half(initial_per.begin(), initial_per.begin() + middle_index);
            vector<int> second_half(initial_per.begin() + middle_index, initial_per.end());

            //E bit selection table
            vector<int> ebit_temp;
            //cout<<"E-bit\n";
            for (int i = 0; i < 48; i++)
            {
                int index = ebit[i]-1;
                ebit_temp.push_back(second_half[index]);

                /*cout << ebit_temp.back() << ' ';
                if ((i + 1) % 6 == 0)
                {
                    cout << endl;
                }*/
            }

            //XOR
            vector<int>x_or;
            for(int i=0; i<48; i++)
            {
                if((keys_16[a][i])==ebit_temp[i])
                {
                    x_or.push_back(0);
                }
                else
                {
                    x_or.push_back(1);
                }
                /*cout << x_or.back() << ' ';
                if ((i + 1) % 6 == 0)
                {
                    cout << endl;
                }*/
            }

            /*cout<<"\nAFTER XOR:\n";
            for(int i=0; i<48; i++)
            {
                cout<<x_or[i]<<" ";
                if ((i + 1) % 6 == 0)
                {
                    cout << endl;
                }
            }*/


            int numRows = 8;
            int numCols = 6;

            // Convert to 2D vector
            vector<vector<int>> result;

            if (x_or.size() == numRows * numCols)
            {
                for (int i = 0; i < numRows; ++i)
                {
                    vector<int> row(x_or.begin() + i * numCols, x_or.begin() + (i + 1) * numCols);
                    result.push_back(row);
                }
            }

            //S BOX
            vector<int> binaryValues;
            for (int i = 0; i < 8; ++i)
            {
                int row = determineRow((result[i][0] << 1) | result[i][5]);
                int col = determineColumn(result[i]);

                int value = getSBoxValue(row, col, i);

                //cout<<value<<" ";
                bitset<4> binaryValue(value);
                for (int j = 3; j >= 0; j--)
                {
                    binaryValues.push_back(binaryValue[j]);

                }

            }
            /*for(int i=0;i<32;i++)
            {
                cout<<binaryValues[i]<<" ";
            }*/

            //Permutation
            vector<int> after_per;
            //cout<<"permutation\n";
            for (int i = 0; i < 32; i++)
            {
                int index = permutation[i];
                after_per.push_back(binaryValues[index-1]);

                /*cout << after_per.back() << ' ';
                if ((i + 1) % 6 == 0)
                {
                    cout << endl;
                }*/
            }

            //Xor left right
            vector<int>x_or_temp;
            for(int i=0; i<32; i++)
            {
                if((first_half[i])==after_per[i])
                {
                    x_or_temp.push_back(0);
                }
                else
                {
                    x_or_temp.push_back(1);
                }
                /*cout << x_or_temp.back() << ' ';
                if ((i + 1) % 6 == 0)
                {
                    cout << endl;
                }*/
            }
            temp.clear();

            temp.insert(temp.end(), x_or_temp.begin(), x_or_temp.end());
            temp.insert(temp.end(), second_half.begin(), second_half.end());

            /*cout<<"Round\n";
            for(int i=0; i<64; i++)
            {
                cout<<temp[i]<<" ";
                if ((i + 1) % 8 == 0)
                {
                    cout << endl;
                }
            }*/
            cout<<"Encrypted ASCII values of Round:"<<a<<endl;
            for (int i = 0; i < 64; i += 8)
            {
                vector<int> group(temp.begin() + i, temp.begin() + i + 8);

                char asciiChar = binaryToAscii(group);

                if (asciiChar != '\0')
                {
                    cout << asciiChar << " ";
                }
            }

            cout<<endl;
            initial_per.clear();
            initial_per = temp;
        }

        ///////////////////// 7.inverse initial permutation////////////////
        vector<int> fin;
        //cout<<"\nEncryption of b-bits : \n";
        for (int i = 0; i < 64; i++)
        {
            int index = inverseinitialpermutation[i];
            fin.push_back(temp[index-1]);

            //cout << fin.back() << ' ';
            if ((i + 1) % 8 == 0)
            {
                //cout << endl;
            }
        }

        //selecting s bits
        vector<int>select_s(64);
        for (int i = 0; i < 64; ++i)
        {
            select_s[i] = fin[i];
        }
        /*for(int i=0;i<8;i++)
        {
            cout<<select_s[i]<<" ";
        }*/

        //Xor of s bits
        vector<int>cipher(64);
        for(int i=0; i<64; i++)
        {
            if((select_s[i])==Cipher2d[s][i])
            {
                cipher[i]=0;
            }
            else
            {
                cipher[i]=1;
            }
        }

        /*cout<<"Cipher Text:\n";
        for(int i=0; i<8; i++)
        {
            cout<<cipher[i]<<" ";
        }*/

        for(int i=0; i<64; i++)
        {
            decrypt2d[s][i]=cipher[i];
        }

    }

}
int binaryToDecimal(const std::vector<int>& binaryRow)
{
    int decimalValue = 0;
    for (int i = 0; i < binaryRow.size(); ++i)
    {
        decimalValue += binaryRow[i] << (binaryRow.size() - 1 - i);
    }
    return decimalValue;
}

std::string decrypt2D(const std::vector<std::vector<int>>& matrix)
{
    std::string decryptedText;

    for (const std::vector<int>& row : matrix)
    {
        for (int i = 0; i < row.size(); i += 8)
        {
            std::vector<int> eightBits(row.begin() + i, row.begin() + i + 8);
            int decimalValue = binaryToDecimal(eightBits);
            char asciiChar = static_cast<char>(decimalValue);
            decryptedText += asciiChar;
        }
    }

    return decryptedText;
}
int main()
{
    string input_text;
    cout << "Enter an Input text: ";
    getline(cin, input_text);

    if (input_text.length() % 8 != 0)
    {
        cout << "Input text length must be a multiple of 8 !!!" << endl;
        return 1;
    }

    int temp = input_text.length();
    text_c = temp/8;

    input_bin = text_to_binary_vector(input_text);


    ////////////////////////////////////////////////////////Encryption//////////////////////////////////////////////////////
    encryption(text_c);
    cout<<"Encrypted:\n";
    for(int i=0; i<text_c; i++)
    {
        for(int j=0; j<64; j++)
        {
            cout<<Cipher2d[i][j]<<" ";
        }
        cout<<endl;
    }

    ////////////////////////////////////////////////////////Decryption//////////////////////////////////////////////////////

    decryption(text_c);
    cout<<"\nDecrypted:\n";
    for(int i=0; i<text_c; i++)
    {
        for(int j=0; j<64; j++)
        {
            cout<<decrypt2d[i][j]<<" ";
        }
        cout<<endl;
    }

    std::string result = decrypt2D(decrypt2d);
    std::cout << "Decrypted Text: " <<endl<< result << std::endl;


    return 0;
}


