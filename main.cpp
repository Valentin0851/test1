#include "C:\Users\hr5\Desktop\C++\OOP.cpp"

using namespace std;

typedef long long ll;


const int INF = (int)(1e9 + 7);

vector<pair<int, int>> graph[100000];
int pr[100000];


int n;
int a[100000];     //массив
int tree[400004];  //дерево отрезков. в вершинах хранятся минимумы

struct node
{
    int left, right, min, max;
    node* child_left, * child_right;
};


node* build(int left, int right, vector<int>& values)
{
    if (left > right)
        return 0;
    node* res = new node;
    res->left = left;
    res->right = right;
    if (right == left)
    {
        res->child_left = res->child_right = 0;
        res->min = values[left];
        res->max = values[left];
    }
    else
    {
        int mid = (left + right) / 2;
        res->child_left = build(left, mid, values);
        res->child_right = build(mid + 1, right, values);
        res->min = min(res->child_left->min, res->child_right->min);
        res->max = max(res->child_left->max, res->child_right->max);
    }
    return res;
}
int query_min(node* root, int left, int right)
{
    if (right < root->left || left > root->right)
        return INF;
    if (left <= root->left && right >= root->right)
        return root->min;
    int ans1 = query_min(root->child_left, left, right);
    int ans2 = query_min(root->child_right, left, right);
    return min(ans1, ans2);
}
int query_max(node* root, int left, int right)
{
    if (right < root->left || left > root->right)
        return -INF;
    if (left <= root->left && right >= root->right)
        return root->max;
    int ans1 = query_max(root->child_left, left, right);
    int ans2 = query_max(root->child_right, left, right);
    return max(ans1, ans2);
}
int query(node* root, int left, int right)
{
    return query_max(root, left, right) - query_min(root, left, right);
}


vector<bool> used;
vector<vector<int>> gr;





vector<int> prefix_func(string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}
vector<int> z_func(string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}



struct Node {
    int cnt;
    int go[26];

    Node() {
        cnt = 0;
        for (int i = 0; i < 26; ++i) {
            go[i] = -1;
        }
    }
};

vector<Node> trie;


void addString(const string& s) {
    int v = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (trie[v].go[s[i] - 'a'] == -1) {
            trie.emplace_back();
            trie[v].go[s[i] - 'a'] = (int)trie.size() - 1;
        }
        v = trie[v].go[s[i] - 'a'];
    }
    ++trie[v].cnt;
}


bool exist(const string& s) {
    int v = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (trie[v].go[s[i] - 'a'] == -1) {
            return false;
        }
        v = trie[v].go[s[i] - 'a'];
    }
    return trie[v].cnt > 0;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second < b.second) {
        return true;
    }
    return false;
}

void dfs(int v) {
    used[v] = true;
    for (auto u : gr[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}
inline ll sub_pref(int i, int j, vector<int> a) {
    return a[j - 1] - a[i];
}

int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a %= b;
        }
        else
        {
            b %= a;
        }
    }
    return a + b;
}

inline int lcm(int a, int b)
{
    return abs(a * b) / gcd(a, b);
}

bool in_space1(int x, int y)
{
    bool b1, b2, b3;
    b1 = b2 = b3 = false;

    b1 = y > -x;
    b2 = y > (2 * x + 2);
    b3 = (x + 1) * (x + 1) + (y - 1) * (y - 1) < 4;

    return b1 && b2 && b3;
}

bool in_space2(int x, int y)
{
    bool b1, b2, b3;
    b1 = b2 = b3 = false;

    b1 = y < -x;
    b2 = y < (2 * x + 2);
    b3 = (x + 1) * (x + 1) + (y - 1) * (y - 1) > 4;

    return b1 && b2 && b3;
}

inline double diskr(int a, int b, int c)
{
    return sqrt(b * b - 4 * a * c);
}


int cnt_roots(int a, int b, int c)
{
    int ans = 0;
    if (b * b >= 4 * a * c)
    {
        if (b * b == 4 * a * c)
        {
            ans = 1;
        }
        else
        {
            ans = 2;
        }
    }
    return ans;
}

void root(int a, double b, int c)
{
    double x1, x2;
    double d = diskr(a, b, c);
    x1 = (-b - d) / (2 * a);
    x2 = (-b + d) / (2 * a);
    if (cnt_roots(a, b, c) > 0)
    {
        if (cnt_roots(a, b, c) == 1)
        {
            cout << x1 << endl;
        }
        else
        {
            cout << x1 << endl;
            cout << x2 << endl;
        }
    }
    else
    {
        cout << "No roots";
    }

}

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int numdigits(int x)
{
    int count = 0;
    while (x != 0)
    {
        x = x / 10;
        ++count;
    }
    return count;
}

void PascalsTriangle(int n)
{
    int x, y, maxlen;
    string len;
    for (int i = 0; i < n; i++)
    {
        x = 1;
        len = string((n - i - 1) * (n / 2), ' ');
        cout << len;
        for (int j = 0; j <= i; j++)
        {
            y = x;
            x = x * (i - j) / (j + 1);
            maxlen = numdigits(x) - 1;
            if (n % 2 == 0)
                cout << y << string(n - 1 - maxlen, ' ');
            else
            {
                cout << y << string(n - 2 - maxlen, ' ');
            }
        }
        cout << endl;
    }
}

void nod(int a, int b, int* r)
{
    if (a == b)
    {
        *r = a;
    }
    else
    {
        if (a > b)
        {
            nod(a - b, b, r);
        }
        else
        {
            nod(a, b - a, r);
        }
    }
}

