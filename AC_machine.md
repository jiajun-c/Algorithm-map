# AC 自动机
[TOC]
## The usage
多模式匹配
what's this ?
多模式匹配指的是在一个字符串中寻找多个模式字符串的问题。

## The thought
主要使用的思想有KMP的思想，Trie树的思想
## 建图
建图的方式和我们的trie树的方式是一样的
```cpp
void insert(string s) {
    int now = 0;
    for (int i = 0;i < s.length();i++) {
        int num = s[i] - 'a';
        if(!tr[now][num]) tr[now][num] = ++cnt;
        now = tr[now][num];
    }
}
```

## 建立失配图
```cpp
void build() {
    queue<int>q;
    for (int i = 0;i < 26;i++) if(tr[0][i]) q.push(tr[0][i]);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0;i < 26;i++) {
            if(tr[u][j]) fail[tr[u][i]] =  tr[fail[u]][i],q.push(tr[u][j]);
            else tr[u][i] = tr[fail[u]][i];
        }
    }
}
```


