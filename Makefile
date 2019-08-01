.PHONY: all
all: build install sdist

.PHONY: build
build:
	python3 setup.py build

.PHONY: install
install:
	python3 setup.py install

.PHONY: sdist
sdist:
	python3 setup.py sdist
