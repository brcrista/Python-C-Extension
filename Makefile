.PHONY: all
all: spammodule

.PHONY: spammodule
spammodule:
	python3 setup.py build
