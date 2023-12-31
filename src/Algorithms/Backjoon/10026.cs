using StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
using StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));

(int, int)[] directions  = { (0, 1), (-1, 0), (0, -1), (1, 0) };

var N = Convert.ToInt32(sr.ReadLine()!);
string[] picture = new string[N];

for (int i = 0; i < N; ++i)
    picture[i] = sr.ReadLine()!;

bool[,] visited1 = new bool[N,N];
int cnt1 = 0;
for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
        if (!visited1[x, y]) {
            ++cnt1;
            Queue<(int, int)> Q = new();
            Q.Enqueue((x, y));
            visited1[x, y] = true;

            while (Q.TryDequeue(out var cur)) {
                foreach(var next in directions) {
                    var (nextX, nextY) = (next.Item1 + cur.Item1, next.Item2 + cur.Item2);

                    if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
                        continue;
                    if (picture[cur.Item1][cur.Item2] != picture[nextX][nextY]
                        || visited1[nextX, nextY])
                        continue;
                    
                    Q.Enqueue((nextX, nextY));
                    visited1[nextX, nextY] = true;
                }
            }
        }
    }
}

bool[,] visited2 = new bool[N,N];
int cnt2 = 0;
for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
        if (!visited2[x, y]) {
            ++cnt2;
            Queue<(int, int)> Q = new();
            Q.Enqueue((x, y));
            visited2[x, y] = true;

            while (Q.TryDequeue(out var cur)) {
                foreach(var next in directions) {
                    var (nextX, nextY) = (next.Item1 + cur.Item1, next.Item2 + cur.Item2);

                    if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
                        continue;
                    if (visited2[nextX, nextY]
                        || (picture[cur.Item1][cur.Item2] != picture[nextX][nextY]
                        && !(picture[cur.Item1][cur.Item2] == 'R' && picture[nextX][nextY] == 'G')
                        && !(picture[cur.Item1][cur.Item2] == 'G' && picture[nextX][nextY] == 'R')))
                        continue;
                    
                    Q.Enqueue((nextX, nextY));
                    visited2[nextX, nextY] = true;
                }
            }
        }
    }
}

sw.WriteLine($"{cnt1} {cnt2}");