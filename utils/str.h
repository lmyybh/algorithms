#include <vector>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
string vectorToString(vector<T> &v)
{
    ostringstream os;
    os << "[";
    for (auto it = v.cbegin(); it != v.cend(); ++it)
    {
        os << *it;
        if (it != v.cend() - 1)
            os << ", ";
    }
    os << "]";

    return os.str();
}