#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    ifstream in ("dane5-3.txt");
	int bsum, mpop, nums[201] = {};
    int prev, curr;

    in >> curr;
    nums[curr+100]++;
    bsum = curr;

    while (!in.eof())
    {
        prev = curr;
        in >> curr;

        if (in.fail())
            break;

        nums[curr+100]++;

        int sum = curr + prev;
        if (sum > bsum)
            bsum = sum;

    }

    if (prev > bsum)
        bsum = prev;

    int pop = -1;
    for (int i = -100; i <= 100; i++)
    {
        if (nums[i+100] > pop)
        {
            pop = nums[i+100];
            mpop = i;
        }
    }

    in.close();

    cout << "Najlepsza suma: " << bsum << endl
        << "Najpopularniejszy element: " << mpop << endl;
    return 0;
}
