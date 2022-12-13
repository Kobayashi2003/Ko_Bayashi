# 结合使用 find xargs grep locate

```bash
kobayashi@Computer:~$ find ./ -name '*.md' | xargs grep string -n -C5 --color 2>/dev/null  
```

```bash
kobayashi@Computer:~$ locate -i string | xargs grep string -n -C5 --color 2>/dev/null  
```
