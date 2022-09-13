#include <iostream>
using namespace std;

int main()
{
    int t, n, temp;
    cout << "Enter the number of test cases:\n";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Enter the number of items:\n";
        cin >> n;
        int arr[2][n];
        int counter = 0;
        int mayur_sum = 0;
        int temp_arr[n];
        int arrboolfriend[n];

        // Entering elements in both arrays
        cout << "Enter the elements in 2D array form:\n";
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> arr[j][k];
            }
        }

        // // Print 2D array
        // for (int j = 0; j < 2; j++)
        // {
        //     for (int k = 0; k < n; k++)
        //     {
        //         cout << arr[j][k] << "  ";
        //     }
        //     cout << "\n";
        // }

        // Sorting
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[0][j] > arr[0][j + 1])
                {
                    temp = arr[0][j];
                    arr[0][j] = arr[0][j + 1];
                    arr[0][j + 1] = temp;
                    temp = arr[1][j];
                    arr[1][j] = arr[1][j + 1];
                    arr[1][j + 1] = temp;
                }
            }
        }

        // // Print Sorted Array
        // for (int j = 0; j < 2; j++)
        // {
        //     for (int k = 0; k < n; k++)
        //     {
        //         cout << arr[j][k];
        //     }
        //     cout << "\n";
        // }

        for (int i = 0; i < n; i++)
        {

            // Deciding the items of friends and appending in temporary array
            if (arr[0][i] <= arr[1][i])
            {
                temp_arr[counter] = arr[0][i];
                arrboolfriend[counter] = 1; // Selected for friend so don't check for mayur
                counter++;
            }

            // Deciding items of Mayur and increasing sum
            else
            {
                mayur_sum += arr[1][i];
                if (i == 0)
                {
                    continue;
                }
                for (int j = 0; j < i; j++)
                {
                    if (arrboolfriend[j] == 1)

                    // Already decided that friend will bring this item
                    {
                        continue;
                    }

                    // If sum increases minimum of friend list then friend should go instead of mayur
                    if (arr[0][j] <= mayur_sum)
                    {
                        mayur_sum -= arr[1][j];
                        temp_arr[counter] = arr[0][j];
                        arrboolfriend[counter] = 1; // Selected for friend so don't check for mayur
                        counter++;
                    }
                }
            }
        }
        // cout<<mayur_sum;

        temp_arr[counter] = mayur_sum;

        // // Print Temp Array
        // cout << "\nThe array is  ";
        // for (int j = 0; j < counter + 1; j++)
        // {
        //     cout << temp_arr[j] << " ";
        // }

        // Finding Max From Temp Array
        int max = temp_arr[0];
        for (int i = 1; i < counter + 1; i++)
        {
            if (temp_arr[i] > max)
            {
                max = temp_arr[i];
            }
        }

        // Printing Final Answer
        cout << "The minimum time to complete this task is : " << max << " seconds.\n";
    }
    return 0;
}