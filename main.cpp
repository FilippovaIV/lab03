#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
using namespace std;
vector<double>
input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}
vector<size_t>
make_histogram(vector<double>numbers, size_t bin_count)
{
    double h;
    double min,max;
    find_minmax(numbers, min, max);
    h=(max-min)/bin_count;
    vector <size_t> bins (bin_count);
    for (double number: numbers)
    {
        for (size_t i=0; i<bin_count; i++)
        {
            if ((number>=(min+h*(i))) && (number<(min+h*(i+1))))
            {
                bins[i]++;
            }
            if (i>=bin_count)
            {
                i=bin_count-1;
            }
        }
        if (number==max)
        {
            bins [bin_count-1]++;
        }
    }
    return bins;
}
int main()
{
    string da_net;
    da_net="n";
    size_t number_count;
    cin >> number_count;
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    do
    {
        cerr<<"Enter bin count\n";
        cin>>bin_count;
        const auto bins = make_histogram(numbers, bin_count);
        show_histogram_svg(bins);
        cerr<<"WI dowolny? (da/net)\n";
        cin>>da_net;
    }
    while (da_net!="da");
    return 0;
}
