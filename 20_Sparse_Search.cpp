#include <bits/stdc++.h>
using namespace std;

int sparseSearch(string arr[], int n, string key)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == "")
        {
            int mid_l = mid - 1;
            int mid_r = mid + 1;
            while (1)
            {
                if (mid_l < s && mid_r > e)
                    return -1;
                else if (mid_l >= s && arr[mid_l] != "")
                {  
                    mid = mid_l;
                    break;
                }
                else if (mid_r <= e && arr[mid_r] != "")
                {
                    mid = mid_r;
                    break;
                }
                mid_l--;
                mid_r++;
            }
        }
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

int main()
{
    string arr[] = {"abc", "", "", "car", "dog", "", "", "ele", "", "xyz"};
    int n = 10;
    cout << sparseSearch(arr, 10, "car") << endl;

    return 0;
}