#include "histogram.h"
void
find_minmax(vector<double> numbers, double& min, double& max)
{
    if (numbers.size()==0)
    {
        min=0;
        max=0;
    }
    else
    {
        min = numbers[0];
        max=numbers[0];
        for (int i=0; i<numbers.size(); i++)
        {
            if(min>numbers[i])
            {
                min=numbers[i];
            }
            if (max<numbers[i])
            {
                max=numbers[i];
            }
        }
    }
}
