all: hexchat xchat
hexchat: link-hexchat
link-hexchat: hexchatobj xmpobj
	g++ -o main-hexchat main-hexchat.o xmp.o
hexchatobj:
	g++ -c main-hexchat.cpp -o main-hexchat.o
xmpobj:
	gcc -c xmp.h -o xmp.o

