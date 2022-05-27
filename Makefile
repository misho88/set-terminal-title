SRC=set-terminal-title.c
EXE=set-terminal-title

all: $(EXE)

$(EXE): $(SRC)
	gcc -Wall -Wextra $< -o $@

clean:
	rm -f $(EXE)

install: $(EXE)
	install -d $(DESTDIR)/usr/local/bin
	install $(EXE) $(DESTDIR)/usr/local/bin

uninstall:
	rm -f $(DESTDIR)/usr/local/bin/$(EXE)
