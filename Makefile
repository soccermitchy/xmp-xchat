all: clean hexchat xchat
hexchat: link-hexchat
link-hexchat: hexchatobj
	g++ -o main-hexchat main-hexchat.o /usr/local/lib/libxmp.so.4
hexchatobj:
	g++ -c main-hexchat.cpp -o main-hexchat.o
xchat:
clean:
	rm -rf *.o main-hexchat
