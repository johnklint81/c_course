.PHONY : all

all : 111 112 113 121 122 131 134 135 136 137 143 \
      144 153 154 155 156 157 158 159 1510 1511 \
      161 162 211 212 lib1 lib2 421

111 : 111.c
	gcc -o 111 111.c
112 : 112.c
	gcc -o 112 112.c
113 : 113.c
	gcc -o 113 113.c -lncurses
121 : 121.c
	gcc -o 121 121.c
122 : 122.c
	gcc -o 122 122.c
131 : 131.c
	gcc -o 131 131.c
134 : 134.c
	gcc -o 134 134.c
135 : 135.c
	gcc -o 135 135.c -lm
136 : 136.c
	gcc -o 136 136.c -lm
137 : 137.c
	gcc -o 137 137.c
143 : 143.c
	gcc -o 143 143.c
144 : 144.c
	gcc -o 144 144.c
153 : 153.c
	gcc -o 153 153.c
154 : 154.c
	gcc -o 154 154.c
155 : 155.c
	gcc -o 155 155.c
156 : 156.c
	gcc -o 156 156.c
157 : 157.c
	gcc -o 157 157.c
158 : 158.c
	gcc -o 158 158.c
159 : 159.c
	gcc -o 159 159.c
1510 : 1510.c
	gcc -o 1510 1510.c
1511 : 1511.c
	gcc -o 1511 1511.c
161 : 161.c
	gcc -o 161 161.c
162 : 162.c
	gcc -o 162 162.c
211 : 211.c
	gcc -o 211 211.c
212 : 212.c
	gcc -o 212 212.c
# -fPIC generates position independent code, necessary for shared libraries
# -shared tells the compiler to create a shared library
lib1 : lib1.c lib1.h
	@echo "Compiling lib1 from lib1.c"
	gcc -fPIC -shared -o lib1.so lib1.c
lib2 : lib2.c lib2.h
	@echo "Compiling lib2 from lib2.c"
	gcc -fPIC -shared -o lib2.so lib2.c
# -L. tells compiler to look for libraries in the current directory
421 : 421.c
	gcc -o 421 421.c -L. -l1 -l2
