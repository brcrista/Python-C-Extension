.PHONY: all
all: build sdist

.PHONY: build
build:
	python3 setup.py build

.PHONY: sdist
sdist:
	python3 setup.py sdist
