.PHONY: libmx uninstall reinstall

PROJECT_NAME = libmx.a
SRC = $(wildcard src/*.c)
INC = $(wildcard inc/*.c)

libmx:
	@clang -c ${INC} ${SRC}
	@mkdir obj
	@mv *.o obj
	@ar -rc $(PROJECT_NAME) obj/*.o
	@ranlib $(PROJECT_NAME)
	@rm -r obj/

uninstall:
	@rm -r obj/
	@rm $(PROJECT_NAME)

reinstall: uninstall libmx
