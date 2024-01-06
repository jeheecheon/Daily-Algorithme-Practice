using StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
using StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));

(int, int)[] directions = { (0, 1), (0, -1), (1, 0), (-1, 0) };

int T = Convert.ToInt32(sr.ReadLine());

while (T-- > 0) {
    int[] input = sr.ReadLine()!.Split().Select(int.Parse).ToArray();
    int R = input[1], C = input[0];
    char[,] board = new char[R, C];

    Queue<(int, int)> fireQ = new(), personQ = new();
    int[,] fireDist = new int[R, C], personDist = new int[R, C];
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            board[r, c] = Convert.ToChar(sr.Read()!);
            if (board[r, c] == '@') {
                personQ.Enqueue((r, c));
                personDist[r, c] = 1;
            }
            else if (board[r, c] == '*') {
                fireQ.Enqueue((r, c));
                fireDist[r, c] = 1;
            }
        }
        sr.ReadLine();
    }

    while (fireQ.TryDequeue(out var cur)) {
        foreach (var nextDir in directions) {
            var (nextR, nextC) = (cur.Item1 + nextDir.Item1, cur.Item2 + nextDir.Item2);

            if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C
                || fireDist[nextR, nextC] > 0
                || board[nextR, nextC] == '#')
                continue;
            
            fireQ.Enqueue((nextR, nextC));
            fireDist[nextR, nextC] = fireDist[cur.Item1, cur.Item2] + 1;
        }
    }

    int moveCnt = 0;
    while (moveCnt == 0 && personQ.TryDequeue(out var cur)) {
        foreach (var nextDir in directions) {
            var (nextR, nextC) = (cur.Item1 + nextDir.Item1, cur.Item2 + nextDir.Item2);

            if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) {
                moveCnt += personDist[cur.Item1, cur.Item2];
                break;
            }

            if (personDist[nextR, nextC] > 0
                || board[nextR, nextC] == '#')
                continue;
            if (fireDist[nextR, nextC] != 0 && personDist[cur.Item1, cur.Item2] + 1 >= fireDist[nextR, nextC])
                continue;

            personQ.Enqueue((nextR, nextC));
            personDist[nextR, nextC] = personDist[cur.Item1, cur.Item2] + 1;
        }
    }

    if (moveCnt == 0)
        sw.WriteLine("IMPOSSIBLE");
    else
        sw.WriteLine(moveCnt);
}