template <ll mod>
struct ModInt
{
    const static ll MD = mod;
    ll x;

    ModInt(ll x = 0) : x(x % MD) {}

    int get() { return x; }

    ModInt operator+(const ModInt &that) const
    {
        ll x0 = x + that.x;
        return ModInt(x0 < MD ? x0 : x0 - MD);
    }

    ModInt operator-(const ModInt &that) const
    {
        ll x0 = x - that.x;
        return ModInt(x0 < MD ? x0 + MD : x0);
    }

    ModInt operator*(const ModInt &that) const { return ModInt((ll)x * that.x % MD); }

    ModInt operator/(const ModInt &that) const { return *this * that.inverse(); }

    ModInt operator+=(const ModInt &that)
    {
        x += that.x;
        if (x >= MD)
            x -= MD;
        return ModInt<mod>(x);
    }

    ModInt operator-=(const ModInt &that)
    {
        x -= that.x;
        if (x < 0)
            x += MD;
        return ModInt<mod>(x);
    }

    ModInt operator*=(const ModInt &that)
    {
        x = (ll)x * that.x % MD;
        return ModInt<mod>(x);
    }

    ModInt operator/=(const ModInt &that)
    {
        *this = *this / that;
        return ModInt<mod>(x);
    }

    ModInt inverse() const
    {
        ll a = x, b = MD, u = 1, v = 0;
        while (b)
        {
            int t = a / b;
            a -= t * b;
            std::swap(a, b);
            u -= t * v;
            std::swap(u, v);
        }
        if (u < 0)
            u += MD;
        return u;
    }
};