
// int A[400 * 31 * 31][12], n;
// int B[400 * 31 * 31][12];
// int countVal[400 * 31 * 31][12];

// for(n = 1;n <= 961;n++) // 31 * 31 = 961
    // {
    //     for(i = 0;i < 400;i++)
    //     {
    //         for(j = 0;j < 12;j++)
    //         {
    //             int y = n * 400 + i;

    //             if(j == 0)
    //             {
    //                 A[y][j] = nextLong(11, y - 1 + 1, A[y - 1][11]);
    //                 B[y][j] = nextCook(11, y - 1 + 1, B[y - 1][11]);
    //             }
    //             else
    //             {
    //                 A[y][j] = nextLong(j - 1, y + 1, A[y][j - 1]);
    //                 B[y][j] = nextCook(j - 1, y + 1, B[y][j - 1]);
    //             }

    //             if(A[y][j] <= B[y][j] && B[y][j] <= A[y][j] + 10)
    //             {
    //                 if(y == 0 && j == 0)
    //                     countVal[y][j] = 1;
    //                 else if(j == 0)
    //                     countVal[y][j] = countVal[y - 1][11] + 1;
    //                 else
    //                     countVal[y][j] = countVal[y][j - 1] + 1;
    //             }
    //         }
    //     }

    //     if(A[n * 400][0] == A[0][0] && B[n * 400][0] == B[0][0])
    //         break;
    // }