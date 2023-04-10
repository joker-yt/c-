class TryInline
{
public:
    inline TryInline() {}

    // automatically inlined because of declaration and definition at the same time.
    int ret_n()
    {
        return n_;
    }

    // not inlined
    int ret_n2();

    // inlined according to explicit inline keyword.
    inline int ret_n3();

private:
    int n_ = 10;
};

int TryInline::ret_n2()
{
    return n_;
}

int TryInline::ret_n3()
{
    return n_;
}