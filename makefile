.PHONY: clean build run

build: clean
	@echo -e "Compiling"
	clang++ -lraylib src/*.cpp

run: build
	@echo -e "Running"
	@./a.out

clean:
	@echo -e "Cleaning"
	@rm -f a.out

