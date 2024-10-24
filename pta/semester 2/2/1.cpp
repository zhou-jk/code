#include <iostream>
#include <cstdio>
#include <vector>
#include <stdexcept>

template <typename T>
class Set
{
private:
    std::vector<T> value;

public:
    Set() {}

    ~Set()
    {
        value.clear();
    }

    Set(const std::vector<T> &_value) : value(_value) {}

    size_t size() const
    {
        return value.size();
    }

    T &operator[](const size_t &x)
    {
        if ((int)x >= (int)value.size())
        {
            throw std::runtime_error("Array out of bounds");
        }
        return value[x];
    }
    const T operator[](const size_t &x) const
    {
        if ((int)x >= (int)value.size())
        {
            throw std::runtime_error("Array out of bounds");
        }
        return value[x];
    }

    bool insert(const T &x)
    {
        if (value.empty() || x < *value.begin())
        {
            value.insert(value.begin(), x);
            return true;
        }
        for (auto it = value.begin(); it != value.end(); ++it)
        {
            if (*it == x)
            {
                return false;
            }
            auto nit = next(it);
            if (nit == value.end() || x < *nit)
            {
                value.insert(nit, x);
                return true;
            }
        }
        return false;
    }

    bool exist(const int &x) const
    {
        for (auto it : value)
            if (*it == x)
                return true;
        return false;
    }

    friend Set<T> intersection_of_set(const Set<T> &x, const Set<T> &y)
    {
        int i = 0, j = 0;
        std::vector<T> s;
        while (i < (int)x.size() && j < (int)y.size())
        {
            if (x[i] < y[j])
            {
                i++;
            }
            else if (x[i] > y[j])
            {
                j++;
            }
            else
            {
                s.push_back(x[i]);
                i++;
                j++;
            }
        }
        return Set(s);
    }

    friend Set<T> union_of_set(const Set<T> &x, const Set<T> &y)
    {
        int i = 0, j = 0;
        std::vector<T> s;
        while (i < (int)x.size() && j < (int)y.size())
        {
            if (x[i] < y[j])
            {
                s.push_back(x[i]);
                i++;
            }
            else if (x[i] > y[j])
            {
                s.push_back(y[j]);
                j++;
            }
            else
            {
                s.push_back(x[i]);
                i++;
                j++;
            }
        }
        while (i < (int)x.size())
        {
            s.push_back(x[i]);
            i++;
        }
        while (j < (int)y.size())
        {
            s.push_back(y[j]);
            j++;
        }
        return Set(s);
    }
};

int main()
{
    int n, m;
    Set<int> a, b;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        std::cin >> x;
        b.insert(x);
    }
    Set<int> c = union_of_set(a, b), d = intersection_of_set(a, b);
    std::cout << "{";
    for (int i = 0; i < (int)c.size(); i++)
    {
        if (i > 0)
        {
            std::cout << ",";
        }
        std::cout << c[i];
    }
    std::cout << "}\n";
    std::cout << "{";
    for (int i = 0; i < (int)d.size(); i++)
    {
        if (i > 0)
        {
            std::cout << ",";
        }
        std::cout << d[i];
    }
    std::cout << "}\n";
    return 0;
}