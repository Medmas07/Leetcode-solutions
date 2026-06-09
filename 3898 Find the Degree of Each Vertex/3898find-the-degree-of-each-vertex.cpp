#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


// ---------------------------------------------------------
// 1. MEMORY HIJACKING (Speeds up LeetCode's hidden driver code)
// ---------------------------------------------------------
static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024]; // 64 MB static buffer
static size_t pos = 0;

void* operator new(const size_t size) {
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void*>(&BUFFER[pos - size]);
}

void* operator new[](const size_t size) { return operator new(size); }
// Disable deallocation entirely to save CPU cycles
void operator delete(void*) noexcept {}
void operator delete[](void*) noexcept {}
void operator delete(void*, size_t) noexcept {}
void operator delete[](void*, size_t) noexcept {}

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>  // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>  // for less
using namespace std;
using namespace __gnu_pbds;
// define ordered set
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

// Define ordered multiset
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

#define pb push_back
#define setbits __builtin_popcountll
#define clz __builtin_clzll
// clz -> count leading zeros 00000100 clz(4) = 5
#define ctz __builtin_ctzll
// ctz -> count trailing zeros 00000100 ctz(4) = 2
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define reverse(x) (reverse(all(x)))
#define rep(i, a, n) for (int i = a; i < (n); ++i)
#define repo(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define sum(a) (accumulate((a).begin(), (a).end(), 0ll))
#define sorted(a) (sort((a).begin(), (a).end()))
#define countx(v, x) (count(all(v), x))
#define minel(a) (*min_element((a).begin(), (a).end()))
#define maxel(a) (*max_element((a).begin(), (a).end()))
#define maxidx(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define minidx(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define lb(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define ub(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define min_heap priority_queue<int, vector<int>, greater<int>>
#define max_heap priority_queue<int>
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
const int mod = 1e9 + 7;

#define ll long long

/*--------------------Printing Templates --------------------------------------------------------*/
template <typename T>
T floor(T a, T b) {
    return a / b - (a % b && (a ^ b) < 0);
}
template <typename T>
T ceil(T x, T y) {
    return floor(x + y - 1, y);
}

// print any int/string
template <typename T>
void print(const T& t) {
    cout << t << '\n';
}
// print multiple int/strings
template <typename T, typename... Args>
void print(const T& first_parameter, const Args&... second_paramter) {
    cout << first_parameter << ' ';
    if (sizeof...(second_paramter)) print(second_paramter...);
}
// print vector
template <typename T>
void print(const vector<T>& vec) {
    for (const auto& value : vec) {
        cout << value << ' ';
    }
    cout << '\n';
}
// print map
template <typename t1, typename t2>
void print(const map<t1, t2>& mp) {
    for (const auto& [x, y] : mp) {
        cout << x << " " << y << '\n';
    }
}
// print set
template <typename T>
void print(const set<T>& s) {
    for (const auto& value : s) {
        cout << value << ' ';
    }
    cout << '\n';
}
// print multiset
template <typename T>
void print(const multiset<T>& s) {
    for (const auto& value : s) {
        cout << value << ' ';
    }
    cout << '\n';
}
// print pair
template <typename T1, typename T2>
void print(const pair<T1, T2>& p) {
    cout << p.first << ' ' << p.second << '\n';
}

/*----------------------------------------------------------------------------------------------*/

string to_binary(int64_t n) {
    string res = "";
    while (n > 0) {
        res += (n % 2 == 0 ? '0' : '1');
        n /= 2;
    }
    reverse(res);
    return res;
}
// Binary exponentiation with mod
int bin_pow(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int power(int a, int b) {  // binary exponentiaion
    int ans = 1;
    while (b) {
        if (b & 1)
            ans *= a;
        a *= a;
        b = b >> 1;  // b/=2
    }
    return ans;
}
// a^-1 mod m = a^(m-2) mod m
int modinv(int a) { return bin_pow(a, mod - 2); }

int modadd(int a, int b) {
    a = (a % mod + mod) % mod;
    b = (b % mod + mod) % mod;
    return (a + b) % mod;
}
int modsub(int a, int b) {
    a = (a % mod + mod) % mod;
    b = (b % mod + mod) % mod;
    return (a - b + mod) % mod;
}
int modmul(int a, int b) {
    a = (a % mod + mod) % mod;
    b = (b % mod + mod) % mod;
    return (a * b) % mod;
}
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

/*----------------------------Binary Search Functions ------------------------------------------------------------------*/

int gteq_count(vector<int>& arr, int x) {
    int n = arr.size();
    int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    return n - pos;
}
int gt_count(vector<int>& arr, int x) {
    int n = arr.size();
    int pos = upper_bound(arr.begin(), arr.end(), x) - arr.begin();  // first index of element > x
    return n - pos;
}
int lteq_count(vector<int>& arr, int x) {
    int pos = upper_bound(arr.begin(), arr.end(), x) - arr.begin();  // first index of element > x
    return pos;
}
int lt_count(vector<int>& arr, int x) {
    int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    return pos;
}

/*----------------------------------------------------------------------------------------------*/

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> d(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    d[i]++;
                }
            }
        }
        return d;
    }
};

/*----------------------------------------------------------------------------------------------*/

#ifdef LOCAL

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example local testing for some function:
    Solution sol;
    // vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // cout << sol.maxSubArray(nums) << "\n";


            }
#endif

// compile and run : g++ -DLOCAL Leetcode.cpp -o Leetcode && ./Leetcode