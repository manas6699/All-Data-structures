template <typename T, typename V>

class pairc
{
    T x;
    V y;

public:
    void set_x(T x)
    {
        this->x = x;
    }

    T get_x()
    {
        return x;
    }
    void set_y(V y)
    {
        this->y = y;
    }

    V get_y()
    {
        return y;
    }
};
