const int p = 31;
long long hash = 0, p_pow = 1;
for (size_t i=0; i<s.length(); ++i)
{
	// желательно отнимать 'a' от кода буквы
	// единицу прибавляем, чтобы у строки вида 'aaaaa' хэш был ненулевой
	hash += (s[i] - 'a' + 1) * p_pow;
	p_pow *= p;
}

// ############################################################

string s;  int i1, i2, len; // входные данные

// считаем все степени p
const int p = 31;
vector<long long> p_pow (s.length());
p_pow[0] = 1;
for (size_t i=1; i<p_pow.size(); ++i)
	p_pow[i] = p_pow[i-1] * p;

// считаем хэши от всех префиксов
vector<long long> h (s.length());
for (size_t i=0; i<s.length(); ++i)
{
	h[i] = (s[i] - 'a' + 1) * p_pow[i];
	if (i)  h[i] += h[i-1];
}

// получаем хэши двух подстрок
long long h1 = h[i1+len-1];
if (i1)  h1 -= h[i1-1];
long long h2 = h[i2+len-1];
if (i2)  h2 -= h[i2-1];

// сравниваем их
if (i1 < i2 && h1 * p_pow[i2-i1] == h2 ||
	i1 > i2 && h1 == h2 * p_pow[i1-i2])
	cout << "equal";
else
	cout << "different";

// ############################################################