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

# 38 ☆3
解説AC  
`a * b` のオーバーフローは、`a > LLONG_MAX / b` で OK  
`1e18` とかいう書き方は、値が `double` で返ってくるので、`ll` にキャストしてから使うこと  
python は多長倍整数だから `a * b` で OK  
ただし、`int * int -> int` の割り算は `//` だから注意  

# 48 ☆3
もうちょい考察すれば `priority_queue` 使わなくても `sort` するだけでよかったらしい

