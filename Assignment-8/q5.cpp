#include <bits/stdc++.h>
using namespace std;

class priorityQueue
{
    int idx;
    int arr[100];

public:
    priorityQueue() : idx(1) {}

    int top()
    {
        if (!size())
        {
            cout << "Empty" << endl;
            return -1;
        }
        return arr[1];
    }

    void push(int val)
    {
        arr[idx] = val;

        int i = idx;
        idx++;

        while (i > 1)
        {
            int p = i / 2;
            if (arr[p] > arr[i])
            {
                swap(arr[i], arr[p]);
                i = p;
            }
            else
                break;
        }
    }

    void pop()
    {
        if (!size())
            return;

        idx--;
        arr[1] = arr[idx];
        int i = 1;

        while (i < idx)
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            int smallest = i;

            if (left < idx && arr[left] < arr[smallest])
                smallest = left;
            if (right < idx && arr[right] < arr[smallest])
                smallest = right;

            if (smallest != i)
            {
                swap(arr[i], arr[smallest]);
                i = smallest;
            }
            else
                break;
        }
    }

    int size()
    {
        return idx - 1;
    }
};



void heapSort(vector<int>& v)
{
    priorityQueue pq;

    
    for (int x : v)
        pq.push(x);

  
    int idx = 0;
    while (pq.size())
    {
        v[idx++] = pq.top();
        pq.pop();
    }
}


int main()
{
    vector<int> arr = {10, 3, 15, 7, 8, 23, 74, 18};

    heapSort(arr);

    cout << "Sorted array using heapsort: ";
    for (int x : arr)
        cout << x << " ";

    return 0;
}
