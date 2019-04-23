#include "svg.h"
double
mashtab (vector <size_t> bins)
{
    size_t maxbin;
    const size_t MAX_WiDTH = 350;
    maxbin=0;
    for (size_t bin : bins)
    {
        if (bin > maxbin)
        {
            maxbin = bin;
        }
    }
    double koef;
    koef=1;
    maxbin = maxbin * 10;
    if (maxbin > MAX_WiDTH)
    {
        koef=(static_cast<double>(MAX_WiDTH)/maxbin);
    }
    return koef;
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
void
svg_rect(double x, double y, double width, double height, string stroke = "red", string fill = "blue")
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
    const auto koef = mashtab(bins);
    svg_text(TEXT_LEFT, TEXT_LEFT, to_string(bins[0]));
    double top = 0;
    for (size_t bin : bins)
    {
        const double bin_width = 10 * bin * koef;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT);
        top += BIN_HEIGHT;
    }
    svg_end();
}
