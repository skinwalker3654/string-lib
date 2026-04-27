source = example.c src/stringlib.c
cc = gcc
target = test

test: $(source)
	@echo "Compiling example.c ..."
	$(cc) $^ -o $(target)
	@echo "Executing example.c ..."
	./$(target)

install:
	@echo "Compiling source code ..."
	$(cc) -c src/stringlib.c
	@echo "Transporting it into a library ..."
	ar rcs libstringlib.a  stringlib.o
	@echo "Moving the library into your system ..."
	sudo cp header/stringlib.h /usr/local/include/
	sudo cp libstringlib.a /usr/local/lib/
	rm stringlib.o
	rm libstringlib.a

remove:
	@echo "Removing library ..."
	sudo rm /usr/local/include/stringlib.h
	sudo rm /usr/local/lib/libstringlib.a

clean:
	@echo "Removing compiled program ..."
	rm $(target)

.PHONY: test clean install
