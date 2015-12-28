# Question
How would you test the word count program?
What kinds of input are most likely to uncover bugs if there are any?

# Answer
Notice the source code of the word count program is avaliable for me, I would
do the so-called white box test. Build series of tests what are cover all the
of the program.

* Test0: the empty input
```
$echo -ne "" | ./wc
0 0 0
$
```

* Test1: one character
```
$echo -ne "a" | ./wc
0 1 1
$
```

* Test2: one word
```
$echo -ne "word" | ./wc
0 1 4
$
```

* Test3: one blank
```
$echo -ne " " | ./wc
0 0 1
$
```

* Test4: one newline
```
$echo -ne "\n" | ./wc
1 0 1
$
```

* Test5: one tab
```
$echo -ne "\t" | ./wc
0 0 1
$
```

* Test6: one blank before a word
```
$echo -ne " word" | ./wc
0 1 5
$
```

* Test7: one newline after a word
```
$echo -ne "word\n" | ./wc
1 1 5
$
```

* Test6: one tab between two words
```
$echo -ne "two\twords" | ./wc
0 2 9
$
```

* Test8: one underscore between two words
```
$echo -ne "two_words" | ./wc
0 1 9
$
```

* Test9: number before a word
```
$echo -ne "7heaven" | ./wc
0 1 7
$
```

* Test10: mix
```
$echo -ne "I\n can     eat\tglass,it doesn't\nhurt me." | ./wc
2 7 40
$
```

* Test11: redirect input from a file and compare with GNU wc
```
$./wc < answer.md
101 286 1286
$wc < answer.md
 101  286 1286
$
```
