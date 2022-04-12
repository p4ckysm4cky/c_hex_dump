# C_hex_dump



## About

A command line program that is able to view contents of binary files in hexadecimal format ([Hex dump](https://en.wikipedia.org/wiki/Hex_dump)).



## Build

Navigate to the `/src` folder and either run

```sh
make
```

or

```
gcc chd.c -o chd
```



## Example usage

```sh
$ ./chd ../example/test2.txt
54 68 65 20 71 75 69 63 6B 20 62 72 6F 77 6E 20  | The quick brown  
66 6F 78 20 6A 75 6D 70 73 20 6F 76 65 72 20 74  | fox jumps over t 
68 65 20 6C 61 7A 79 20 64 6F 67 73              | he lazy dogser t.
```