struct Student
{
    char name[20];
    char surname[30];
    int old;
    int weight;
};

struct data
{
    int year;
    int month;
    int day;
};

struct record
{
    char fam[22];
    struct data birthday;
};

union study
{
    int course;
    char direction[20];
    char kaf[20];
};

struct BookSates
{
    std::string titles;
    std::vector<std::string> authors;
    std::vector<std::string> tags;
    unsigned int PageCount = 0;
    unsigned int PublishingYear = 0;
};


class ThreadWorker
{
private:
    enum class State
    {
        NotStarted,
        Working,
        Shutdown
    };

};

// функция удаления лишних пробелов
char* strdel(const char* source, char* result)
{
    char* ptr;
    result = (char*)source;
    while ((ptr = strstr(result, "  ")) != nullptr)
    {
        ptr = (ptr + 1);
    }
    return result;
}

// структура массива
struct mas
{
    int n;
    int a[10] = { 1, 2, 3, 4, 5,6, 7, 8, 9, 10 };
    int s;
};

void summa(struct mas &x)
{
    int s = 0;
    for (int i = 0; i < x.n; ++i)
    {
        s += x.a[i];
    }
    x.s = s;
}

void perest(int n, int m, const char* r, char *pole)
{
    if (n > m)
    {
        for (int i = 0; i < m; ++i)
        {
            cout << pole[i];
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < m - n + 1; ++i)
        {
            pole[n - 1] = r[i];
            int k = 0;
            char *r1;
            r1 = new char[m];
            for (int j = 0; j < m - n + 1; ++j)
            {
                r1[k++] = r[j];
            }
            perest(n + 1, m, r1, pole);
        }
    }
}


inline int ad(int n, int m) { return n + m; }

void table(float(*ptr)(float), float a, float b, int n, float* masX, float* masY)
{
    float h = (b - a) / (n - 1);
    float x = a;
    for (int i = 0; i < n; ++i)
    {
        masX[i] = x;
        masY[i] = ptr(x);
        x += h;
    }
}

//
struct element1
{
    char name[16];
    char telef[7];
    element1* p;//
};

class st
{
private:
    int mark;
    int course;
    std::string name;
    std::string surname;
    int age;
public:
    st() : mark(3), course(1), name(""), surname("") {}
    st(int mark, int course) :mark(mark), course(course) {}
};

class Counter
{
private:
    unsigned int num;
public:
    Counter() :num(0) {}
    unsigned int get_counter()
    {
        return num;
    }
    void operator++()
    {
        ++num;
    }
};



struct element2
{
    char name[16];
    char telef[7];
    element2* prev;
    element2* next;
};

struct elem
{
    int num;
    elem* p;
};

void print(const int a[], int n, int m)
{
    for (int i = 0; i < n * m; ++i)
    {
        if ((i) % m == 0)
            std::cout << std::endl;
        std::cout << *(a + i) << ' ';
    }

}


void print()
{
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    int f = -1;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
        {
            f *= -1;
        }
        if (f > 0)
        {
            ans += a[i];
        }
    }
    std::cout << ans;
}


int main(int args, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    setlocale(LC_ALL, "ru");

    /*ofstream fout;
    fout.open("C:\\Users\\hr5\\Desktop\\text.txt");
    fout << "working with files\n";
    fout.close();

    char line[100];
    ifstream fin;
    fin.open("C:\\Users\\hr5\\Desktop\\text.txt");
    fin.getline(line, 100);
    fout.open("C:\\Users\\hr5\\Desktop\\text.txt", ios::app);
    fout << line << endl;
    fout.close();
    fin.close();*/

    int n, m;
    int a[1000];
    cin >> n >> m;
    for (int i = 0; i < n*m; ++i)
    {
        cin >> a[i];
    }

    print(a, n, m);

    //int n, r, a, b;
    //cin >> n;
    //int m = 10;
    //mas z;
    //z.n = n;
    //summa(z);
    //cout << z.s;
    //nod(a, b, &r);

    //elem* first, * nn, * ff, * qq;
    //first = NULL;
    //first = new elem;
    //first->num = 5;
    //first->p = NULL;

    //qq = new elem;
    //qq->num = 4;

    //qq = first;
    //first = first->p;
    //delete qq;



    //char v[] = "ABC";
    //char pole[3];
    //perest(1, 3, v, pole);

    //int (*ptr)(int, int);
    //ptr = ad;
    //int c = ptr(n, m);


    //int* list;
    //list = new int[n];
    //*list = -244;
    //*(list + 1) = 15;
    //*(list + 2) = 10;

    ///*for (int i = 0; i<n;++i)
    //{
    //    cout << *(list + i);
    //}*/

    //int** h = new int* [n];
    //for (int i = 0; i < n; ++i)
    //{
    //    h[i] = new int[n];
    //}

    //for (int i = 0; i < n; ++i)
    //{
    //    delete[] h[i];
    //}
    //delete[] h;

    //char* ptrstr;
    //ptrstr = new char[10];
    //delete[] ptrstr;

    //char* mn[4];//массив указателей на строки 
    //char ms[4][7];// массив строк указанной длинны

    //record basa[40];
    //char name[22];
    //bool key;
    ///*for (int i = 0; i < n; ++i)
    //{
    //    cin >> basa[i].fam;
    //    cin >> basa[i].birthday.day;
    //    cin >> basa[i].birthday.month;
    //    cin >> basa[i].birthday.year;
    //}*/



    //

    return 0;
}