.PHONY: all
all: build install sdist wheel

.PHONY: build
build:
	python3 setup.py build

.PHONY: install
install:
	python3 setup.py install

.PHONY: sdist
sdist:
	python3 setup.py sdist

.PHONY: wheel
wheel:
	pip3 install wheel
	python3 setup.py bdist_wheel
