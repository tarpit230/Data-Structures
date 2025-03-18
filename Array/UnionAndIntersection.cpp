// Union of two arrays is an array having all distinct elements that are present in either array whereas
// Intersection of two arrays is an array containing distinct common elements between the two arrays.

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void Union(int a[], int b[], int aSize, int bSize)
    {
        set<int> uniqueElements;
        for (int i = 0; i < aSize; i++)
            uniqueElements.insert(a[i]);
        for (int i = 0; i < bSize; i++)
            uniqueElements.insert(b[i]);

        int size = uniqueElements.size();

        int c[size];
        int idx = 0;
        for (int i = 0; i < aSize; i++)
        {
            if (find(c, c + size, a[i]) == c + size)
            {
                c[idx++] = a[i];
            }
        }
        for (int i = 0; i < bSize; i++)
        {
            if (find(c, c + size, b[i]) == c + size)
            {
                c[idx++] = b[i];
            }
        }
        for (int i = 0; i < size; i++)
        {
            cout << c[i] << " ";
        }
    }

    void Intersection(int a[], int b[], int aSize, int bSize)
    {
        set<int> result;
        set<int> setB(b, b + bSize);

        for (int i = 0; i < aSize; i++)
        {
            if (setB.count(a[i]))
            {
                result.insert(a[i]);
            }
        }
        for (int num : result)
        {
            cout << num << " ";
        }
    }
};

int main()
{
    int a[] = {1, 1, 2, 2, 2, 4};
    int b[] = {2, 2, 4, 4};

    int aSize = sizeof(a) / sizeof(a[0]);
    int bSize = sizeof(b) / sizeof(b[0]);

    Solution obj;
    obj.Union(a, b, aSize, bSize);
    cout<< endl;
    obj.Intersection(a, b, aSize, bSize);

    return 0;
}