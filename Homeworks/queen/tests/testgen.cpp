#include <iostream>
#include <stdio.h>
#include <random>
using namespace std;

mt19937 mt(1337);

int n, m, mx, my, k;

int randInt(int L, int R)
{
    return mt() % (R - L + 1) + L;
}

void generateTest(int testType, int maxVals)
{
    if (maxVals == 8)
    {
        if (testType == 0)
        {
            n = 8;
            m = 8;
            mx = 8 - randInt(0, 1);
            my = 8 - randInt(0, 1);
            k = 8 - randInt(0, 1);

            return;
        }
        else
            testType = 4;
    }

    if (testType == 0)
    {
        n = maxVals - randInt(0, 3);
        m = maxVals - randInt(0, 3);
        mx = maxVals - randInt(0, 10);
        my = maxVals - randInt(0, 10);
        k = maxVals - randInt(0, 10);
    }
    else if (testType == 1)
    {
        n = maxVals - randInt(0, 3);
        m = maxVals - randInt(0, 3);
        mx = maxVals / 2 - randInt(0, 3);
        my = maxVals / 2 - randInt(0, 3);
        k = maxVals / 2 - randInt(0, 3);
    }
    else if (testType == 2)
    {
        n = maxVals - randInt(0, 5);
        m = maxVals - randInt(0, 5);
        mx = maxVals / 10 - randInt(0, 3);
        my = maxVals / 10 - randInt(0, 3);
        k = maxVals - randInt(0, 5);
    }
    else if (testType == 3)
    {
        n = maxVals - randInt(0, 5);
        m = maxVals - randInt(0, 5);
        mx = max(1, maxVals / 10 - randInt(0, 3));
        my = max(1, maxVals / 10 - randInt(0, 3));
        k = max(1, maxVals / 8 - randInt(0, 3));
    }
    else if (testType == 4)
    {
        n = randInt(1, maxVals);
        m = randInt(1, maxVals);
        mx = randInt(1, n);
        my = randInt(1, m);
        k = randInt(1, maxVals);
    }
}

int main()
{
    const int TEST_TYPES = 5;
    const int ITERATIONS = 2;
    const int SUBTASKS[] = {8, 50, 300, 1000, 3000, 10000};
    const int SUBTASK_COUNT = (sizeof(SUBTASKS)/sizeof(*SUBTASKS));
    int testNo = 0;

    for (int i = 0; i < SUBTASK_COUNT; i++)
    {
        for (int j = 0; j < TEST_TYPES; j++)
        {
            for (int in = 0; in < ITERATIONS; in++)
            {
                testNo++;

                generateTest(j, SUBTASKS[i]);
                string s = "jumps.";
                s.push_back(testNo / 10 + '0');
                s.push_back(testNo % 10 + '0');
                s += ".in";

                FILE *f = fopen(s.c_str(), "w");
                fprintf(f, "%d %d %d %d %d\n", n, m, mx, my, k);
                fclose(f);
            }
        }
    }

    return 0;
}
