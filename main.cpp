#include <iostream>
#include <vector>
using namespace std;
double koef=1;

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

void
find_minmax(vector<double> numbers, double& min, double& max)
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
    size_t minbin,maxbin;
    const size_t MAX_WiDTH = 76;
    minbin=999;
    maxbin=0;
    for (size_t bin : bins)
    {
        if (bin < minbin)
        {
            minbin = bin;
        }
        if (bin > maxbin)
        {
            maxbin = bin;
        }
    }
    double koef;
    koef=1;
    if (maxbin>MAX_WiDTH)
    {
        koef=(static_cast<double>(MAX_WiDTH)/maxbin);
    }
    return bins;
}

void
show_histogram_text(vector <size_t> bins)
{
    for (size_t bin: bins)
    {
        if (bin<100)
        {
            cout<<" ";
        }
        if (bin<10)
        {
            cout<<" ";
        }
        cout<<bin<<"|";
        for (size_t i=0; i<bin*koef; i++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
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
        show_histogram_text(bins);
        cerr<<"WI dowolny? (da/net)\n";
        cin>>da_net;
    }
    while (da_net!="da");
    return 0;
}
