vector < vector<int> > g; // граф
int n; // число вершин

vector<int> color; // цвет вершины (0, 1, или 2)

vector<int> time_in, time_out; // "времена" захода и выхода из вершины
int dfs_timer = 0; // "таймер" для определения времён

void dfs (int v) {
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (vector<int>::iterator i=g[v].begin(); i!=g[v].end(); ++i)
    if (color[*i] == 0)
    dfs (*i);
    color[v] = 2;
    time_out[v] = dfs_timer++;
}

//////////////////////////////////////////////////////////////////////////////////////////

vector < vector<int> > g; // граф
int n; // число вершин

vector<char> used;

void dfs (int v) {
	used[v] = true;
	for (vector<int>::iterator i=g[v].begin(); i!=g[v].end(); ++i)
		if (!used[*i])
			dfs (*i);
}