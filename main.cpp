#include <iostream>
#include <vector>
#include "histogram.h"
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

void
svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg width='" << width << "' height='" << height << "' "
         << "viewBox='0 0 " << width << " " << height << "' "
         << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end()
{
    cout << "</svg>\n";
}

void
svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='" << baseline << "'>"<< text <<"</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke = "red", string fill = "blue")
{
    cout<<"<rect x='" << x <<"' y='" << y <<"' width='"<< width <<"' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "'/>";
}

void
show_histogram_svg(const vector<size_t>& bins)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    svg_text(TEXT_LEFT, TEXT_LEFT, to_string(bins[0]));
    double top = 0;
    for (size_t bin : bins)
    {
        const double bin_width = 10 * bin;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT);
        top += BIN_HEIGHT;
    }
    svg_end();
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
