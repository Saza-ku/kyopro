# 6 ☆5
解説AC  
辞書順最小は貪欲法 ← これはわかった  
貪欲法の前計算による高速化 ← これがわからんかった

![解説](https://pbs.twimg.com/media/EyPpXzoVIAMkP9e?format=jpg&name=large)
https://twitter.com/e869120/status/1379202843622576130?s=21

# 7 ☆3
流石に解けた
![解説](https://pbs.twimg.com/media/EyUzOFjU4AAvIcw?format=jpg&name=large)

# 8 ☆4
解けた  
普通に DP  
![解説](https://pbs.twimg.com/media/EyZ8W4aUcAIOVr4?format=jpg&name=medium)

# 10 ☆2
懐かしの累積和  
やるだけ

# 13 ☆5
両端からの最短距離 → 2 回ダイクストラ 
![解説](https://pbs.twimg.com/media/Ey41_9eVkAIC8lU?format=jpg&name=large)

# 24 ☆2
やるだけ  
偶数か奇数か = 偶奇性 = パリティ

# 27 ☆2
set 使うだけ

# 30 ☆5
自力AC  
通ると思わなかったー  
素数の逆数和は loglogN っていうのは覚えておく

![解説](https://pbs.twimg.com/media/E0f1L0SUcAMtbcF?format=jpg&name=large)

# 34 ☆4
尺取り法  。
要素の重複を考えないといけないので set ではなく map を使う。  
要素の重複数が 0 になったときは erase する。

# 38 ☆3
解説AC  
`a * b` のオーバーフローは、`a > LLONG_MAX / b` で OK  
`1e18` とかいう書き方は、値が `double` で返ってくるので、`ll` にキャストしてから使うこと  
python は多長倍整数だから `a * b` で OK  
ただし、`int * int -> int` の割り算は `//` だから注意  

# 46
同じ意味のものをまとめて考える

# 48 ☆3
もうちょい考察すれば `priority_queue` 使わなくても `sort` するだけでよかったらしい

# 50 ☆3
一次元 DP やるだけ

# 61 ☆2
deque は要素のランダムアクセスが定数倍でできる。  
stack や queue は基本的に deque を使った方がいいらしい。（[参考](https://qiita.com/h_hiro_/items/a83a8fd2391d4a3f0e1c#adapter)）

# 64 ☆3
解説 AC  
imos 法しか思いつかなかった
![解説](https://github.com/E869120/kyopro_educational_90/blob/main/editorial/064.jpg)

# 75 ☆3
なんか一回 TLE 出した。  
困ったらとりあえず int を ll に変えといたらええねん。
