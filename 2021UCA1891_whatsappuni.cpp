#include <iostream>
using namespace std;

class Queue
{
private:
    int arr[1000];
    int front, rear;

public:
    bool isEmpty()
    {
        if ((front == -1) || (front == (rear - 1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if ((front - rear) == 99)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int size()
    {
        return front - rear + 1;
    }
    void enqueue(int a)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
        }
        else
        {
            front++;
            arr[front] = a;
        }
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return 0;
        }
        else
        {
            int temp = arr[rear];
            rear++;
            return temp;
        }
    }
    void display()
    {
        for (int i = rear; i < front + 1; i++)
        {
            cout << arr[i] << "\n";
        }
    }
    Queue()
    {
        front = -1;
        rear = 0;
        for (int i = 0; i < 10; i++)
        {
            arr[i] = 0;
        }
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m; // N and M should both be less than 1000 to prevent queue overflow
    int stud;
    int arr[n][m];

    // Make all elements 0

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Make important elements 1

    for (int i = 0; i < m; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> stud;
            arr[stud - 1][i] = 1;
        }
    }

    // Print 2D array

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++)
    {
        int fake[n];
        int counter = 0;
        Queue grp;
        Queue student;
        int check1[m];
        int check2[n];

        // Initialise checks to 0

        for (int i = 0; i < m; i++)
        {
            check1[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            check2[i] = 0;
        }

        // Enqueue grps which first student is in

        for (int j = 0; j < m; j++)
        {
            if (check1[j] == 1) // Checks prevent duplicate entries in both student queue and grp queue
            {
                continue;
            }
            if (arr[i][j] == 1)
            {
                grp.enqueue(j);
                check1[j] = 1;
            }
        }

        if (grp.size() == 0)
            counter = 1; // If no grps found in an element it means fake msg only went to that person only (only 1)

        // Enqueue students which are in grps enqueued in loop 1

        while (grp.size() > 0)
        {
            int x = grp.dequeue();
            for (int i = 0; i < n; i++)
            {
                if (check2[i] == 1)
                {
                    continue;
                }
                if (arr[i][x] == 1)
                {
                    student.enqueue(i);
                    check2[i] = 1;
                    fake[counter] = i;
                    counter++;
                }
            }

            // Repeat until both group size and student size become 0

            while (student.size() > 0)
            {
                int y = student.dequeue();
                for (int j = 0; j < m; j++)
                {
                    if (check1[j] == 1)
                    {
                        continue;
                    }
                    if (arr[y][j] == 1)
                    {
                        grp.enqueue(j);
                        check1[j] = 1;
                    }
                }
            }
        }

        // Print final array
        // for (int i = 0; i < size; i++)
        // {
        //     cout << fake[i];
        // }
        // cout << endl;

        // Print size of final array

        cout << counter;
    }
    return 0;
}