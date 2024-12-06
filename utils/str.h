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

template <typename T>
string Vector2dToString(vector<vector<T>> &vec)
{
    ostringstream os;
    os << "[";
    for (auto it = vec.cbegin(); it != vec.cend(); ++it)
    {
        os << "[";
        for (auto cb = (*it).cbegin(); cb != (*it).cend(); ++cb)
        {
            os << *cb;
            if (cb != (*it).cend() - 1)
                os << ", ";
        }
        os << "]";
        if (it != vec.cend() - 1)
            os << ", ";
    }
    os << "]";

    return os.str();
}

template <typename T>
void sortVector2d(vector<vector<T>> &vec)
{
    for (auto &v : vec)
    {
        sort(v.begin(), v.end());
    }
    sort(vec.begin(), vec.end());
}